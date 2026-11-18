#include "FFRPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
AFFRPlayerController::AFFRPlayerController(){ bShowMouseCursor=false; }
void AFFRPlayerController::BeginPlay(){ Super::BeginPlay(); ApplyMappingContext(); }
void AFFRPlayerController::SetupInputComponent(){ Super::SetupInputComponent(); ApplyMappingContext(); }
void AFFRPlayerController::SetInputDevicePreference(EFFRInputDevice NewPreference){ InputDevicePreference=NewPreference; ApplyMappingContext(); }
void AFFRPlayerController::ApplyMappingContext()
{
    if(!PlayerMappingContext || !GetLocalPlayer()) return;
    if(UEnhancedInputLocalPlayerSubsystem* Subsystem=GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        Subsystem->AddMappingContext(PlayerMappingContext,MappingPriority);
}
