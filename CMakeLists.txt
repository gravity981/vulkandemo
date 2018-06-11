cmake_minimum_required(VERSION 2.8.11)
project (VULKAN_DEMO)

set(PROJECT_NAME vulkan_demo)

link_directories(C:/VulkanSDK/1.1.73.0/lib32)
link_directories(../libraries/glfw/lib-vc2015)

include_directories(${PROJECT_NAME} PUBLIC C:/VulkanSDK/1.1.73.0/Include)
include_directories(${PROJECT_NAME} PUBLIC ../libraries/glfw/include)
include_directories(${PROJECT_NAME} PUBLIC ../libraries/glm)

add_executable(${PROJECT_NAME} source/main.cpp)
target_link_libraries(${PROJECT_NAME} glfw3 vulkan-1)

