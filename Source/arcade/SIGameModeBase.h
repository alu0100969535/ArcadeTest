// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SIGameModeBase.generated.h"


DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_MULTICAST_DELEGATE_OneParam(FOneParamMulticastDelegateSignature, int32);
DECLARE_DELEGATE_OneParam(FOneParamDelegateSignature, int32)

UCLASS()
class ARCADE_API ASIGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<class AInvaderSquad> InvaderSquadClass;
	
	UPROPERTY(EditAnyWhere,BlueprintReadWrite, Category= "Level Layout")
		FVector spawnLocation = FVector(300.0f, -1800.0f, 150.0f);
	
	UPROPERTY(EditAnyWhere,BlueprintReadWrite, Category = "Level Layout")
		int32 nInvaderRows;
	
	UPROPERTY(EditAnyWhere,BlueprintReadWrite, Category = "Level Layout")
		int32 nInvaderCols;
	
	UPROPERTY(EditAnyWhere,BlueprintReadWrite,Category="Game parameters")
		int32 nRounds = 0;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite,Category="Game parameters")
		int32 pointsPerInvader = 1000;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game parameters")
		int32 pointsPerSquad = 10000;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AInvaderSquad* spawnedInvaderSquad;

	
	// Delegates
	FStandardDelegateSignature SquadOnLeftSide;
	FStandardDelegateSignature SquadOnRightSide;
	FStandardDelegateSignature SquadOnDownSide;
	FStandardDelegateSignature SquadFinishesDown;
	FStandardDelegateSignature SquadDissolved;
	FStandardDelegateSignature SquadSuccessful;
	FOneParamMulticastDelegateSignature InvaderDestroyed;
	
	FOneParamDelegateSignature NewSquad;
	FStandardDelegateSignature PlayerZeroLifes;

	ASIGameModeBase();

	void EndGame();

protected:
	virtual void BeginPlay();
	
	UFUNCTION(BlueprintCallable)
		void RegenerateSquad();
	
	UFUNCTION(BlueprintCallable)
		void OnNewSquad(int32 lifes);
	
	UFUNCTION(BlueprintCallable)
		void OnPlayerZeroLifes();

};
