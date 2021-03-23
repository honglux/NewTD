// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Unit.h"
#include "EnumController.h"

#include "GridContainer.generated.h"

UCLASS()
class NEWTD_API AGridContainer : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TEnumAsByte<PlayerGroup_enum> player_group;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TEnumAsByte<ContainerBuilding_enum> building_state;

	TMap<int, AUnit*> units;	//ID, unit;
	int pos_index;
	AUnit* building;
	
public:
	// Sets default values for this actor's properties
	AGridContainer();

	UFUNCTION(BlueprintCallable)
		virtual int Get_pos_index();

	virtual void Init_GridCcontainer(int _pos_index);
	TEnumAsByte<PlayerGroup_enum> Get_player_group();
	TEnumAsByte<ContainerBuilding_enum> Get_building_state();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
