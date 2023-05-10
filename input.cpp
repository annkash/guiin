#include "input.hpp"

void input_app::Update()
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
        static ImVec2 point1_1 = ImVec2(50, 100);
        static ImVec2 point2_1 = ImVec2(100, 50);
        static ImVec2 point3_1 = ImVec2(150, 100);
        static ImColor color1 = ImColor(0, 0, 255);
        ImGui::SetNextWindowPos(ImVec2(50, 200), ImGuiCond_Once, ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(200, 300), ImGuiCond_Once);

        ImGui::Begin("Settings1", &show_settings1_window);
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
        draw_list->AddTriangleFilled(point1_1, point2_1, point3_1, color1);
        ImGui::Text("Coordinates:");
        ImGui::Spacing();

        ImGui::SeparatorText("1st point");
        ImGui::SliderFloat("x1", &point1_1.x, 0, width);
        ImGui::SliderFloat("y1", &point1_1.y, 0, height);

        ImGui::SeparatorText("2nd point");
        ImGui::SliderFloat("x2", &point2_1.x, 0, width);
        ImGui::SliderFloat("y2", &point2_1.y, 0, height);

        ImGui::SeparatorText("3rd point");
        ImGui::SliderFloat("x3", &point3_1.x, 0, width);
        ImGui::SliderFloat("y3", &point3_1.y, 0, height);

        if (ImGui::Button("Save changes"))
        {
            tr1.color = color1;
            tr1.point1 = point1_1;
            tr1.point2 = point2_1;
            tr1.point3 = point3_1;
        }

        ImGui::End();
    };

    if (show_settings2_window)
    {
        static ImVec2 point1_2 = ImVec2(50, 100);
        static ImVec2 point2_2 = ImVec2(100, 50);
        static ImVec2 point3_2 = ImVec2(150, 100);
        static ImColor color2 = ImColor(255, 0, 0);
        ImGui::SetNextWindowPos(ImVec2(1000, 200), ImGuiCond_Once, ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(200, 300), ImGuiCond_Once);

        ImGui::Begin("Settings2", &show_settings2_window);
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); 
        draw_list->AddTriangleFilled(point1_2, point2_2, point3_2, color2);
        ImGui::Text("Coordinates:");
        ImGui::Spacing();

        ImGui::SeparatorText("1st point");
        ImGui::SliderFloat("x1", &point1_2.x, 0, width);
        ImGui::SliderFloat("y1", &point1_2.y, 0, height);

        ImGui::SeparatorText("2nd point");
        ImGui::SliderFloat("x2", &point2_2.x, 0, width);
        ImGui::SliderFloat("y2", &point2_2.y, 0, height);

        ImGui::SeparatorText("3rd point");
        ImGui::SliderFloat("x3", &point3_2.x, 0, width);
        ImGui::SliderFloat("y3", &point3_2.y, 0, height);

        if (ImGui::Button("Save changes"))
        {
            tr2.color = color2;
            tr2.point1 = point1_2;
            tr2.point2 = point2_2;
            tr2.point3 = point3_2;
        }

        ImGui::End();
    }
    ImGui::End();
    
};