// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JSONLiveLink : ModuleRules
{
	public JSONLiveLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"JSONLiveLink/Public"
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"JSONLiveLink/Private",
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "Networking",
                "Sockets",
                "LiveLinkInterface"
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Json",
                "JsonUtilities"
            }
			);
	}
}
