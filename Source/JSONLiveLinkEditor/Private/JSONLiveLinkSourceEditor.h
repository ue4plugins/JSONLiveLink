// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "SListView.h"
#include "IMessageContext.h"
#include "MessageEndpoint.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Guid.h"

class SJSONLiveLinkSourceEditor : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SJSONLiveLinkSourceEditor)
	{
	}

	SLATE_END_ARGS()
	
	SJSONLiveLinkSourceEditor()
	{
		PortNumber = 54321;
	};

	~SJSONLiveLinkSourceEditor();

	void Construct(const FArguments& Args);

private:
	TOptional<uint32> PortNumber;
	
	TOptional<uint32> GetPort() const
	{ 
		return PortNumber; 
	};
	
	void OnPortChanged(uint32 InPortNumber)
	{
		PortNumber = InPortNumber;
	};
};