// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReferenceController.generated.h"

UCLASS()
class NEWTD_API AReferenceController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReferenceController();

	static AReferenceController* IS;

	UFUNCTION(BlueprintCallable)
	static AReferenceController* Get_RC_Instance();

protected:
	UFUNCTION(BlueprintCallable)
	virtual void Set_Instance(AReferenceController* OBJ);

};
