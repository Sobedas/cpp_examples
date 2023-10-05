// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorLight.h"
#include "Components/PointLightComponent.h"

// Sets default values
AHorrorLight::AHorrorLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create our light component and set some properties
    HorrorLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("HorrorLight"));
    HorrorLight->Intensity = 7000;
    HorrorLight->bAddedToSceneVisible = true;
    HorrorLight->SetLightColor(FLinearColor(FColor(150, 0, 0)));
    RootComponent = HorrorLight;
}

// Called when the game starts or when spawned
void AHorrorLight::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHorrorLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //Flickering light done with random deltatime
    timeHorrorLightFlicker -= DeltaTime;
    if (timeHorrorLightFlicker <= 0)
    {
        HorrorLight->ToggleVisibility();
        timeHorrorLightFlicker = FMath::RandRange(0.05, 1);
    }

}

