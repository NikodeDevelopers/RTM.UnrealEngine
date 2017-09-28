// Fill out your copyright notice in the Description page of Project Settings.

#include "Vehicle.h"


// Sets default values
AVehicle::AVehicle()
    : maxSpeed(25)
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
void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (speed_.X < maxSpeed) {
        speed_.X += speedAcceleration * DeltaTime;
        if (speed_.X > maxSpeed) {
            speed_.X = maxSpeed;
        }
    }

    FRotator rotator = GetActorRotation();
    rotator.Yaw += 30 * DeltaTime;

    FVector newLocation = GetActorLocation();
    newLocation.X += speed_.X * FMath::Cos(rotator.Yaw) + speed_.Y * FMath::Sin(rotator.Yaw);
    newLocation.Y += speed_.X * FMath::Sin(rotator.Yaw) + speed_.Y * FMath::Cos(rotator.Yaw);
    SetActorLocation(newLocation);
}

