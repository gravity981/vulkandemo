cmake_minimum_required(VERSION 2.8.11)
project (VulkanDemo)

link_directories(C:/VulkanSDK/1.1.73.0/lib32)
link_directories(../libraries/glfw/lib-vc2015)

add_subdirectory(application/Empty)
add_subdirectory(application/HelloTriangle)
