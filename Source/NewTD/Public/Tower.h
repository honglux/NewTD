// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class NEWTD_API ATower : public AUnit
{
	GENERATED_BODY()

public:
	ATower();
protected:
	float defense;

};
