// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_MapWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTASSIGNMENT_API UCPP_MapWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ToggleGameMap();

};
