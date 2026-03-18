// Copyright (c) Howaajin. All rights reserved.
// Licensed under the MIT License. See License in the project root for license information.
// Public API additions by Square Hat Games for RPC bridge integration.

#pragma once

#include "CoreMinimal.h"

class UBlueprint;
class UEdGraph;

/**
 * Public API for the GraphFormatter plugin.
 * Allows external modules (e.g., RPC bridge) to invoke graph formatting programmatically.
 */
class GRAPHFORMATTER_API FGraphFormatterAPI
{
public:
	/**
	 * Format all nodes in a specific graph of a Blueprint.
	 * The Blueprint editor must be open (or will be opened automatically).
	 *
	 * @param Blueprint		The Blueprint asset to format.
	 * @param Graph			The specific graph to format. If nullptr, formats the currently active graph.
	 * @param OutError		Populated with error message on failure.
	 * @return				True if formatting succeeded.
	 */
	static bool FormatGraph(UBlueprint* Blueprint, UEdGraph* Graph, FString& OutError);
};
