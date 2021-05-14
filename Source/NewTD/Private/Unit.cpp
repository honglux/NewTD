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
	AOEAnimation = false;
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
	Super::Tick(DeltaTime);
	if (target && !isAOE) {
		if (isAttacking) {
			time += DeltaTime;

			if (time >= attack_interval) {
				(target->health) -= (this->damage);
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("health %f"), target->health));
				time = 0.0f;
				AttackAnimation();
			}
		}

		float dist = FVector::Dist(this->GetActorLocation(), target->GetActorLocation());

		if (target->health <= 0.0f || dist >= 400.0f) {
			isAttacking = false;
		}
	}

	if (isAOE && targets.Num() >= 0 && isAttacking) {
		time += DeltaTime;
		if (time >= attack_interval) {
			AOEAnimation = true;
			AttackAnimation();
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("health")));
			for (auto t : targets) {
				t->health -= this->damage;
			}
			time = 0.0f;
			AOEAnimation = false;
			isAttacking = false;
		}
	}


}

void AUnit::Attcking (AUnit* t) {
	target = t;
	isAttacking = true;
}

void AUnit::AOEAttcking (TArray<AUnit*> ts) {
	if (!isAttacking) {
		targets = ts;
		isAttacking = true;
	}
}

void AUnit::AttackAnimation_Implementation() {

}

// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

