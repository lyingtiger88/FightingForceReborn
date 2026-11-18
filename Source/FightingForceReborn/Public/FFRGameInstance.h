#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FFRTypes.h"
#include "FFRGameInstance.generated.h"
class UFFRSaveGame;
UCLASS()
class FIGHTINGFORCEREBORN_API UFFRGameInstance : public UGameInstance
{
    GENERATED_BODY()
public:
    virtual void Init() override;
    UFUNCTION(BlueprintCallable, Category="Local Co-op") APlayerController* AddCoopPlayer(int32 ControllerId);
    UFUNCTION(BlueprintPure, Category="Progression") bool IsClassicCameraUnlocked() const;
    UFUNCTION(BlueprintCallable, Category="Progression") void CompleteCampaign();
    UFUNCTION(BlueprintCallable, Category="Settings") bool SetPreferredCameraMode(EFFRCameraMode NewMode);
    UFUNCTION(BlueprintPure, Category="Settings") EFFRCameraMode GetPreferredCameraMode() const;
    UFUNCTION(BlueprintCallable, Category="Save") void SaveProgress();
private:
    UPROPERTY() TObjectPtr<UFFRSaveGame> SaveData;
    void LoadProgress();
};
