project(HelloTriangle)

include_directories(${PROJECT_NAME} PUBLIC C:/VulkanSDK/1.1.73.0/Include)
include_directories(${PROJECT_NAME} PUBLIC ../../../libraries/glfw/include)
include_directories(${PROJECT_NAME} PUBLIC ../../../libraries/glm)
include(Sources.cmake)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} vulkan-1 glfw3)

# Scan through resource folder for updated files and copy if none existing or changed
file (GLOB_RECURSE resources "shaders/*.spv")
foreach(resource ${resources})
 get_filename_component(filename ${resource} NAME)
 get_filename_component(dir ${resource} DIRECTORY)
 get_filename_component(dirname ${dir} NAME)
 set(output "${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}")
 add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD 
  COMMENT "Moving updated resource-file '${filename}'"
  COMMAND ${CMAKE_COMMAND} -E copy
  ${resource}
  ${output}
 ) 
endforeach()