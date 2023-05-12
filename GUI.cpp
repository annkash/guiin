#include "GUI.hpp"

void UserInterface::Update()
{   

    ImGui::SetNextWindowPos(ImVec2(360, 120), ImGuiCond_Once, ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(500, 80), ImGuiCond_Once);

    ImGui::Begin("Hello, user!");                        
    ImGui::Text("Here you can create 2 triangles and find their intersection.");         

    static bool show_settings1_window = false;
    static bool show_settings2_window = false;

    if (ImGui::Button("Add triangles"))
        {
            show_settings1_window = true;
            show_settings2_window = true;
        }
    if (show_settings1_window)
    {
        ImGui::SetNextWindowPos(ImVec2(50, 200), ImGuiCond_Once, ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(200, 300), ImGuiCond_Once);

        ImGui::Begin("Settings1", &show_settings1_window);
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
        draw_list->AddTriangleFilled(tr1.point1, tr1.point2, tr1.point3, tr1.color);
        ImGui::Text("Coordinates:");
        ImGui::Spacing();

        ImGui::SeparatorText("1st point");
        ImGui::SliderFloat("x1", &tr1.point1.x, 0, width);
        ImGui::SliderFloat("y1", &tr1.point1.y, 0, height);

        ImGui::SeparatorText("2nd point");
        ImGui::SliderFloat("x2", &tr1.point2.x, 0, width);
        ImGui::SliderFloat("y2", &tr1.point2.y, 0, height);

        ImGui::SeparatorText("3rd point");
        ImGui::SliderFloat("x3", &tr1.point3.x, 0, width);
        ImGui::SliderFloat("y3", &tr1.point3.y, 0, height);

        ImGui::End();
    };

    if (show_settings2_window)
    {
        tr2.color = ImColor(255, 0, 0);
        ImGui::SetNextWindowPos(ImVec2(1000, 200), ImGuiCond_Once, ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(200, 300), ImGuiCond_Once);

        ImGui::Begin("Settings2", &show_settings2_window);
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); 
        draw_list->AddTriangleFilled(tr2.point1, tr2.point2, tr2.point3, tr2.color);
        ImGui::Text("Coordinates:");
        ImGui::Spacing();

        ImGui::SeparatorText("1st point");
        ImGui::SliderFloat("x1", &tr2.point1.x, 0, width);
        ImGui::SliderFloat("y1", &tr2.point1.y, 0, height);

        ImGui::SeparatorText("2nd point");
        ImGui::SliderFloat("x2", &tr2.point2.x, 0, width);
        ImGui::SliderFloat("y2", &tr2.point2.y, 0, height);

        ImGui::SeparatorText("3rd point");
        ImGui::SliderFloat("x3", &tr2.point3.x, 0, width);
        ImGui::SliderFloat("y3", &tr2.point3.y, 0, height);

        ImGui::End();
    }

    ImGui::End();
    
};