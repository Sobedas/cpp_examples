// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HorrorLight.generated.h"

UCLASS()
class GAM312_PROJECT_MR_API AHorrorLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHorrorLight();

	// This is the Point light that will flicker
	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent* HorrorLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// This will be amount of time that the light will flicker randomly
	float timeHorrorLightFlicker;

};
