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
		int presentFamily = -1;

		bool isComplete() {
			return graphicsFamily >= 0 && presentFamily >= 0;
		}
	};
	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const size_t MAX_FRAMES_IN_FLIGHT = 2;
	GLFWwindow* m_window;
	VkInstance m_instance;
	VkDebugReportCallbackEXT m_debugCallback;
	VkPhysicalDevice m_physicalDevice;
	VkDevice m_device;
	VkQueue m_graphicsQueue;
	VkSurfaceKHR m_surface;
	VkQueue m_presentQueue;
	VkSwapchainKHR m_swapChain;
	std::vector<VkImage> m_swapChainImages;
	VkFormat m_swapChainImageFormat;
	VkExtent2D m_swapChainExtent;
	std::vector<VkImageView> m_swapChainImageViews;
	VkShaderModule m_vertShaderModule;
	VkShaderModule m_fragShaderModule;
	VkPipelineLayout m_pipelineLayout;
	VkRenderPass m_renderPass;
	VkPipeline m_graphicsPipeline;
	std::vector<VkFramebuffer> m_swapChainFramebuffers;
	VkCommandPool m_commandPool;
	std::vector<VkCommandBuffer> m_commandBuffers;
	std::vector<VkSemaphore> m_imageAvailableSemaphores;
	std::vector<VkSemaphore> m_renderFinishedSemaphores;
	std::vector<VkFence> m_inFlightFences;
	size_t m_currentFrame = 0;

	const std::vector<const char*> m_validationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};

	const std::vector<const char*> m_deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
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

	void drawFrame();

	void createInstance();
	void setupDebugCallback();
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createSurface();
	void createSwapChain();
	void createImageViews();
	void createGraphicsPipeline();
	void createRenderPass();
	void createFrameBuffers();
	void createCommandPool();
	void createCommandBuffers();
	void createSyncObjects();

	int rateDeviceSuitability(VkPhysicalDevice device);
	void checkRequiredInstanceExtensions(std::vector<const char*>& requiredExtensions);
	void checkValidationLayerSupport();
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	std::vector<const char*> getRequiredInstanceExtensions();
	QueueFamilyIndices findRequiredQueueFamilies(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	VkShaderModule createShaderModule(const std::vector<char>& code);

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

	static std::vector<char> readFile(const std::string& filename);
};
