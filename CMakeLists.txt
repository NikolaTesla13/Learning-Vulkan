cmake_minimum_required(VERSION 3.16)
project(LearningVulkan)

set(BUILD_SHARED_LIBS true)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

find_package(Vulkan REQUIRED FATAL_ERROR)
add_executable(LearningVulkan src/main.cpp src/application.h src/application.cpp src/vulkan_extensions.h)

if(Vulkan_FOUND)
    target_include_directories(LearningVulkan PRIVATE Vulkan::Vulkan)
    target_link_libraries(LearningVulkan Vulkan::Vulkan)
endif()

add_subdirectory(libs/glfw)
target_link_libraries(LearningVulkan glfw)
include_directories(libs/glfw/include)

add_subdirectory(libs/glm/glm)
target_link_libraries(LearningVulkan glm)
include_directories(libs/glm)
