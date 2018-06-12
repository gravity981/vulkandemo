#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>

class HelloTriangleApplication
{
private:
	struct QueueFamilyIndices {
		int graphicsFamily = -1;

		bool isComplete() {
			return graphicsFamily >= 0;
		}
	};
	const int WIDTH = 800;
	const int HEIGHT = 600;
	GLFWwindow* m_window;
	VkInstance m_instance;
	VkDebugReportCallbackEXT m_debugCallback;
	VkPhysicalDevice m_physicalDevice;
	VkDevice m_device;
	VkQueue m_graphicsQueue;
	VkSurfaceKHR m_surface;

	const std::vector<const char*> m_validationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};

#ifdef NDEBUG
	const bool m_enableValidationLayers = false;
#else
	const bool m_enableValidationLayers = true;
#endif
public:
	HelloTriangleApplication();
	virtual ~HelloTriangleApplication();
	void run();

private:
	void initVulkan();
	void mainLoop();
	void cleanup();

	void createInstance();
	void setupDebugCallback();
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createSurface();

	int rateDeviceSuitability(VkPhysicalDevice device);
	void checkRequiredExtensions(std::vector<const char*>& requiredExtensions);
	void checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	QueueFamilyIndices findRequiredQueueFamilies(VkPhysicalDevice device);
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType,
	                                                    uint64_t obj,
	                                                    size_t location, int32_t code, const char* layerPrefix,
	                                                    const char* msg,
	                                                    void* userData);

	//proxy functions
	VkResult CreateDebugReportCallbackEXT(
		VkInstance instance,
		const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugReportCallbackEXT* pCallback);

	void DestroyDebugReportCallbackEXT(
		VkInstance instance, 
		VkDebugReportCallbackEXT callback, 
		const VkAllocationCallbacks* pAllocator);
};
