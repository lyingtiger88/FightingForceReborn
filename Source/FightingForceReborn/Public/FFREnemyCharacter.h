#pragma once

#include "CoreMinimal.h"
#include "FFRCharacter.h"
#include "FFREnemyCharacter.generated.h"

UCLASS()
class FIGHTINGFORCEREBORN_API AFFREnemyCharacter : public AFFRCharacter
{
    GENERATED_BODY()

public:
    AFFREnemyCharacter();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="50.0"))
    float PreferredCombatDistance = 135.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="1.0"))
    float AttackDamage = 10.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0.1"))
    float AttackInterval = 1.25f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0.1"))
    float ThinkInterval = 0.35f;

protected:
    virtual void BeginPlay() override;

private:
    void UpdateCombatBehavior();
    AFFRCharacter* FindNearestPlayer() const;

    FTimerHandle ThinkTimer;
    float NextAttackTime = 0.0f;
};
