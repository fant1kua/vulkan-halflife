/*
* File: vulkanfunctions.h
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#include <vulkan.h>

namespace vkFuncs
{

	#define EXPORTED_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define GLOBAL_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define INSTANCE_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) extern PFN_##name name;
	#define DEVICE_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) extern PFN_##name name;

	#include "vulkanfunctions.inl"
}
