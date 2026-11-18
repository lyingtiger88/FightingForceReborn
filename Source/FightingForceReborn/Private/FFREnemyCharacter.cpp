#include "FFREnemyCharacter.h"

#include "AIController.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

AFFREnemyCharacter::AFFREnemyCharacter()
{
    TeamId = 1;
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();

    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetCharacterMovement()->MaxWalkSpeed = 330.0f;
}

void AFFREnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        GetWorldTimerManager().SetTimer(
            ThinkTimer,
            this,
            &AFFREnemyCharacter::UpdateCombatBehavior,
            FMath::Max(0.1f, ThinkInterval),
            true,
            0.2f);
    }
}

AFFRCharacter* AFFREnemyCharacter::FindNearestPlayer() const
{
    AFFRCharacter* BestTarget = nullptr;
    float BestDistanceSquared = TNumericLimits<float>::Max();

    for (int32 PlayerIndex = 0; PlayerIndex < 2; ++PlayerIndex)
    {
        AFFRCharacter* Candidate = Cast<AFFRCharacter>(
            UGameplayStatics::GetPlayerCharacter(this, PlayerIndex));

        if (!Candidate || !Candidate->IsAlive() || Candidate->TeamId == TeamId)
        {
            continue;
        }

        const float DistanceSquared = FVector::DistSquared(
            GetActorLocation(), Candidate->GetActorLocation());

        if (DistanceSquared < BestDistanceSquared)
        {
            BestDistanceSquared = DistanceSquared;
            BestTarget = Candidate;
        }
    }

    return BestTarget;
}

void AFFREnemyCharacter::UpdateCombatBehavior()
{
    if (!IsAlive()) return;

    AAIController* AIController = Cast<AAIController>(GetController());
    AFFRCharacter* Target = FindNearestPlayer();

    if (!AIController || !Target)
    {
        if (AIController) AIController->StopMovement();
        return;
    }

    const float Distance = FVector::Distance(GetActorLocation(), Target->GetActorLocation());
    if (Distance > PreferredCombatDistance)
    {
        AIController->MoveToActor(Target, PreferredCombatDistance * 0.8f);
        return;
    }

    AIController->StopMovement();
    AIController->SetFocus(Target);

    const float CurrentTime = GetWorld()->GetTimeSeconds();
    if (CurrentTime >= NextAttackTime)
    {
        Target->ReceiveCombatDamage(AttackDamage, this);
        NextAttackTime = CurrentTime + FMath::Max(0.1f, AttackInterval);
    }
}
