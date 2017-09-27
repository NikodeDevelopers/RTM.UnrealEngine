// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehicle.generated.h"

UCLASS()
class RTM_API AVehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicle();

    UPROPERTY(VisibleAnywhere, Category = "Dynamics")
        FVector speed_;
    UPROPERTY(EditDefaultsOnly, Category = "Dynamics")
        int maxSpeedBoost;
    UPROPERTY(EditDefaultsOnly, Category = "Dynamics")
        int maxSpeed;
    UPROPERTY(EditDefaultsOnly, Category = "Dynamics")
        int maxBrakingBoost;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
