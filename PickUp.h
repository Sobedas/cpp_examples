// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "PickUp.generated.h"

UCLASS()
class GAM312_PROJECT_MR_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Created this function to show when a object is interacted with in scene
	// when to set it to hidden and active to false
	void Interacted();
	bool GetActive();

private:

	UPROPERTY()
		bool active;

	UPROPERTY(VisibleAnywhere, Category= "Mesh");
	class UStaticMeshComponent* mesh;
};
