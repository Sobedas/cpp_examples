// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class GAM312_PROJECT_MR_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	

	void CameraSwitch();
	// Sets default values for this actor's properties
	ACameraDirector();
	// Added this section from Unreal Documentation
	// UPROPERTY macros will make variables visible to Unreal Engine making the values set in the variables to not
	// reset when launching game or reloading level or project in the future 
	// EditAnywhere will allow and set CameraOne and CameraTwo in the Unreal Editor
	UPROPERTY(EditAnywhere)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere)
		AActor* CameraTwo;

	float TimeToNextCameraChange;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame - commented this out since we don't need anything running every frame
	//virtual void Tick(float DeltaTime) override;

};
