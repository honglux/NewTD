// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGridBase.h"

// Sets default values
AGameGridBase::AGameGridBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

bool AGameGridBase::InitGrid(int _z_offset, int _lx, int _rx, int _dy, int _uy, int _gap,
	bool _use_ZO)
{
	z_offset = _z_offset;
	lx = _lx;
	rx = _rx;
	dy = _dy;
	uy = _uy;
	gap = _gap;
	use_ZO = _use_ZO;
	return false;
}

FVector AGameGridBase::Grid_pos_cal(const FVector& pos)
{
	int half_gap = ((int)gap) / 2;
	int posx = (int)pos.X;
	int posy = (int)pos.Y;
	int gridx = Grid_axis_cal(posx);
	int gridy = Grid_axis_cal(posy);
	int z = 0;
	if (use_ZO) { z = z_offset; }
	else { z = pos.Z; }
	FVector pos2 = FVector(gridx, gridy, z);
	return pos2;
}

//FVector AGameGridBase::Editor_grid_pos_cal(const FVector& pos)
//{
//	return FVector();
//}

// Called when the game starts or when spawned
void AGameGridBase::BeginPlay()
{
	Super::BeginPlay();
	
}

int AGameGridBase::Grid_axis_cal(int val)
{
	int v_sign = val < 0 ? -1 : 1;
	int half_gap = ((int)gap) / 2;
	val += half_gap * v_sign;
	int grid_v = val / gap * gap;
	return grid_v;
}

// Called every frame
void AGameGridBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//FVector AGameGridBase::Editor_grid_pos_cal_Implementation(const FVector& pos)
//{
//	return FVector::ZeroVector;
//}