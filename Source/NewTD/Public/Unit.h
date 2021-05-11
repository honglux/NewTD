// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumController.h"
#include "GameFramework/Pawn.h"
#include "Unit.generated.h"

UCLASS()
class NEWTD_API AUnit : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUnit();

	FString getType() { return type; }
	void setType(FString t) { type = t; }
	float getHealth() { return health;}
	void setHealth(float h) { health = h; }
	float getDamage() { return damage; }
	void setDamage(float d) { damage = d; }
	float getAttackInterval() { return attack_interval; }
	void setAttackInterval(float a) { attack_interval = a; }
	int getCost() { return cost; }
	void setCost(int c) { cost = c; }
	int getRange() { return range; }
	void setRange(int r) { range = r; }
	FVector getLocation() { return location; }
	void setLocation(FVector l) { location = l; }
	AUnit* getTarget() { return this->target; }
	void setTarget(AUnit* tar) { target = tar; }

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<PlayerGroup_enum> player_group;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ContainerBuilding_enum> building_state;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString type;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float attack_interval;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float range;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int cost;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector location;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AUnit* target;

	float time;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Attcking(AUnit* target);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
