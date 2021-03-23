// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridContainer.h"
#include "GameGridBase.h"
#include "Unit.h"

#include "NewTDUtilities.generated.h"

UCLASS()
class NEWTD_API ANewTDUtilities : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewTDUtilities();

	UFUNCTION(BlueprintCallable)
	static AGridContainer* AIGetNextContainer(AUnit* unit,
		AGameGridBase* grid_base, MapDirection dir);

protected:

	static int grid_target_score_cal(AUnit* unit, AGridContainer* container);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
