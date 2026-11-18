#include "FFRCharacter.h"

AFFRCharacter::AFFRCharacter()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AFFRCharacter::BeginPlay()
{
    Super::BeginPlay();
    MaxHealth = FMath::Max(1.0f, MaxHealth);
    CurrentHealth = MaxHealth;
}

void AFFRCharacter::ReceiveCombatDamage(float DamageAmount, AActor* DamageCauser)
{
    if (!IsAlive() || DamageAmount <= 0.0f) return;

    const float PreviousHealth = CurrentHealth;
    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.0f, MaxHealth);
    OnCombatDamageReceived(PreviousHealth - CurrentHealth, DamageCauser);

    if (CurrentHealth <= 0.0f)
    {
        OnCombatDeath(DamageCauser);
        SetActorEnableCollision(false);
    }
}
