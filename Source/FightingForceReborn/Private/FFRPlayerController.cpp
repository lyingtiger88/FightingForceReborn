#include "FFRPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

AFFRPlayerController::AFFRPlayerController()
{
    bShowMouseCursor = false;
}

void AFFRPlayerController::BeginPlay()
{
    Super::BeginPlay();
    ApplyMappingContext();
}

void AFFRPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    ApplyMappingContext();
}

void AFFRPlayerController::SetInputDevicePreference(EFFRInputDevice NewPreference)
{
    InputDevicePreference = NewPreference;
    ApplyMappingContext();
}

void AFFRPlayerController::ApplyMappingContext()
{
    if (!GetLocalPlayer()) return;

    UEnhancedInputLocalPlayerSubsystem* Subsystem =
        GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    if (!Subsystem) return;

    if (AppliedMappingContext)
    {
        Subsystem->RemoveMappingContext(AppliedMappingContext);
        AppliedMappingContext = nullptr;
    }

    UInputMappingContext* DesiredContext =
        InputDevicePreference == EFFRInputDevice::KeyboardMouse
            ? KeyboardMouseMappingContext.Get()
            : GamepadMappingContext.Get();

    if (DesiredContext)
    {
        Subsystem->AddMappingContext(DesiredContext, MappingPriority);
        AppliedMappingContext = DesiredContext;
    }
}
