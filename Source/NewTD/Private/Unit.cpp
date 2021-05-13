// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	target = NULL;
	time = 0.0f;
	isAttacking = false;
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	time = 0;
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	if (target) {
		if (isAttacking) {
			Super::Tick(DeltaTime);
			time += DeltaTime;

			if (time >= attack_interval) {
				target->health -= this->damage;
				time = 0.0f;
			}
		}

		float dist = FVector::Dist(this->location, target->location);

		if (target->health <= 0.0f || dist >= 300.0f) {
			isAttacking = false;
		}
	}
}

void AUnit::Attcking (AUnit* t) {
	target = t;
	isAttacking = true;
}

// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

