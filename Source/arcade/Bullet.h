// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "arcade.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class ARCADE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();
	
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite)
    	BulletType bulletType = BulletType::PLAYER;

    UPROPERTY()
    	class USceneComponent* Root;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
    	class UStaticMeshComponent* Mesh;


    UPROPERTY()
    	class UBoxComponent* TriggerBox;

    UPROPERTY()
    	FVector dir;

    UPROPERTY(EditAnywhere,BlueprintReadWrite)
    	float velocity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable)
	void SetBulletMesh(class UStaticMesh* staticMesh=nullptr,  FString path = TEXT(""),  FVector scale = FVector(1.0f,1.0f,1.0f));


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool isXHorizontal = true;
	
	FName autoDestroyTags[4] = { TEXT("downLimit"),TEXT("rightLimit"),TEXT("leftLimit"),TEXT("upperLimit") };

	static constexpr const TCHAR* defaultStaticMeshPath = TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'");
};
