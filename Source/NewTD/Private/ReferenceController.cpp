// Fill out your copyright notice in the Description page of Project Settings.


#include "ReferenceController.h"

// Sets default values
AReferenceController::AReferenceController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

AReferenceController* AReferenceController::IS = nullptr;

AReferenceController* AReferenceController::Get_RC_Instance()
{
	return IS;
}

void AReferenceController::Set_Instance(AReferenceController* OBJ)
{
	IS = OBJ;
}
