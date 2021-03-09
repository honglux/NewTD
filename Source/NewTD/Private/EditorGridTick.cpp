// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorGridTick.h"
#include <string>

using namespace std;

// Sets default values
AEditorGridTick::AEditorGridTick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

bool AEditorGridTick::ShouldTickIfViewportsOnly() const
{
	return true;
}

// Called when the game starts or when spawned
void AEditorGridTick::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEditorGridTick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	EditorGridTickEvent();
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
	//		TEXT("Some debug message!"));
	//}
}

void AEditorGridTick::EditorGridTickEvent_Implementation()
{
}



//void AEditorGridTick::print_test()
//{
//
//		
//}

//void AEditorGridTick::print_test()
//{
//	if (GEngine)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
//			TEXT("Some debug message!"));
//	}
//}