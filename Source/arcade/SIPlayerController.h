// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARCADE_API ASIPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	ASIPlayerController();

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<AActor*> M_Cameras;
	FName M_MainCameraTag;

};
