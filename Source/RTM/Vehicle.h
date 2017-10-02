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
        float maxSpeed;
    UPROPERTY(Category = "Dynamics", EditDefaultsOnly) 
        float acceleration;
    UPROPERTY(Category = "Dynamics", EditDefaultsOnly) 
        float deceleration;

    // Sets default values for this actor's properties
    AVehicle();

    // Called every frame
    virtual void Tick(float deltaTime) override;

protected:
    // Speed params
    float speed_;
    float helmAngle_;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Movement
    void Accelerate(float deltaTime);
    void Decelerate(float deltaTime);

    // Update coordinates
    void UpdatePosition(float deltaTime);
};
