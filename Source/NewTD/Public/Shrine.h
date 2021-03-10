// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "Shrine.generated.h"

/**
 * 
 */
UCLASS()
class NEWTD_API AShrine : public ATower
{
	GENERATED_BODY()
	
public:
	AShrine();
private:
	bool adPower;
};
