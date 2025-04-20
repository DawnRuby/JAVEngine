#pragma once
#include "config.h"

/// <summary>
/// Namespace that handles the creation functions for vulkan
/// </summary>
namespace vkInit {
	vk::Instance make_instance(bool debug, const char* applicationName) {
		if (debug) {
			std::cout << "Creating a new instance\n";
		}

		uint32_t version{ 0 };
		vkEnumerateInstanceVersion(&version);

		if (debug) {
			std::cout << "Using the following vulkan version:"
				<< ", Major: " << VK_API_VERSION_MAJOR(version)
				<< ", Minor: " << VK_API_VERSION_MINOR(version)
				<< ", Patch: " << VK_API_VERSION_PATCH(version)<<"\n";
		}

		///Zeroing out the minimum version patch we need. This makes sure that patches do not influence how we handle which versions we support
		version &= ~(0xFFFU);

		//Drop down to a lower version for now until we have specific features only required in later versions
		version = VK_MAKE_API_VERSION(0, 1, 0, 0);

		vk::ApplicationInfo appInfo = vk::ApplicationInfo(
			applicationName,
			version,
			"0.0.0.1",
			version,
			version
		);

		///Load our required extensions GLFW needs to work with vulkan
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

		if (debug) {
			std::cout << "extensions to be requested are:\n";
			for (const char* extensionName : extensions) {
				std::cout << "\t\"" << extensionName << "\"\n";
			}
		}


		vk::InstanceCreateInfo createInfo = vk::InstanceCreateInfo(
			vk::InstanceCreateFlags(),
			&appInfo,
			0,
			nullptr, // enabled debug layers
			static_cast<uint32_t>(extensions.size()), extensions.data()
		);

		try {
			return vk::createInstance(createInfo, nullptr /* The memory allocator we want to use */ );
		}catch (vk::SystemError err) {
			if (debug) {
				std::cout << "Failed to create a new Vulkan Instance!\n";
			}
		
			return nullptr;
		}
	}
}