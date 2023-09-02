// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FridgeDoor.generated.h"

UCLASS()
class PROJECTASSIGNMENT_API AFridgeDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFridgeDoor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	UFUNCTION(BlueprintCallable, Category = "FridgeDoor")
	void OpenDoor();

	UFUNCTION(BlueprintCallable, Category = "FridgeDoor")
	void CloseDoor();

private:
	bool bIsOpen;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
