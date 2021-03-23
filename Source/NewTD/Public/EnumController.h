// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EnumController.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EnumTest
{
	VE_Dance UMETA(DisplayName = "Dance"),
	VE_Rain UMETA(DisplayName = "Rain"),
	VE_Song UMETA(DisplayName = "Song"),
};

UENUM(BlueprintType)
enum ContainerBuilding_enum
{
	empty UMETA(DisplayName = "Empty"),
	not_buildable UMETA(DisplayName = "Not_buildable"),
	tower UMETA(DisplayName = "Tower"),
	block UMETA(DisplayName = "Block"),
	unavailable UMETA(DisplayName = "Unavailable"),
};

UENUM(BlueprintType)
enum PlayerGroup_enum
{
	group1 UMETA(DisplayName = "Group1"),
	group2 UMETA(DisplayName = "Group2"),
};

UENUM(BlueprintType)
enum MapDirection
{
	up UMETA(DisplayName = "Up"),
	down UMETA(DisplayName = "Down"),
	left UMETA(DisplayName = "Left"),
	right UMETA(DisplayName = "Right"),
};