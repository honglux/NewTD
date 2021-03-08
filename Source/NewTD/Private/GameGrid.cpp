// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"
#include "GridContainer.h"

#include <string>

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	rows = 0;
	cols = 0;
	containers = TMap<FString, AGridContainer*>();
}

AGameGrid::AGameGrid(int _r, int _c)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	rows = _r;
	cols = _c;
	containers = TMap<FString, AGridContainer*>();
}

void AGameGrid::SetContainerPrefab(UObject* prefab)
{
	//cont_prefab = prefab->GetClass();
}

bool AGameGrid::InitContainers(int _lx, int _rx, int _dy, int _uy, int gap,
	class TSubclassOf<AGridContainer> cont_prefab)
{
	FString coord_str = "";
	AGridContainer* temp_cont = nullptr;
	FVector temp_vec;
	for (int x = _lx; x < _rx; x += gap)
	{
		for (int y = _dy; y < _uy; y += gap)
		{
			coord_str = CoordToString(x, y);
			temp_vec = FVector(x, y, 0);
			temp_cont = (AGridContainer*)(GetWorld()->SpawnActor(cont_prefab,
				&temp_vec));
		}
	}

	return false;
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

