// Fill out your copyright notice in the Description page of Project Settings.


#include "SIPlayerController.h"

#include "Kismet/GameplayStatics.h"

ASIPlayerController::ASIPlayerController()
	: M_MainCameraTag("MainCamera")
{
	M_Cameras.Reserve(5);
}

void ASIPlayerController::BeginPlay() {
	// Set the camera tagged as "MainCamera" as the view target.
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), M_MainCameraTag, M_Cameras);
	if (M_Cameras.Num() > 0)
		this->SetViewTarget(M_Cameras[0]);
}