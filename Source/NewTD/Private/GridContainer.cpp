// Fill out your copyright notice in the Description page of Project Settings.


#include "GridContainer.h"
#include "Unit.h"

// Sets default values
AGridContainer::AGridContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	units = TMap<int, AUnit*>();
	building = nullptr;
	building_state = ContainerBuilding_enum::empty;
	pos_index = 0;
}

void AGridContainer::Init_GridCcontainer(int _pos_index)
{
	pos_index = _pos_index;
}

TEnumAsByte<PlayerGroup_enum> AGridContainer::Get_player_group()
{
	return player_group;
}

TEnumAsByte<ContainerBuilding_enum> AGridContainer::Get_building_state()
{
	return building_state;
}

int AGridContainer::Get_pos_index()
{
	return pos_index;
}

bool AGridContainer::Add_to_container(AUnit* _building)
{
	building = _building;
	building_state = _building->building_state;
	return true;
}

bool AGridContainer::Erase_building()
{
	building_state = ContainerBuilding_enum::empty;
	building = nullptr;
	return false;
}

bool AGridContainer::IsBuildable(TEnumAsByte<PlayerGroup_enum> _player_group)
{
	return (player_group == _player_group) &&
		building_state == ContainerBuilding_enum::empty;
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

