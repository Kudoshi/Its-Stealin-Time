// Fill out your copyright notice in the Description page of Project Settings.


#include "FridgeDoor.h"

// Sets default values
AFridgeDoor::AFridgeDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create the door mesh component and attach it to the root component
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	// Set default values
	bIsOpen = false;
}

// Called when the game starts or when spawned
void AFridgeDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFridgeDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFridgeDoor::OpenDoor()
{
	if (!bIsOpen)
	{
		DoorMesh->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
		bIsOpen = true;
	}
}

void AFridgeDoor::CloseDoor()
{
	if (bIsOpen)
	{
		DoorMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		bIsOpen = false;
	}
}