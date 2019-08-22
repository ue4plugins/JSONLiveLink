// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;

public class JSONLiveLinkEditor : ModuleRules
{
    public JSONLiveLinkEditor(ReadOnlyTargetRules Target) : base(Target)
    {
		// TODO: Clean up dependencies
		
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PrivateIncludePaths.AddRange(
            new string[] {
                "JSONLiveLinkEditor/Private",
            }
            );
            
        
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "UnrealEd",
                "Engine",
                "Projects",
                "DetailCustomizations",
				"JSONLiveLink",
				"LiveLinkInterface",
				"BlueprintGraph"
            }
            );
            
        
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "WorkspaceMenuStructure",
                "EditorStyle",
                "SlateCore",
                "Slate",
                "InputCore"
			}
            );
    }
}
