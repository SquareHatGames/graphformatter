/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Howaajin. All rights reserved.
 *  Licensed under the MIT License. See License in the project root for license information.
 *--------------------------------------------------------------------------------------------*/

namespace UnrealBuildTool.Rules
{
	using System.IO;

	public class GraphFormatter : ModuleRules
	{
		public GraphFormatter(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
            PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));
            PrivateIncludePaths.Add(ModuleDirectory);

            PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
				}
			);

            PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"ApplicationCore",
					"InputCore",
					"Kismet",
					"UnrealEd",
					"SlateCore",
					"Slate",
					"EditorStyle",
					"GraphEditor",
					"BlueprintGraph",
					"MaterialEditor",
					"AIModule",
					"AIGraph",
					"BehaviorTreeEditor",
				}
			);
		}
	}
}
