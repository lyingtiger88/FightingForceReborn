#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FFRTypes.h"
#include "FFRPlayerController.generated.h"
class UInputMappingContext;
UCLASS()
class FIGHTINGFORCEREBORN_API AFFRPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    AFFRPlayerController();
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input") TObjectPtr<UInputMappingContext> PlayerMappingContext;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input") int32 MappingPriority=0;
    UFUNCTION(BlueprintCallable, Category="Input") void SetInputDevicePreference(EFFRInputDevice NewPreference);
    UFUNCTION(BlueprintPure, Category="Input") EFFRInputDevice GetInputDevicePreference() const { return InputDevicePreference; }
protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
private:
    UPROPERTY(VisibleInstanceOnly, Category="Input") EFFRInputDevice InputDevicePreference=EFFRInputDevice::Gamepad;
    void ApplyMappingContext();
};
