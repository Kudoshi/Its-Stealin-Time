// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Flashlight_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLASHLIGHT_API UFlashlight_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlashlight_Component();
	UFUNCTION(BlueprintCallable)
		void ToggleFlashlight();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
		class USpotLightComponent* Flashlight;
	bool IsOn;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
