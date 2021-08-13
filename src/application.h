//
// Created by Stefan on 08/13/2021.
//
#pragma once

const uint32_t WIDTH = 1080;
const uint32_t HEIGHT = 720;

class Application {
public:
    void run();

private:
    GLFWwindow* window;

    VkInstance instance;

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    void createInstance();
};