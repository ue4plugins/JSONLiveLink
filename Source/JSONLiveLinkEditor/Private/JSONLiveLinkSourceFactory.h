// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LiveLinkSourceFactory.h"
#include "JSONLiveLinkSourceFactory.generated.h"

class SJSONLiveLinkSourceEditor;

UCLASS()
class UJSONLiveLinkSourceFactory : public ULiveLinkSourceFactory
{
public:

	GENERATED_BODY()

	virtual FText GetSourceDisplayName() const;
	virtual FText GetSourceTooltip() const;

	virtual TSharedPtr<SWidget> CreateSourceCreationPanel();
	virtual TSharedPtr<ILiveLinkSource> OnSourceCreationPanelClosed(bool bMakeSource);

	TSharedPtr<SJSONLiveLinkSourceEditor> ActiveSourceEditor;	
};