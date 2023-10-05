// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GAM312_Project_MRCharacter.h"
#include "HealthBar.generated.h"

UCLASS(Abstract)
class GAM312_PROJECT_MR_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public: 

	// Creates a function that will get the character's pointer and assign that to a 
	// varible that will later be used in the binding properties for HUD widget
	void SetOwnerCharacter(MRCharacter* InCharacter) { OwnerCharacter = InCharacter; }

protected:

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	// These are the properties that will be get each bind widget element to display
	// each element needed for HUD widget onto the player's screen with the desired
	// varibles 
	UPROPERTY()
	MRCharacter* OwnerCharacter;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentHealthLabel;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxHealthLabel;
	
};
