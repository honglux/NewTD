// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGridBase.h"

#include <string>

// Sets default values
AGameGridBase::AGameGridBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	z_offset = 0;
	gap = 0;
	container_pool = TMap<FString, AGridContainer*>();
	grid_poses = TArray<FVector>();
}

bool AGameGridBase::InitGrid(int _z_offset, int _ly, int _ry, int _dx, int _ux, int _gap,
	bool _use_ZO)
{
	z_offset = _z_offset;
	ly = _ly;
	ry = _ry;
	dx = _dx;
	ux = _ux;
	gap = _gap;
	use_ZO = _use_ZO;
	return true;
}

FVector AGameGridBase::Grid_pos_cal(const FVector& pos)
{
	int half_gap = ((int)gap) / 2;
	int posx = (int)pos.X;
	int posy = (int)pos.Y;
	int gridx = Grid_axis_cal(posx, dx);
	int gridy = Grid_axis_cal(posy, ly);
	int z = 0;
	if (use_ZO) { z = z_offset; }
	else { z = pos.Z; }
	FVector pos2 = FVector(gridx, gridy, z);
	return pos2;
}

FVector AGameGridBase::Grid_pos_cal_ZO(const FVector& pos, bool use_offset)
{
	int posx = (int)pos.X;
	int posy = (int)pos.Y;
	int gridx = Grid_axis_cal(posx, dx);
	int gridy = Grid_axis_cal(posy, ly);
	int z = 0;
	if (use_offset) { z = z_offset; }
	else { z = 0.0; }
	FVector pos2 = FVector(gridx, gridy, z);
	return pos2;
}

bool AGameGridBase::Spawn_containers(class TSubclassOf<AGridContainer> cont_prefab,
	int _z_offset)
{
	FString cod_str = "";
	AGridContainer* temp_obj = nullptr;
	FVector temp_pos;
	for (int i = 0; i < grid_poses.Num(); ++i)
	{
		temp_pos.X = grid_poses[i].X;
		temp_pos.Y = grid_poses[i].Y;
		cod_str = CoordToString(temp_pos.X, temp_pos.Y);
		temp_pos.Z = _z_offset;
		temp_obj = Spawn_one_conatiner(cont_prefab, &temp_pos);
		container_pool.Add(cod_str, temp_obj);
	}
	return true;
}

bool AGameGridBase::Spawn_containers_bound(class TSubclassOf<AGridContainer> cont_prefab,
	int left_bound, int right_bound, int up_bound, int low_bound, int _z_offset)
{
	FString cod_str = "";
	AGridContainer* temp_obj = nullptr;
	FVector temp_pos;
	for (int i = 0; i < grid_poses.Num(); ++i)
	{
		if (grid_poses[i].X < low_bound || grid_poses[i].X > up_bound ||
			grid_poses[i].Y < left_bound || grid_poses[i].Y > right_bound)
		{
			continue;
		}
		temp_pos.X = grid_poses[i].X;
		temp_pos.Y = grid_poses[i].Y;
		cod_str = CoordToString(temp_pos.X, temp_pos.Y);
		temp_pos.Z = _z_offset;
		temp_obj = Spawn_one_conatiner(cont_prefab, &temp_pos);
		container_pool.Add(cod_str, temp_obj);
		
	}
	return true;
}

bool AGameGridBase::Clear_containers()
{
	for (auto it = container_pool.CreateIterator(); it; ++it)
	{
		it->Value->Destroy();
	}
	container_pool.Empty();
	return true;
}

bool AGameGridBase::Clear_poses()
{
	//for (int i = 0; i < grid_poses.Num(); ++i)
	//{
	//	delete(&grid_poses[i]);
	//}
	grid_poses.Empty();
	return true;
}

FVector AGameGridBase::Get_next_row_pos(const FVector& pos, MapDirection dir)
{
	int r = 0, c = 0;
	Pos_to_rc(pos, r, c);
	r = dir == MapDirection::up ? r + 1 : r - 1;
	if (r >= rows) { return FVector(-1, -1, -1); }
	return Row_col_to_pos(r, c);
}

