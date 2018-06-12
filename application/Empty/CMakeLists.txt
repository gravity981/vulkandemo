project(Empty)

include_directories(${PROJECT_NAME} PUBLIC C:/VulkanSDK/1.1.73.0/Include)
include_directories(${PROJECT_NAME} PUBLIC ../../../libraries/glfw/include)
include_directories(${PROJECT_NAME} PUBLIC ../../../libraries/glm)
include(Sources.cmake)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} vulkan-1 glfw3)
