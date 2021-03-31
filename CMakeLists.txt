cmake_minimum_required(VERSION 3.17)
project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
find_package(Vulkan REQUIRED FATAL_ERROR)
add_executable(GameEngine src/main.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

if(Vulkan_FOUND)
    target_include_directories(GameEngine PRIVATE Vulkan::Vulkan)
    target_link_libraries(GameEngine Vulkan::Vulkan)
endif()

add_subdirectory(libs/glfw-3.3.3)
target_link_libraries(GameEngine glfw)
include_directories(libs/glfw-3.3.3/include)

add_subdirectory("libs/glm/glm")
target_link_libraries(GameEngine glm)
include_directories("libs/glm")
