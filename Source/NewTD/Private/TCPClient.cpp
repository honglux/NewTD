// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPClient.h"

// Sets default values
ATCPClient::ATCPClient()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATCPClient::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATCPClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATCPClient::ConnectServer()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->
		CreateSocket(NAME_Stream, TEXT("default"), false);
	FIPv4Address::Parse(IPStr, ip);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->
		CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(Port);

	bool connected = Socket->Connect(*addr);

	(new FAutoDeleteAsyncTask<ReceiveThreading>(this, Socket))->StartBackgroundTask();
}

void ATCPClient::SendData(FString data)
{
	if (Socket == nullptr) { return; }
	FString message = FString(TEXT("Unreal client"));
	TCHAR* seriallizedChar = message.GetCharArray().GetData();
	int32 size = FCString::Strlen(seriallizedChar) + 1;
	int32 sent = 0;
	if (Socket->Send((uint8*)TCHAR_TO_UTF8(seriallizedChar), size, sent))
	{
		UE_LOG(LogTemp, Warning, TEXT("___Send Succeed!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("___Send Failed!"));
		return;
	}
}

void ATCPClient::DataReceived_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, receive_message);
}

void ATCPClient::DataReceived_thread(FString message)
{
	receive_message = message;
	DataReceived();
}
