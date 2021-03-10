// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MageTower.h"
#include "FrostMageTower.generated.h"

/**
 * 
 */
UCLASS()
class NEWTD_API AFrostMageTower : public AMageTower
{
	GENERATED_BODY()
	
public:
	AFrostMageTower();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float showRate;
};
