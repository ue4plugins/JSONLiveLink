// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "JSONLiveLinkSourceEditor.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Input/SNumericEntryBox.h"

#define LOCTEXT_NAMESPACE "JSONLiveLinkSourceEditor"

SJSONLiveLinkSourceEditor::~SJSONLiveLinkSourceEditor()
{
}

void SJSONLiveLinkSourceEditor::Construct(const FArguments& Args)
{
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(250)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				.FillWidth(0.5f)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("JSONPortNumber", "Port Number"))
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.FillWidth(0.5f)
				[
					SNew(SNumericEntryBox<uint32>)
					.Value(this, &SJSONLiveLinkSourceEditor::GetPort)
					.OnValueChanged(this, &SJSONLiveLinkSourceEditor::OnPortChanged)
				]
			]
		]
	];
}

#undef LOCTEXT_NAMESPACE