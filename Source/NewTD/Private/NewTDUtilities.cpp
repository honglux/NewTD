// Fill out your copyright notice in the Description page of Project Settings.


#include "NewTDUtilities.h"

// Sets default values
ANewTDUtilities::ANewTDUtilities()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AGridContainer* ANewTDUtilities::AIGetNextContainer(AUnit* unit,
	AGameGridBase* grid_base, MapDirection dir)
{
	PlayerGroup_enum group = PlayerGroup_enum::group1;
	FVector pos = unit->GetActorLocation();
	TArray<AGridContainer*> C_list = grid_base->Get_next_row_containers(pos, dir);
	if (C_list.Num() == 0)
	{
		return nullptr;
	}
	int mins = INT32_MAX, mini = 0, temp_score = 0;
	for (int i = 0; i < C_list.Num(); ++i)
	{
		temp_score = grid_target_score_cal(unit, C_list[i]);
		if (temp_score < mins)
		{
			mins = temp_score;
			mini = i;
		}
	}
	return C_list[mini];
}

int ANewTDUtilities::grid_target_score_cal(AUnit* unit, AGridContainer* container)
{
	int max_s = 100000;
	int dis_scale = 1;
	if (container->Get_player_group() != PlayerGroup_enum::group1)
	{
		//return max_s;
	}
	FVector u_temp_pos = unit->GetActorLocation();
	FVector c_temp_pos = container->GetActorLocation();
	u_temp_pos.Z = 0.0;
	c_temp_pos.Z = 0.0;
	int dist = FVector::Distance(u_temp_pos, c_temp_pos);
	int b_score = 0;
	switch (container->Get_building_state())
	{
	case ContainerBuilding_enum::empty:
	case ContainerBuilding_enum::not_buildable:
		b_score = 1;
		break;
	case ContainerBuilding_enum::tower:
		b_score = 1000;
		break;
	case ContainerBuilding_enum::block:
		b_score = 2000;
		break;
	case ContainerBuilding_enum::unavailable:
		b_score = max_s;
		break;
	default:
		break;
	}
	int score = dist / dis_scale + b_score;
	UE_LOG(LogTemp, Warning, TEXT("unit loc: (%d,%d), container loc: (%d, %d), score: %d"),
		unit->GetActorLocation().X, unit->GetActorLocation().Y,
		container->GetActorLocation().X, container->GetActorLocation().Y,
		score);
	return score;
}

// Called when the game starts or when spawned
void ANewTDUtilities::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANewTDUtilities::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

