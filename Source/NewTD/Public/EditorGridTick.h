// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EditorGridTick.generated.h"

UCLASS()
class NEWTD_API AEditorGridTick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEditorGridTick();
	int i = 0;
	virtual bool ShouldTickIfViewportsOnly() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void print_test();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EditorGridTickEvent();
};
