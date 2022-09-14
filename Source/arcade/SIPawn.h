// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIGameModeBase.h"
#include "GameFramework/DefaultPawn.h"
#include "Sound/SoundCue.h"
#include "SIPawn.generated.h"

UCLASS()
class ARCADE_API ASIPawn : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 pointsPerInvader;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 pointsPerSquad;
	
	FStandardDelegateSignature* SquadDissolved;
	FStandardDelegateSignature* SquadSuccessful;
	FOneParamMulticastDelegateSignature* InvaderDestroyed;

	FOneParamDelegateSignature* NewSquad;
	FStandardDelegateSignature* PlayerZeroLifes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float velocity = 1000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float bulletVelocity = 3000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isXHorizontal = true;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<class ABullet> bulletClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* PFXExplosion;

	UFUNCTION(BlueprintPure, Category = "Player")
	int32 GetPlayerPoints();

	UFUNCTION(BlueprintPure, Category = "Player")
	int32 GetPlayerLifes();
	
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	ASIPawn();
	
	void OnInvaderDestroyed(int32 id);
	void OnSquadSuccessful();
	void OnSquadDissolved();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	FTimerHandle timerHandle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* AudioShoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* AudioExplosion;


protected:
	
	UFUNCTION(BlueprintCallable)
	void SetStaticMesh(class UStaticMesh* staticMesh = nullptr,  FString path = TEXT(""),  FVector scale = FVector(1.0f,1.0f,1.0f));
	
	UFUNCTION(BlueprintCallable)
	void PostPlayerDestroyed();
	
	virtual void BeginPlay() override;
	
	void OnPlayerDestroyed();

	void OnMove(float value);
	
	void OnFire();
	
	void OnPause();

private:
	
	UPROPERTY()
	UAudioComponent* AudioComponent;

	UPROPERTY()
	ABullet* bulletTemplate;
		
	int32 playerPoints;
	int32 playerLifes;
	
	bool bFrozen;
	bool bPause;

	static constexpr const TCHAR* defaultStaticMeshPath = TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'");
};
