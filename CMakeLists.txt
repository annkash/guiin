cmake_minimum_required(VERSION 3.16)

project(GUI_input)

set(CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_subdirectory(glfw)

#adding imgui
set(IMGUI_INCLUDE_DIR imgui)

file(GLOB IMGUI_SOURCES imgui/*.cpp)
file(GLOB IMGUI_HEADERS imgui/*.h)

set(IMGUI_BACKENDS_DIR imgui/backends)
set(IMGUI_BACKEND_SOURCES
    ${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp
    ${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp)
set(IMGUI_BACKEND_HEADERS
    ${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.h
    ${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.h)

add_library(imgui STATIC
    ${IMGUI_SOURCES} ${IMGUI_HEADERS}
    ${IMGUI_BACKEND_HEADERS} ${IMGUI_BACKEND_SOURCES})

set(GLFW_INCLUDE_DIR glfw/include/GLFW)
set(GLAD_INCLUDE_DIR glfw/deps/glad)

target_include_directories(imgui PUBLIC
    ${IMGUI_INCLUDE_DIR}
    ${IMGUI_BACKENDS_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${GLAD_INCLUDE_DIR})

target_link_libraries(imgui
    ${OPENGL_LIBRARIES}
    glfw
)

#adding glad
file(GLOB GLAD_HEADERS glad/include/glad/glad.h glad/include/KHR/khrplatform.h)
file(GLOB GLAD_SOURCES glad/src/glad.c)

add_library(glad STATIC ${GLAD_SOURCES} ${GLAD_HEADERS})

set(GLAD_INCLUDE_DIR_ANOTHER glad/include)

target_include_directories(glad PUBLIC ${GLAD_INCLUDE_DIR_ANOTHER})

target_link_libraries(glad
    ${OPENGL_LIBRARIES}
)

add_executable(main main.cpp)

target_link_libraries(main ${OPENGL_LIBRARIES} glfw imgui glad)