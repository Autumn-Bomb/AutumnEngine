#include "About.h"

AutumnEngine::About::About() {}
AutumnEngine::About::~About() {}

void AutumnEngine::About::ShowAboutMenu(bool& open)
{
    ImGui::Begin("About");

    ImGui::Text("Engine Name: Autumn Engine");
    ImGui::Text("Engine Version: 0.0.1");
    ImGui::Text("Engine Description: Autumn Engine is a small 2D Game Engine in development by Autumn Bomb LTD");

    ImGui::Separator();

    ImGui::Text("The Team");
    ImGui::Indent();
    ImGui::BulletText("Daniel Martin - Lead Programmer");
    ImGui::BulletText("Aaron Gray - Lead Designer");
    ImGui::Unindent();

    ImGui::Separator();

    if (ImGui::Button("OK", ImVec2(30, 20))) { open = !open; }

    ImGui::End();
}