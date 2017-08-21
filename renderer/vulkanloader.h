/*
* File: vulkanloader.h
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#pragma once
#ifndef __VULKANLOADER_H__
#define __VULKANLOADER_H__

#include "windows_common.h"

#ifdef WIN32
#define VULKAN_LIBRARY "vulkan-1.dll"
#endif

using namespace vkFuncs;

class CVulkanLoader
{
public:
	CVulkanLoader()
	{
#ifdef WIN32
		m_hVulkanLib = LoadLibrary(VULKAN_LIBRARY);
		if (m_hVulkanLib == nullptr)
			Sys_FatalError("Could not load vulkan library!");

		#define EXPORTED_VULKAN_FUNCTION( name )						 \
		name = (PFN_##name)GetProcAddress								 \
			(m_hVulkanLib, #name);										 \
		if (name == nullptr)											 \
			Sys_FatalError("Could not load %s from vk library!", #name); \
		
		#include "vulkanfunctions.inl"
#endif
	}

	~CVulkanLoader()
	{
#ifdef WIN32
		if (m_hVulkanLib)
			FreeLibrary(m_hVulkanLib);
#endif
	}

private:

#ifdef WIN32
	HMODULE m_hVulkanLib;
#endif WIN32
};

#endif