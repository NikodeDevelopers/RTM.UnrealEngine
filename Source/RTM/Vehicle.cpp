// Fill out your copyright notice in the Description page of Project Settings.

#include "Vehicle.h"


// Sets default values
AVehicle::AVehicle()
    : maxSpeed(21.f)
    , acceleration(2.f)
    , deceleration(7.f)
    , speed_(0.f)
    , helmAngle_(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVehicle::Accelerate(float deltaTime)
{
    if (speed_ < maxSpeed) {
        speed_ += acceleration * deltaTime;
        if (speed_ > maxSpeed) {
            speed_ = maxSpeed;
        }
    }
}

void AVehicle::Decelerate(float deltaTime)
{
    if (speed_ > 0) {
        speed_ -= deceleration * deltaTime;
        if (speed_ < 0) {
            speed_ = 0;
        }
    }
}

// Movement
void AVehicle::UpdatePosition(float deltaTime)
{
    // Get position
    FVector location = GetActorLocation();
    FRotator rotator = GetActorRotation();

    // Move
    rotator.Yaw += helmAngle_;
    location.X += speed_ * FMath::Cos(PI * rotator.Yaw / 180) * deltaTime;
    location.Y += speed_ * FMath::Sin(PI * rotator.Yaw / 180) * deltaTime;

    // Set position
    SetActorLocation(location);
    SetActorRotation(rotator);
}

// Called every frame
void AVehicle::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

    if (GetActorLocation().X > 300) {
        Decelerate(deltaTime);
    }
    else {
        Accelerate(deltaTime);
    }
    
    // Update coordinates
    UpdatePosition(deltaTime);
}

