// Fill out your copyright notice in the Description page of Project Settings.


#include "GridContainer.h"
#include "Unit.h"

// Sets default values
AGridContainer::AGridContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	units = TSet<AUnit*>();

}

// Called when the game starts or when spawned
void AGridContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

