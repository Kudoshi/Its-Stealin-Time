// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_BP.h"


// Sets default values
APlayer_BP::APlayer_BP()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayer_BP::BeginPlay()
{
	Super::BeginPlay();
	CharacterMovementComponent = GetCharacterMovement();
	crouched.BindUFunction(this, FName("Crouching"));
	uncrouched.BindUFunction(this, FName("Not Crouching"));
}

// Called to bind functionality to input
void APlayer_BP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

