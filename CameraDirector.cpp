// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
// Added this section of code from Unreal Documentation
// It gives access to useful general-purpose functions
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::CameraSwitch()
{
	
    // Added this section from Unreal Documentation
    // This code will switch the default player's view between two different cameras every eight seconds
    const float SmoothBlendTime = 0.75f;

    // Find the actor that handles control for the local player.
    APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (OurPlayerController)
    {
        if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
        {
            // Cut instantly to camera one.
            OurPlayerController->SetViewTarget(CameraOne);
        }
        else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
        {
            // Blend smoothly to camera two.
            OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
        }
    }
}

