// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flashlight.generated.h"

UCLASS()
class PROJECTASSIGNMENT_API AFlashlight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashlight();

protected:
	UPROPERTY(VisibleAnywhere)
		class USpotLightComponent * FlashlightComponent;
	bool IsOn;

public:	
	// Called every frame
	void ToggleFlashlight();

};
