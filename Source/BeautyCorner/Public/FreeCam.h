#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "FreeCamInputConfig.h"
#include "FreeCam.generated.h"

UCLASS()
class BEAUTYCORNER_API AFreeCam : public APawn
{
	GENERATED_BODY()

public:
	AFreeCam();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region /** Input */
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UFreeCamInputConfig* InputActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;

#pragma endregion

#pragma region /** Movement */
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float MovementSpeed = 10.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float CameraSpeed = 1.0f;
private:
	float MovementSpeedMultiplier = 1.0f;
	void Move(const FInputActionValue& Value);
	void RotateCam(const FInputActionValue& Value);
	void AddMoveSpeed(const FInputActionValue& Value);

#pragma endregion
};