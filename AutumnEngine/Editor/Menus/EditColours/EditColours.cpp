#include "EditColours.h"

AutumnEngine::EditEditorColoursMenu::EditEditorColoursMenu() {}
AutumnEngine::EditEditorColoursMenu::~EditEditorColoursMenu() {}

void AutumnEngine::EditEditorColoursMenu::ShowEditColoursMenu(AutumnEngine::Style& style)
{
	ImGui::Begin("Edit Editor Colours");
	ImGui::Text("Use this menu to change the colours of the main editor");
	ImGui::Separator();
	ImGui::End();
}