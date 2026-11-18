#include "FFRGameInstance.h"
#include "FFRSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"
namespace { const TCHAR* SaveSlot=TEXT("FFR_Profile"); constexpr int32 UserIndex=0; }
void UFFRGameInstance::Init(){ Super::Init(); LoadProgress(); }
void UFFRGameInstance::LoadProgress()
{
    if(UGameplayStatics::DoesSaveGameExist(SaveSlot,UserIndex))
        SaveData=Cast<UFFRSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot,UserIndex));
    if(!SaveData) SaveData=Cast<UFFRSaveGame>(UGameplayStatics::CreateSaveGameObject(UFFRSaveGame::StaticClass()));
    if(!SaveData->bCampaignCompleted) SaveData->PreferredCameraMode=EFFRCameraMode::ThirdPerson;
}
APlayerController* UFFRGameInstance::AddCoopPlayer(int32 ControllerId)
{
    FString Error; ULocalPlayer* NewPlayer=CreateLocalPlayer(ControllerId,Error,true);
    return NewPlayer ? NewPlayer->GetPlayerController(GetWorld()) : nullptr;
}
bool UFFRGameInstance::IsClassicCameraUnlocked() const { return SaveData && SaveData->bCampaignCompleted; }
void UFFRGameInstance::CompleteCampaign(){ if(!SaveData)return; SaveData->bCampaignCompleted=true; SaveProgress(); }
bool UFFRGameInstance::SetPreferredCameraMode(EFFRCameraMode Mode)
{
    if(!SaveData || (Mode==EFFRCameraMode::ClassicFixed && !IsClassicCameraUnlocked())) return false;
    SaveData->PreferredCameraMode=Mode; SaveProgress(); return true;
}
EFFRCameraMode UFFRGameInstance::GetPreferredCameraMode() const { return SaveData ? SaveData->PreferredCameraMode : EFFRCameraMode::ThirdPerson; }
void UFFRGameInstance::SaveProgress(){ if(SaveData) UGameplayStatics::SaveGameToSlot(SaveData,SaveSlot,UserIndex); }
