// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Crouching.generated.h"

UCLASS()
class PROJECTASSIGNMENT_API ACrouching : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACrouching();

protected:
	bool isCrouching;

public:	
	UFUNCTION(BlueprintCallable, Category = "Crouching")
		void StartCrouch();
	UFUNCTION(BlueprintCallable, Category = "Crouching")
		void StopCrouch();
};