FVector AGameGridBase::Get_next_col_pos(const FVector& pos, MapDirection dir)
{
	int r = 0, c = 0;
	Pos_to_rc(pos, r, c);
	c = dir == MapDirection::left ? c - 1 : c + 1;
	if (c >= cols) { return FVector(-1, -1, -1); }
	return Row_col_to_pos(r, c);
}

TArray<AGridContainer*> AGameGridBase::Get_row_containers(int r)
{
	TArray<int> pos_indexes = Get_all_indexes_in_row(r);
	TArray<AGridContainer*> res = TArray<AGridContainer*>();
	FString temp_str = "";
	for (int i = 0; i < pos_indexes.Num(); ++i)
	{
		temp_str = CoordToString_pos(grid_poses[pos_indexes[i]]);
		if (container_pool.Contains(temp_str))
		{
			res.Add(container_pool[temp_str]);
		}
	}
	return res;
}

TArray<AGridContainer*> AGameGridBase::Get_next_row_containers(const FVector& pos,
	MapDirection dir)
{
	int r = 0, c = 0;
	Pos_to_rc(pos, r, c);
	r = dir == MapDirection::up ? r + 1 : r - 1;
	TArray<AGridContainer*> res = Get_row_containers(r);
	return res;
}

TArray<FVector>* AGameGridBase::Get_grid_posos()
{
	return &grid_poses;
}

int AGameGridBase::Get_rows()
{
	return rows;
}

int AGameGridBase::Get_cols()
{
	return cols;
}

// Called when the game starts or when spawned
void AGameGridBase::BeginPlay()
{
	Super::BeginPlay();
	
}

int AGameGridBase::Grid_axis_cal(int val, int small_border)
{
	return small_border + Grid_axis_to_rc(val, small_border) * gap;
}

int AGameGridBase::Grid_axis_to_rc(int val, int small_border)
{
	int mult = (val - small_border) / gap;
	int half_gap = gap / 2;
	int remain = (val - small_border) % gap;
	return mult + (remain > half_gap ? 1 : 0);
}

FString AGameGridBase::CoordToString(int x, int y)
{
	std::string res = "";
	res += std::to_string(x);
	res += '_';
	res += std::to_string(y);
	return FString(res.c_str());
}

FString AGameGridBase::CoordToString_pos(FVector pos)
{
	return CoordToString(pos.X, pos.Y);
}

AGridContainer* AGameGridBase::Spawn_one_conatiner(class TSubclassOf<AGridContainer> cont_prefab,
	const FVector* pos)
{
	AGridContainer* temp = (AGridContainer*)(GetWorld()->SpawnActor(cont_prefab, pos));
	temp->AttachToActor(conatiner_parent_ACT, FAttachmentTransformRules::KeepWorldTransform);
	return temp;
}

bool AGameGridBase::Grid_pos_generator()
{
	Clear_poses();
	Grid_row_col_num_cal();
	int gridx = 0, gridy = 0;
	FVector temp;
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			temp = Row_col_to_pos(r, c);
			temp = Grid_pos_cal_ZO(temp, 0.0);
			grid_poses.Add(temp);
		}
	}
	return true;
}

void AGameGridBase::Grid_row_col_num_cal()
{
	rows = (ux - dx) / gap + 1;
	cols = (ry - ly) / gap + 1;
}

FVector AGameGridBase::Row_col_to_pos(int r, int c)
{
	int x = r * gap + dx;
	int y = c * gap + ly;
	return FVector(x, y, 0.0);
}

TArray<int> AGameGridBase::Get_all_indexes_in_row(int r)
{
	int start_i = r * cols;
	TArray<int> res = TArray<int>();
	res.Init(0, cols);
	for (int i = start_i, index = 0; i < start_i + cols; ++i, ++index)
	{
		res[index] = i;
	}
	return res;
}

TArray<int> AGameGridBase::Get_all_indexes_in_col(int c)
{
	int start_i = c;
	TArray<int> res = TArray<int>();
	res.Init(0, rows);
	for (int i = start_i, index = 0; i < rows * cols; i += cols, ++index)
	{
		res[index] = i;
	}
	return res;
}

void AGameGridBase::Pos_to_rc(const FVector& pos, int& r, int& c)
{
	r = Grid_axis_to_rc(pos.X, dx);
	c = Grid_axis_to_rc(pos.Y, ly);
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