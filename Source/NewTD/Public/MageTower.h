// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "MageTower.generated.h"

/**
 * 
 */
UCLASS()
class NEWTD_API AMageTower : public ATower
{
	GENERATED_BODY()
	
public:
	AMageTower();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString magePower;
};
