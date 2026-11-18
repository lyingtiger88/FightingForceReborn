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

    UFUNCTION(BlueprintCallable, Category="Local Co-op", meta=(ToolTip="Creates and possesses the second local player. Pass -1 to use the next available controller ID."))
    APlayerController* AddCoopPlayer(int32 ControllerId = -1);

    UFUNCTION(BlueprintPure, Category="Local Co-op")
    bool CanAddCoopPlayer() const;

    UFUNCTION(BlueprintPure, Category="Progression")
    bool IsClassicCameraUnlocked() const;

    UFUNCTION(BlueprintCallable, Category="Progression")
    void CompleteCampaign();

    UFUNCTION(BlueprintCallable, Category="Settings")
    bool SetPreferredCameraMode(EFFRCameraMode NewMode);

    UFUNCTION(BlueprintPure, Category="Settings")
    EFFRCameraMode GetPreferredCameraMode() const;

    UFUNCTION(BlueprintCallable, Category="Save")
    void SaveProgress();

private:
    UPROPERTY()
    TObjectPtr<UFFRSaveGame> SaveData;

    void LoadProgress();
};
