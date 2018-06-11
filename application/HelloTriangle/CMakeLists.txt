project(HelloTriangle)

include_directories(${PROJECT_NAME} PUBLIC C:/VulkanSDK/1.1.73.0/Include)
include_directories(${PROJECT_NAME} PUBLIC ../../../libraries/glfw/include)
include_directories(${PROJECT_NAME} PUBLIC ../../../libraries/glm)
include(Sources.cmake)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glfw3 vulkan-1)
