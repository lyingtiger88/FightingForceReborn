#pragma once
#include "CoreMinimal.h"
#include "FFRTypes.generated.h"
UENUM(BlueprintType)
enum class EFFRCameraMode : uint8 { ThirdPerson UMETA(DisplayName="Third Person Split Screen"), ClassicFixed UMETA(DisplayName="Classic Fixed Camera") };
UENUM(BlueprintType)
enum class EFFRInputDevice : uint8 { KeyboardMouse UMETA(DisplayName="Keyboard and Mouse"), Gamepad UMETA(DisplayName="Gamepad") };
