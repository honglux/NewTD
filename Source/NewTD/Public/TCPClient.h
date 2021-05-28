// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Networking.h"
#include "Sockets.h"

#include "GameFramework/Actor.h"
#include "TCPClient.generated.h"

static bool TCP_thread = false;

UCLASS()
class NEWTD_API ATCPClient : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
		FString IPStr;
	UPROPERTY(EditAnywhere)
		int Port;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString receive_message;

	FIPv4Address ip;
	FSocket* Socket;
	bool received_trigger;

	// Sets default values for this actor's properties
	ATCPClient();

	UFUNCTION(BlueprintCallable)
		void ConnectServer();

	UFUNCTION(BlueprintCallable)
		void SendData(FString data);

	UFUNCTION(BlueprintNativeEvent)
		void DataReceived();

	UFUNCTION(BlueprintCallable)
		void StopThread();

	void DataReceived_thread(FString message);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

class ReceiveThreading : public FNonAbandonableTask
{

public:
	FSocket* Socket;
	ATCPClient* Client;

	/*Default constructor*/
	ReceiveThreading(ATCPClient* _client, FSocket* _socket)
	{
		this->Client = _client;
		this->Socket = _socket;
	}

	/*This function is needed from the API of the engine.
	My guess is that it provides necessary information
	about the thread that we occupy and the progress of our task*/
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(PrimeCalculationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

	/*This function is executed when we tell our task to execute*/
	void DoWork()
	{
		TArray<uint8> ReceiveData;
		uint8 element = 0;
		while (TCP_thread && Socket != NULL)
		{
			ReceiveData.Init(element, 1024u);
			int32 read = 0;
			Socket->Recv(ReceiveData.GetData(), ReceiveData.Num(), read);
			const FString ReceivedUE4String = 
				FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(ReceiveData.GetData())));
			Client->DataReceived_thread(ReceivedUE4String);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ReceivedUE4String);

			FPlatformProcess::Sleep(0.01f);
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Thread stopped"));
	}
};