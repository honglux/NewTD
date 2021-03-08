// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Unit.h"

#include "GridContainer.generated.h"

UCLASS()
class NEWTD_API AGridContainer : public AActor
{
	GENERATED_BODY()

protected:
	TSet<AUnit*> units;
	
public:	
	// Sets default values for this actor's properties
	AGridContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
