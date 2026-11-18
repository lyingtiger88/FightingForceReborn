#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FFRCharacter.generated.h"
UCLASS()
class FIGHTINGFORCEREBORN_API AFFRCharacter : public ACharacter
{
    GENERATED_BODY()
public:
    AFFRCharacter();
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat") float MaxHealth=100.0f;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat") float CurrentHealth=100.0f;
    UFUNCTION(BlueprintCallable, Category="Combat") virtual void ReceiveCombatDamage(float DamageAmount,AActor* DamageCauser);
    UFUNCTION(BlueprintPure, Category="Combat") bool IsAlive() const { return CurrentHealth>0.0f; }
protected:
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintImplementableEvent, Category="Combat") void OnCombatDamageReceived(float DamageAmount,AActor* DamageCauser);
    UFUNCTION(BlueprintImplementableEvent, Category="Combat") void OnCombatDeath(AActor* DamageCauser);
};
