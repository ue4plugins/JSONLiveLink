// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ILiveLinkSource.h"
#include "MessageEndpoint.h"
#include "IMessageContext.h"
#include "ThreadSafeBool.h"

#include "Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include <memory>

class ILiveLinkClient;

class JSONLIVELINK_API FJSONLiveLinkSource : public ILiveLinkSource, public FRunnable
{
public:

	FJSONLiveLinkSource();

	virtual ~FJSONLiveLinkSource();

	// Begin ILiveLinkSource Interface
	
	virtual void ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid) override;

	virtual bool IsSourceStillValid() override;

	virtual bool RequestSourceShutdown() override;

	virtual FText GetSourceType() const override { return SourceType; };
	virtual FText GetSourceMachineName() const override { return SourceMachineName; }
	virtual FText GetSourceStatus() const override { return SourceStatus; }

	// End ILiveLinkSource Interface

	// Begin FRunnable Interface

	virtual bool Init() override { return true; }
	virtual uint32 Run() override;
	void Start();
	virtual void Stop() override;
	virtual void Exit() override { }

	// End FRunnable Interface

	void HandleReceivedData(TSharedPtr<TArray<uint8>, ESPMode::ThreadSafe> ReceivedData);

private:

	ILiveLinkClient* Client;

	// Our identifier in LiveLink
	FGuid SourceGuid;

	FMessageAddress ConnectionAddress;

	FText SourceType;
	FText SourceMachineName;
	FText SourceStatus;
	
	FIPv4Address DeviceIPAddr;
	uint32 DevicePort;
	
	// Socket to receive data on
	FSocket* Socket;
	
	// Subsystem associated to Socket
	ISocketSubsystem* SocketSubsystem;
	
	// Threadsafe Bool for terminating the main thread loop
	FThreadSafeBool Stopping;
	
	// Thread to run socket operations on
	FRunnableThread* Thread;
	
	// Name of the sockets thread
	FString ThreadName;
	
	// Time to wait between attempted receives
	FTimespan WaitTime;

	// List of subjects we've already encountered
	TSet<FName> EncounteredSubjects;

	// Buffer to receive socket data into
	TArray<uint8> RecvBuffer;
	
	// frame counter for data
	int FrameCounter;
};
