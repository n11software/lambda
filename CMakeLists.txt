cmake_minimum_required(VERSION 3.13)
project(Lambda)
set(CMAKE_CXX_STANDARD 17)

set(ENGINE_SOURCES
	engine/main.cpp
	engine/graphics/stb-image.h
	engine/graphics/Window.h
	engine/graphics/Window.cpp
)

add_library(
	public
	public/mathlib/vec2.cpp
	public/mathlib/vec2.h
)

add_subdirectory(thirdparty/GLFW)

include_directories(${OPENGL_INCLUDE_DIR})

add_executable(Lambda ${ENGINE_SOURCES})

target_include_directories(Lambda PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/GLFW/include)
target_include_directories(Lambda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public)
target_link_libraries(Lambda glfw)
target_link_libraries(Lambda public)

find_package(OpenGL REQUIRED)

target_link_libraries(Lambda OpenGL::GL)