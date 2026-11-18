#include "FFRGameMode.h"
#include "FFRPlayerController.h"
#include "FFRPlayerCharacter.h"

AFFRGameMode::AFFRGameMode()
{
    PlayerControllerClass = AFFRPlayerController::StaticClass();
    DefaultPawnClass = AFFRPlayerCharacter::StaticClass();
}
