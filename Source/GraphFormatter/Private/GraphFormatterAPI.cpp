// Copyright (c) Howaajin. All rights reserved.
// Licensed under the MIT License. See License in the project root for license information.
// Public API additions by Square Hat Games for RPC bridge integration.

#include "GraphFormatterAPI.h"

#include "Formatter.h"
#include "BlueprintEditor.h"
#include "Editor.h"
#include "Engine/Blueprint.h"
#include "EdGraph/EdGraph.h"
#include "Subsystems/AssetEditorSubsystem.h"

bool FGraphFormatterAPI::FormatGraph(UBlueprint* Blueprint, UEdGraph* Graph, FString& OutError)
{
	if (!Blueprint)
	{
		OutError = TEXT("Blueprint is null.");
		return false;
	}

	if (!GEditor)
	{
		OutError = TEXT("GEditor is not available.");
		return false;
	}

	// Ensure the Blueprint editor is open so Slate widgets exist for accurate node sizing.
	UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	if (!AssetEditorSubsystem)
	{
		OutError = TEXT("AssetEditorSubsystem is not available.");
		return false;
	}

	AssetEditorSubsystem->OpenEditorForAsset(Blueprint);
	IAssetEditorInstance* EditorInstance = AssetEditorSubsystem->FindEditorForAsset(Blueprint, false);
	if (!EditorInstance)
	{
		OutError = TEXT("Failed to open or find Blueprint editor.");
		return false;
	}

	// If a specific graph was requested, switch to it in the editor.
	if (Graph)
	{
		FBlueprintEditor* BlueprintEditor = static_cast<FBlueprintEditor*>(EditorInstance);
		if (BlueprintEditor)
		{
			BlueprintEditor->OpenGraphAndBringToFront(Graph);
		}
	}

	// Find the SGraphEditor widget.
	FFormatter& Formatter = FFormatter::Instance();
	SGraphEditor* Editor = Formatter.FindGraphEditorForTopLevelWindow();
	if (!Editor)
	{
		Editor = Formatter.FindGraphEditorByCursor();
	}
	if (!Editor)
	{
		OutError = TEXT("Could not find SGraphEditor widget. Is the graph tab visible?");
		return false;
	}

	// Ensure the panel is updated so node widgets are available.
	SGraphPanel* Panel = Editor->GetGraphPanel();
	if (Panel)
	{
		Panel->Update();
	}

	// Set context and run format.
	Formatter.SetCurrentEditor(Editor, Blueprint);
	Formatter.Format();

	return true;
}
