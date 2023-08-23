// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"

// Sets default values
ATimer::ATimer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimer::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this,&ATimer::CountDown,1.f,true,0.0);
	
}

// Called every frame
void ATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATimer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATimer::CountDown()
{
	if(Seconds != 0)
	{
		Seconds = Seconds-1;
	}

	else
	{
		{
			if(Minutes ==0)
			{
				//Do things here
			}

			else
			{
				{
					Minutes = Minutes-1;
					Seconds = 59;
				}
			}
		}
	}
}

