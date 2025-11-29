// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CakeWalk : ModuleRules
{
	public CakeWalk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks", "NavigationSystem" /*, "AIModule" */, "GameplayAbilities", "Niagara"});

        PublicIncludePaths.AddRange(new string[] {
			"CakeWalk",
			"CakeWalk/Variant_Platforming",
			"CakeWalk/Variant_Platforming/Animation",
			"CakeWalk/Variant_Combat",
			"CakeWalk/Variant_Combat/AI",
			"CakeWalk/Variant_Combat/Animation",
			"CakeWalk/Variant_Combat/Gameplay",
			"CakeWalk/Variant_Combat/Interfaces",
			"CakeWalk/Variant_Combat/UI",
			"CakeWalk/Variant_SideScrolling",
			"CakeWalk/Variant_SideScrolling/AI",
			"CakeWalk/Variant_SideScrolling/Gameplay",
			"CakeWalk/Variant_SideScrolling/Interfaces",
			"CakeWalk/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
