// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridContainer.h"

#include "GameGridBase.generated.h"

UCLASS()
class NEWTD_API AGameGridBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int z_offset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int dx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int ux;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int ly;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int ry;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int gap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool use_ZO;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector> grid_poses;	//x and y poses, z set to 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int rows;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int cols;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FString, AGridContainer*> container_pool;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		AActor* conatiner_parent_ACT;

	/// <summary>
	/// Generate grid_poses from dx, ux ...
	/// </summary>
	UFUNCTION(BlueprintCallable)
		bool Grid_pos_generator();
	/// <summary>
	/// Calculate the total row and col numbers.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		void Grid_row_col_num_cal();

	virtual int Grid_axis_cal(int val, int small_border);
	virtual int Grid_axis_to_rc(int val, int small_border);
	virtual FString CoordToString(int x, int y);
	virtual FString CoordToString_pos(FVector pos);
	virtual AGridContainer* Spawn_one_conatiner(class TSubclassOf<AGridContainer> cont_prefab,
		const FVector* pos);



public:
	// Sets default values for this actor's properties
	AGameGridBase();

	/// <summary>
	/// Assign the variables;
	/// </summary>
	UFUNCTION(BlueprintCallable)
		bool InitGrid(int _z_offset, int _ly, int _ry, int _dx, int _ux, int _gap,
			bool _use_ZO);

	/// <summary>
	/// Transfer a position to nearest grid position.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual FVector Grid_pos_cal(const FVector& pos);
	/// <summary>
	/// Grid_pos_cal with z offset.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual FVector Grid_pos_cal_ZO(const FVector& pos, bool use_offset);
	/// <summary>
	/// Implement in the blueprint.
	/// </summary>
	UFUNCTION(BlueprintImplementableEvent)
		FVector Editor_grid_pos_cal(const FVector& pos);
	/// <summary>
	/// Spawn containers from prefab class.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual bool Spawn_containers(class TSubclassOf<AGridContainer> cont_prefab, 
			int _z_offset);
	/// <summary>
	/// Spawn containers with boundaries.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual bool Spawn_containers_bound(class TSubclassOf<AGridContainer> cont_prefab,
			int left_bound, int right_bound, int up_bound, int low_bound, int _z_offset);
	/// <summary>
	/// Clear the container_pool and destroy the actors.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual bool Clear_containers();
	/// <summary>
	/// Clear grid_poses;
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual bool Clear_poses();
	/// <summary>
	/// Get next row position from current position.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual FVector Get_next_row_pos(const FVector& pos, MapDirection dir);
	/// <summary>
	/// Get next row position from current position.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		virtual FVector Get_next_col_pos(const FVector& pos, MapDirection dir);
	/// <summary>
	/// Calculate the current position to the nearest row can col indexes.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		void Pos_to_rc(const FVector& pos, int& r, int & c);
	/// <summary>
	/// Get grid position from row col indexes, No z position;
	/// </summary>
	UFUNCTION(BlueprintCallable)
		FVector Row_col_to_pos(int r, int c);
	/// <summary>
	/// Get all grid_poses indexes from given row.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		TArray<int> Get_all_indexes_in_row(int r);
	/// <summary>
	/// Get all grid_poses indexes from given col.
	/// </summary>
	UFUNCTION(BlueprintCallable)
		TArray<int> Get_all_indexes_in_col(int c);
	/// <summary>
	/// Get all containers in current row.
	/// </summary>
	/// <returns></returns>
	UFUNCTION(BlueprintCallable)
		TArray<AGridContainer*> Get_row_containers(int r);
	/// <summary>
	/// Get all containers in next row with current position.
	/// </summary>
	/// <returns></returns>
	UFUNCTION(BlueprintCallable)
		TArray<AGridContainer*> Get_next_row_containers(const FVector& pos, MapDirection dir);

	TArray<FVector>* Get_grid_posos();
	int Get_rows();
	int Get_cols();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
