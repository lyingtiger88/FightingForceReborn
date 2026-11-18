#pragma once

#include "CoreMinimal.h"
#include "FFRCharacter.h"
#include "FFRPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class FIGHTINGFORCEREBORN_API AFFRPlayerCharacter : public AFFRCharacter
{
    GENERATED_BODY()

public:
    AFFRPlayerCharacter();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    TObjectPtr<USpringArmComponent> CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    TObjectPtr<UCameraComponent> FollowCamera;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(ClampMin="1.0"))
    float LightAttackDamage = 12.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(ClampMin="1.0"))
    float HeavyAttackDamage = 25.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(ClampMin="0.0"))
    float AttackRange = 155.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(ClampMin="1.0"))
    float AttackRadius = 95.0f;

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void TurnCamera(float Value);
    void LookCamera(float Value);
    void LightAttack();
    void HeavyAttack();
    void Dodge();

    void PerformAttack(float Damage, float Cooldown);
    void ResetAttack();

    bool bCanAttack = true;
    FTimerHandle AttackCooldownTimer;
};
