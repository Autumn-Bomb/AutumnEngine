#include "About.h"

AutumnEngine::About::About() {}
AutumnEngine::About::~About() {}

void AutumnEngine::About::ShowAboutMenu(bool& open)
{
    ImGui::Begin("About");

    ImGui::Text("Name: Autumn Engine");
    ImGui::Text("Version: 1.0.0");
    ImGui::Text("Description: Autumn Engine is a small 2D Game Engine in development by Autumn Bomb LTD");

    ImGui::Separator();

    ImGui::Text("The Team");
    ImGui::Indent();
    ImGui::BulletText("Daniel Martin - Lead Programmer");
    ImGui::BulletText("Aaron Gray - Lead Designer");
    ImGui::Unindent();

    if (ImGui::Button("Exit", ImVec2(150, 50))) { open = !open; }

    ImGui::End();
}