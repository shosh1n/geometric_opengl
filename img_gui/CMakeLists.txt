cmake_minimum_required(VERSION 3.22)
project(imgui_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
# Include directories for GLFW and ImGui
include_directories(
  ${PROJECT_SOURCE_DIR}/lib/imgui
  /home/shoshin/Downloads/download_gl/glfw-3.3.8/include
)

find_package(OpenGL REQUIRED)

add_subdirectory("${PROJECT_SOURCE_DIR}/lib/glfw-3.3.8")

set(IMGUI_HEADERS
  ${PROJECT_SOURCE_DIR}/lib/imgui/imgui.h
  ${PROJECT_SOURCE_DIR}/lib/imgui/backends/imgui_impl_opengl3.h
  ${PROJECT_SOURCE_DIR}/lib/imgui/backends/imgui_impl_glfw.h
)
set(IMGUI_SOURCES
  ${PROJECT_SOURCE_DIR}/lib/imgui/imgui.cpp
  ${PROJECT_SOURCE_DIR}/lib/imgui/backends/imgui_impl_opengl3.cpp
  ${PROJECT_SOURCE_DIR}/lib/imgui/backends/imgui_impl_glfw.cpp
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/lib/imgui/imgui_draw.cpp
  ${PROJECT_SOURCE_DIR}/lib/imgui/imgui_tables.cpp
  ${PROJECT_SOURCE_DIR}/lib/imgui/imgui_demo.cpp
  ${PROJECT_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp
)

add_executable(MyIMGUI ${IMGUI_HEADERS} ${IMGUI_SOURCES})

target_link_libraries(MyIMGUI PRIVATE
  /home/shoshin/Downloads/build_glfw/src/Release/libglfw.so
  OpenGL::GL
)

target_include_directories(MyIMGUI PRIVATE
  ${PROJECT_SOURCE_DIR}/lib/imgui
)

