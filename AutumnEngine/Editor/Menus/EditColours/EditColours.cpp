#include "EditColours.h"

AutumnEngine::EditEditorColoursMenu::EditEditorColoursMenu() {}
AutumnEngine::EditEditorColoursMenu::~EditEditorColoursMenu() {}

<<<<<<< Updated upstream
void AutumnEngine::EditEditorColoursMenu::ShowEditColoursMenu(AutumnEngine::Style& style)
{
	ImGui::Begin("Edit Editor Colours");
	ImGui::Text("Use this menu to change the colours of the main editor");
	ImGui::Separator();
=======
void AutumnEngine::EditEditorColoursMenu::ShowEditColoursMenu()
{
	ImGui::Begin("Edit Editor Colours");

>>>>>>> Stashed changes
	ImGui::End();
}