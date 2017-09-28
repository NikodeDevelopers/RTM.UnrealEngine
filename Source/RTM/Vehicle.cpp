// Fill out your copyright notice in the Description page of Project Settings.

#include "Vehicle.h"


// Sets default values
AVehicle::AVehicle()
    : maxSpeed(21)
    , speedAcceleration(2)
    , brakingAcceleration(7)
    , speed_(0, 0, 0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicle::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

    // Get position
    FVector location = GetActorLocation();
    FRotator rotator = GetActorRotation();
    
    // After cross the finish
    if (location.X > 300) {
        speed_.X -= brakingAcceleration * deltaTime;
        if (speed_.X < 0) {
            speed_.X = 0;
        }
    }
    // Boost
    else if (speed_.X < maxSpeed) {
        speed_.X += speedAcceleration * deltaTime;
        if (speed_.X > maxSpeed) {
            speed_.X = maxSpeed;
        }
    }
    
    // Move
    float cosCoeff = FMath::Cos(PI * rotator.Yaw / 180) * deltaTime;
    float sinCoeff = FMath::Sin(PI * rotator.Yaw / 180) * deltaTime;
    location.X += speed_.X * cosCoeff + speed_.Y * sinCoeff;
    location.Y += speed_.Y * cosCoeff + speed_.X * sinCoeff;
    location.Z += speed_.Z;

    // Set position
    SetActorLocation(location);
    SetActorRotation(rotator);
}

