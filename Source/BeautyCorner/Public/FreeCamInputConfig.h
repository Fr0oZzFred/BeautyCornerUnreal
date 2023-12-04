// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "FreeCamInputConfig.generated.h"

/**
 * 
 */
UCLASS()
class BEAUTYCORNER_API UFreeCamInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputMouse;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputMouseScroll;
};
