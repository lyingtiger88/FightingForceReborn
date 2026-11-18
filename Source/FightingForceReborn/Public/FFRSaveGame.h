#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FFRTypes.h"
#include "FFRSaveGame.generated.h"
UCLASS()
class FIGHTINGFORCEREBORN_API UFFRSaveGame : public USaveGame
{
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Progression") bool bCampaignCompleted = false;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Settings") EFFRCameraMode PreferredCameraMode = EFFRCameraMode::ThirdPerson;
};
