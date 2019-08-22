// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "JSONLiveLinkSourceFactory.h"
#include "JSONLiveLinkSource.h"
#include "JSONLiveLinkSourceEditor.h"

#include "ILiveLinkClient.h"
#include "Features/IModularFeatures.h"

#define LOCTEXT_NAMESPACE "JSONLiveLinkSourceFactory"

FText UJSONLiveLinkSourceFactory::GetSourceDisplayName() const
{
	return LOCTEXT("SourceDisplayName", "JSON LiveLink");
}

FText UJSONLiveLinkSourceFactory::GetSourceTooltip() const
{
	return LOCTEXT("SourceTooltip", "Creates a connection to a JSON UDP Stream");
}

TSharedPtr<SWidget> UJSONLiveLinkSourceFactory::CreateSourceCreationPanel()
{
	if (!ActiveSourceEditor.IsValid())
	{
		SAssignNew(ActiveSourceEditor, SJSONLiveLinkSourceEditor);
	}
	return ActiveSourceEditor;
}

TSharedPtr<ILiveLinkSource> UJSONLiveLinkSourceFactory::OnSourceCreationPanelClosed(bool bMakeSource)
{
	//Clean up
	TSharedPtr<FJSONLiveLinkSource> NewSource = nullptr;

	if (bMakeSource && ActiveSourceEditor.IsValid())
	{
		NewSource = MakeShared<FJSONLiveLinkSource>();
	}

	ActiveSourceEditor = nullptr;
	return NewSource;
}
#undef LOCTEXT_NAMESPACE