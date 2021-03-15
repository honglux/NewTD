// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"
#include "GridContainer.h"
#include "GameGridBase.h"

#include <string>

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//rows = 0;
	//cols = 0;
	containers = TMap<FString, AGridContainer*>();
	//prefab = nullptr;
}

//AGameGrid::AGameGrid(int _r, int _c)
//{
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = false;
//
//	rows = _r;
//	cols = _c;
//	containers = TMap<FString, AGridContainer*>();
//}

//void AGameGrid::SetContainerPrefab(UObject* _prefab)
//{
//	prefab = _prefab;
//}

bool AGameGrid::InitContainers(class TSubclassOf<AGridContainer> cont_prefab, 
	AGameGridBase* GGB_OBJ)
{
	FString coord_str = "";
	AGridContainer* temp_cont = nullptr;
	FVector temp_vec;
	TArray<FVector> pos_arr = *(GGB_OBJ->Get_grid_posos());
	int x = 0, y = 0;
	for (int i = 0; i < pos_arr.Num(); ++i)
	{
		x = pos_arr[i].X;
		y = pos_arr[i].Y;
		coord_str = CoordToString(x, y);
		temp_cont = (AGridContainer*)(GetWorld()->SpawnActor(cont_prefab,
			&pos_arr[i]));
		containers.Add(coord_str, temp_cont);
	}
	return true;
}

FString AGameGrid::CoordToString(int _r, int _c)
{
	std::string res = "";
	res += std::to_string(_r);
	res += '_';
	res += std::to_string(_c);
	return FString(res.c_str());
}

// Called when the game starts or when spawned
void AGameGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

