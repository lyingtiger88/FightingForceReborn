#include "FFRPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "TimerManager.h"
#include "FFRCharacter.h"

AFFRPlayerCharacter::AFFRPlayerCharacter()
{
    TeamId = 0;
    GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    UCharacterMovementComponent* Movement = GetCharacterMovement();
    Movement->bOrientRotationToMovement = true;
    Movement->RotationRate = FRotator(0.0f, 620.0f, 0.0f);
    Movement->MaxWalkSpeed = 480.0f;
    Movement->BrakingDecelerationWalking = 1800.0f;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 360.0f;
    CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 70.0f));
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->bEnableCameraLag = true;
    CameraBoom->CameraLagSpeed = 10.0f;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
}

void AFFRPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AFFRPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFFRPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AFFRPlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AFFRPlayerCharacter::TurnCamera);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AFFRPlayerCharacter::LookCamera);
    PlayerInputComponent->BindAction(TEXT("LightAttack"), IE_Pressed, this, &AFFRPlayerCharacter::LightAttack);
    PlayerInputComponent->BindAction(TEXT("HeavyAttack"), IE_Pressed, this, &AFFRPlayerCharacter::HeavyAttack);
    PlayerInputComponent->BindAction(TEXT("Dodge"), IE_Pressed, this, &AFFRPlayerCharacter::Dodge);
}

void AFFRPlayerCharacter::MoveForward(float Value)
{
    if (FMath::IsNearlyZero(Value) || !Controller) return;
    const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
    AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value);
}

void AFFRPlayerCharacter::MoveRight(float Value)
{
    if (FMath::IsNearlyZero(Value) || !Controller) return;
    const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
    AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Value);
}

void AFFRPlayerCharacter::TurnCamera(float Value)
{
    if (Controller && !FMath::IsNearlyZero(Value)) AddControllerYawInput(Value);
}

void AFFRPlayerCharacter::LookCamera(float Value)
{
    if (Controller && !FMath::IsNearlyZero(Value)) AddControllerPitchInput(Value);
}

void AFFRPlayerCharacter::LightAttack()
{
    PerformAttack(LightAttackDamage, 0.32f);
}

void AFFRPlayerCharacter::HeavyAttack()
{
    PerformAttack(HeavyAttackDamage, 0.72f);
}

void AFFRPlayerCharacter::Dodge()
{
    if (!Controller || !GetCharacterMovement()) return;

    FVector Direction = GetLastMovementInputVector().GetSafeNormal();
    if (Direction.IsNearlyZero())
    {
        Direction = GetActorForwardVector();
    }

    LaunchCharacter(Direction * 650.0f + FVector(0.0f, 0.0f, 80.0f), true, true);
}

void AFFRPlayerCharacter::PerformAttack(float Damage, float Cooldown)
{
    if (!bCanAttack || !GetWorld()) return;
    bCanAttack = false;

    const FVector Start = GetActorLocation() + FVector(0.0f, 0.0f, 55.0f);
    const FVector Center = Start + GetActorForwardVector() * AttackRange;

    TArray<FOverlapResult> Overlaps;
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(FFRPlayerAttack), false, this);
    const bool bHit = GetWorld()->OverlapMultiByChannel(
        Overlaps,
        Center,
        FQuat::Identity,
        ECC_Pawn,
        FCollisionShape::MakeSphere(AttackRadius),
        QueryParams);

    if (bHit)
    {
        TSet<AFFRCharacter*> DamagedTargets;
        for (const FOverlapResult& Result : Overlaps)
        {
            AFFRCharacter* Target = Cast<AFFRCharacter>(Result.GetActor());
            if (!Target || Target == this || !Target->IsAlive() || Target->TeamId == TeamId || DamagedTargets.Contains(Target))
            {
                continue;
            }

            DamagedTargets.Add(Target);
            Target->ReceiveCombatDamage(Damage, this);
        }
    }

    GetWorldTimerManager().SetTimer(AttackCooldownTimer, this, &AFFRPlayerCharacter::ResetAttack, Cooldown, false);
}

void AFFRPlayerCharacter::ResetAttack()
{
    bCanAttack = true;
}
