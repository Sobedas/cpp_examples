// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>

void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!OwnerCharacter)
	{
		return;
	}

	// Handles how the set percentage on the progress bar in the HUD widget will be displayed
	HealthBar->SetPercent(OwnerCharacter->GetHealth() / OwnerCharacter->GetMaxHealth());

	// Current health over max health will be displayed on screen
	FNumberFormattingOptions Opts;
	Opts.SetMaximumFractionalDigits(0);
	CurrentHealthLabel->SetText(FText::AsNumber(OwnerCharacter->GetHealth(), &Opts));
	MaxHealthLabel->SetText(FText::AsNumber(OwnerCharacter->GetMaxHealth(), &Opts));
}


