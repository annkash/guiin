#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <glad/glad.h>
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "2Triangles", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
   
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hello, user!");                        
        ImGui::Text("Here you can create 2 triangles and find their intersection.");         

        static bool show_settings1_window = false;
        static bool show_settings2_window = false;
        static int width, height;
        glfwGetWindowSize(window, &width, &height);

        if (ImGui::Button("Add triangles"))
            {
                show_settings1_window = true;
                show_settings2_window = true;
            }
        if (show_settings1_window){
            ////1triangle
            static ImVec2 point1_1 = ImVec2(50, 100);
            static ImVec2 point2_1 = ImVec2(100, 50);
            static ImVec2 point3_1 = ImVec2(150, 100);
            
            ImGui::Begin("Settings1", &show_settings1_window);
            ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); 
            draw_list->AddTriangleFilled(point1_1, point2_1, point3_1, ImColor(255, 0, 0));
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
            
            if (ImGui::Button("confirm"))
                {
                    std::ofstream out;    
                    out.open("../data1triangle.txt");      
                    if (out.is_open())
                    {
                        //1 triangle input
                        out <<  point1_1.x << std::endl;
                        out <<  point1_1.y << std::endl;
                        out <<  point2_1.x << std::endl;
                        out <<  point2_1.y << std::endl;
                        out <<  point3_1.x << std::endl;
                        out <<  point3_1.y << std::endl;
                    }
                    out.close(); 
                }
            ImGui::End();
        }

        if (show_settings2_window){
            ////2triangle
            static ImVec2 point1_2 = ImVec2(50, 100);
            static ImVec2 point2_2 = ImVec2(100, 50);
            static ImVec2 point3_2 = ImVec2(150, 100);
            ImGui::Begin("Settings2", &show_settings2_window);
            ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); 
            draw_list->AddTriangleFilled(point1_2, point2_2, point3_2, ImColor(0, 0, 255));
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

            if (ImGui::Button("confirm"))
                {
                    std::ofstream out;    
                    out.open("../data2triangle.txt");      
                    if (out.is_open())
                    {
                        //2 triangle input
                        out <<  point1_2.x << std::endl;
                        out <<  point1_2.y << std::endl;
                        out <<  point2_2.x << std::endl;
                        out <<  point2_2.y << std::endl;
                        out <<  point3_2.x << std::endl;
                        out <<  point3_2.y << std::endl;
                    }
                    out.close(); 
                }

            ImGui::End();
        }
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}