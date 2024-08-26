project(owngl)

set(CMAKE_CXX_STANDARD 14)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenCV REQUIRED)

set(CPLUS_INCLUDE_PATH "/usr/include/c++/11:/usr/include/x86_64-linux-gnu/c++/11")

include_directories(
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui
  /home/shoshin/space/__aux/glew/include
  /home/shoshin/Downloads/download_gl/glfw-3.3.8/include
  ${PROJECT_SOURCE_DIR}/src
)

set(IMGUI_HEADERS
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/imgui.h
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/backends/imgui_impl_opengl3.h
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/backends/imgui_impl_glfw.h
  ${PROJECT_SOURCE_DIR}/src/opengl_shader.h
  ${PROJECT_SOURCE_DIR}/src/file_manager.h
)

set(IMGUI_SOURCES
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/imgui.cpp
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/backends/imgui_impl_opengl3.cpp
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/backends/imgui_impl_glfw.cpp
  ${PROJECT_SOURCE_DIR}/src/opengl_shader.cpp
  ${PROJECT_SOURCE_DIR}/src/file_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/imgui_draw.cpp
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/imgui_tables.cpp
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/imgui_demo.cpp
  ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui/imgui_widgets.cpp
)

add_executable(OWNGL
  ${IMGUI_HEADERS}
  ${IMGUI_SOURCES}
  ${PROJECT_SOURCE_DIR}/src/base-shader.vs
  ${PROJECT_SOURCE_DIR}/src/base-cross.vs
  ${PROJECT_SOURCE_DIR}/src/base-shader.fs)

add_custom_command(TARGET OWNGL
  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/src/base-shader.vs ${PROJECT_BINARY_DIR}
  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/src/base-shader.fs ${PROJECT_BINARY_DIR}
  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/src/base-cross.vs ${PROJECT_BINARY_DIR})

target_link_libraries(OWNGL ~/space/__aux/glew-2.1.0/build/build_glew/build_glew/lib/Release/libGLEW.so /home/shoshin/Downloads/build_glfw/src/Release/libglfw.so GL)

target_include_directories(OWNGL PRIVATE ${PROJECT_SOURCE_DIR}/../img_gui/lib/imgui)
