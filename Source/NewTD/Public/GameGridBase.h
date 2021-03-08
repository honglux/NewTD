// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameGridBase.generated.h"

UCLASS()
class NEWTD_API AGameGridBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int y_offset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int lx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int rx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int dy;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int uy;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int gap;
	
public:	
	// Sets default values for this actor's properties
	AGameGridBase();
	
	//bool InitGrid(int _lx, int _rx, int _dy, int _uy, int _gap);
	UFUNCTION(BlueprintCallable)
	virtual FVector Grid_pos_cal(const FVector& pos);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual int Grid_axis_cal(int val);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
