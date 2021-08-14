//
// Created by Stefan on 08/13/2021.
//
#pragma once

class Application {
public:
    void run();

private:
    GLFWwindow* window;

    const uint32_t WIDTH = 1080;
    const uint32_t HEIGHT = 720;

    const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                        VkDebugUtilsMessageTypeFlagBitsEXT messageType,
                                        VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData);

    void createInstance();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void pickPhysicalDevice();
    static bool isDeviceSuitable(VkPhysicalDevice device);

    void setupDebugMessenger();
};