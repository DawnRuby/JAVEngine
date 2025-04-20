#include "engine.h"
#include "instance.h"
#include <iostream>

Engine::Engine() {
	if (debugMode) {
		std::cout << "Making a voxel engine\n";
	}

	build_glfw_window();
}

void Engine::build_glfw_window() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	if (window = glfwCreateWindow(width, height, "JAVEngine", nullptr, nullptr)) {
		if (debugMode) {
			std::cout << "Successfully made a glfw window with width: " << width << "and height: " << height << "\n";
		}
	}
	else {
		std::cout << "Failed to create GLFW window\n";
	}

	make_instance();
}

void Engine::make_instance() {
	instance = vkInit::make_instance(debugMode, "JAVEngine");
}

Engine::~Engine() {
	if (debugMode) {
		std::cout << "Goodbye.";
	}

	//Destroy our Vulkan instance. Make sure to reference a different allocator if it was changed from the default one.
	instance.destroy();

	glfwTerminate();
}