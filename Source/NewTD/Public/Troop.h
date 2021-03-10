// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "Troop.generated.h"

/**
 * 
 */
UCLASS()
class NEWTD_API ATroop : public AUnit
{
	GENERATED_BODY()
	
public:
	ATroop();
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float speed;
};
