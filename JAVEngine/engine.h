#pragma once
#include <GLFW/glfw3.h>
#include "config.h"


/*
	Certain functions from the lunarg sdk will not be available while statically loading the vulkan lib, 
	so if a function is missing it may be due to it not being available while statically loaded
*/

/// <summary>
/// Class that handles creation of the engine
/// </summary>
class Engine {
public:
	/// <summary>
	/// Entry Handler
	/// </summary>
	Engine();

	/// <summary>
	/// Exit Handler
	/// </summary>
	~Engine();

private:
	/// <summary>
	/// is debug mode active
	/// </summary>
	bool debugMode = true;

	/// <summary>
	/// glfw window width
	/// </summary>
	int width{ 640 };

	/// <summary>
	/// glfw window height
	/// </summary>
	int height{ 480 };

	/// <summary>
	/// window handle
	/// </summary>
	GLFWwindow* window{ nullptr };

	/// <summary>
	/// The Vulkan instance we work with
	/// </summary>
	vk::Instance instance{ nullptr };

	/// <summary>
	/// glfw setup
	/// </summary>
	void build_glfw_window();

	/// <summary>
	/// Creates a new vulkan instance
	/// </summary>
	void make_instance();
};