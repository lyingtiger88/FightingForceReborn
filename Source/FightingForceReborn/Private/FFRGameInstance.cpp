#include "FFRGameInstance.h"

#include "FFRSaveGame.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

namespace
{
    const TCHAR* SaveSlot = TEXT("FFR_Profile");
    constexpr int32 UserIndex = 0;
    constexpr int32 MaxLocalPlayers = 2;
}

void UFFRGameInstance::Init()
{
    Super::Init();
    LoadProgress();
}

void UFFRGameInstance::LoadProgress()
{
    if (UGameplayStatics::DoesSaveGameExist(SaveSlot, UserIndex))
    {
        SaveData = Cast<UFFRSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, UserIndex));
    }

    if (!SaveData)
    {
        SaveData = Cast<UFFRSaveGame>(UGameplayStatics::CreateSaveGameObject(UFFRSaveGame::StaticClass()));
    }

    if (!SaveData->bCampaignCompleted)
    {
        SaveData->PreferredCameraMode = EFFRCameraMode::ThirdPerson;
    }
}

bool UFFRGameInstance::CanAddCoopPlayer() const
{
    return GetLocalPlayers().Num() < MaxLocalPlayers;
}

APlayerController* UFFRGameInstance::AddCoopPlayer(int32 ControllerId)
{
    if (!CanAddCoopPlayer() || !GetWorld())
    {
        return nullptr;
    }

    if (ControllerId >= 0)
    {
        for (const ULocalPlayer* ExistingPlayer : GetLocalPlayers())
        {
            if (ExistingPlayer && ExistingPlayer->GetControllerId() == ControllerId)
            {
                UE_LOG(LogTemp, Warning, TEXT("Controller ID %d is already assigned to a local player."), ControllerId);
                return nullptr;
            }
        }
    }

    FString Error;
    ULocalPlayer* NewLocalPlayer = CreateLocalPlayer(ControllerId, Error, true);
    if (!NewLocalPlayer)
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not create local co-op player: %s"), *Error);
        return nullptr;
    }

    APlayerController* NewController = NewLocalPlayer->GetPlayerController(GetWorld());
    if (!NewController)
    {
        UE_LOG(LogTemp, Error, TEXT("Local player was created without a PlayerController."));
        return nullptr;
    }

    if (AGameModeBase* GameMode = GetWorld()->GetAuthGameMode())
    {
        GameMode->RestartPlayer(NewController);
    }

    return NewController;
}

bool UFFRGameInstance::IsClassicCameraUnlocked() const
{
    return SaveData && SaveData->bCampaignCompleted;
}

void UFFRGameInstance::CompleteCampaign()
{
    if (!SaveData) return;
    SaveData->bCampaignCompleted = true;
    SaveProgress();
}

bool UFFRGameInstance::SetPreferredCameraMode(EFFRCameraMode Mode)
{
    if (!SaveData || (Mode == EFFRCameraMode::ClassicFixed && !IsClassicCameraUnlocked()))
    {
        return false;
    }

    SaveData->PreferredCameraMode = Mode;
    SaveProgress();
    return true;
}

EFFRCameraMode UFFRGameInstance::GetPreferredCameraMode() const
{
    return SaveData ? SaveData->PreferredCameraMode : EFFRCameraMode::ThirdPerson;
}

void UFFRGameInstance::SaveProgress()
{
    if (SaveData)
    {
        UGameplayStatics::SaveGameToSlot(SaveData, SaveSlot, UserIndex);
    }
}
