// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridContainer.h"

#include "GameGrid.generated.h"

UCLASS()
class NEWTD_API AGameGrid : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, AGridContainer*> containers;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int rows;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int cols;

public:	
	// Sets default values for this actor's properties
	AGameGrid();
	AGameGrid(int _r, int _c);

	UFUNCTION(BlueprintCallable)
	void SetContainerPrefab(UObject* prefab);
	UFUNCTION(BlueprintCallable)
		bool InitContainers(int _lx, int _rx, int _dy, int _uy, int gap,
			class TSubclassOf<AGridContainer> cont_prefab);
	UFUNCTION(BlueprintCallable)
	FString CoordToString(int _r, int _c);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
