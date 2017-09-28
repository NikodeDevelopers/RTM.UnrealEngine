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
    // Dynamics
    UPROPERTY(Category = "Dynamics", EditDefaultsOnly) 
        int maxSpeed;
    UPROPERTY(Category = "Dynamics", EditDefaultsOnly) 
        int speedAcceleration;
    UPROPERTY(Category = "Dynamics", EditDefaultsOnly) 
        int brakingAcceleration;

    // Sets default values for this actor's properties
    AVehicle();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Vector of speed (x - forward, y - lateral, z - FLIGHT)
    FVector speed_;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

};
