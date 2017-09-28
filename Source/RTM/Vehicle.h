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

protected:
    // Vector of speed
    FVector speed_;

public:
    // Sets default values for this actor's properties
    AVehicle();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
