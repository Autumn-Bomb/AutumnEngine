#include "Fuse.h"

AutumnEngine::Fuse::Fuse() {}
AutumnEngine::Fuse::~Fuse() {}

void AutumnEngine::Fuse::CreateWindow(const char* ID, bool* open, ImGuiWindowFlags flags)
{
	ImGui::Begin(ID, open, flags);
}

void AutumnEngine::Fuse::EndWindow()
{
	ImGui::End();
}

void AutumnEngine::Fuse::AddButton(const char* label, ImVec2 size, bool sameLine = false)
{
	if (!sameLine)
	{
		ImGui::Button(label, size);
	}
	else
	{
		ImGui::SameLine();
		ImGui::Button(label, size);
	}
}

void AutumnEngine::Fuse::AddText(const char* text, bool sameLine)
{
	if (!sameLine)
	{
		ImGui::Text(text);
	}
	else
	{
		ImGui::SameLine();
		ImGui::Text(text);
	}
}

void AutumnEngine::Fuse::AddSeperator()
{
	ImGui::Separator();
}