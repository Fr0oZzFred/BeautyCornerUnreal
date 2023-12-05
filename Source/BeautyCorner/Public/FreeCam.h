#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include <LevelSequence/Public/LevelSequence.h>
#include <LevelSequence/Public/LevelSequenceActor.h>
#include <LevelSequence/Public/LevelSequencePlayer.h>
#include <MovieSceneSequencePlayer.h>
#include "FreeCamInputConfig.h"
#include "CineCameraActor.h"
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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Movement")
	float MovementSpeed = 10.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Movement")
	float CameraSpeed = 3.0f;
private:
	float MovementSpeedMultiplier = 1.0f;
	void Move(const FInputActionValue& Value);
	void RotateCam(const FInputActionValue& Value);
	void AddMoveSpeed(const FInputActionValue& Value);

#pragma endregion

#pragma region /** Camera Sequence */
public:
	UPROPERTY(BlueprintReadOnly, Category = "Camera Sequence")
	class ALevelSequenceActor* CineCameraSequence;

	UPROPERTY(BlueprintReadOnly, Category = "Camera Sequence")
	class ACineCameraActor* CineCamera;

	UFUNCTION(BlueprintCallable, Category = "Camera Sequence")
	void ToggleFreeCam();
#pragma endregion
};