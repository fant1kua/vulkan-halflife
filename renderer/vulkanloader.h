/*
* File: vulkanloader.h
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#pragma once
#ifndef __VULKANLOADER_H__
#define __VULKANLOADER_H__

#include <vector>
#include "windows_common.h"

#ifdef WIN32
#define VULKAN_LIBRARY "vulkan-1.dll"
#endif

#define VK_ENGINE_NAME	"vkGoldSrc2017"
#define VK_APP_NAME		"HalfLifeModification"

using namespace vkFuncs;

typedef void (*vulkan_print) (char*, ...);

class CVulkanLoader
{
public:
	CVulkanLoader(vulkan_print printFunc) :
#ifdef WIN32
		m_vDesiredExtensions(
			{VK_KHR_SURFACE_EXTENSION_NAME})
#endif
	{
		m_pPrintf = printFunc;
		
		loadLibrary();
		loadGlobalFunctions();
		loadInstanceFunctions();

		instanceGetExtensions();
		instanceCreate();
	}

	~CVulkanLoader()
	{
#ifdef WIN32
		if (m_hVulkanLib)
			FreeLibrary(m_hVulkanLib);
#endif
	}

private:
	void loadLibrary(void)
	{
#ifdef WIN32
		m_hVulkanLib = LoadLibrary(VULKAN_LIBRARY);
		if (m_hVulkanLib == nullptr)
			Sys_FatalError("Could not load vulkan library!");

		#define EXPORTED_VULKAN_FUNCTION( name )						 \
		name = (PFN_##name)GetProcAddress								 \
			(m_hVulkanLib, #name);										 \
		if (name == nullptr)											 \
			Sys_FatalError("Could not load %s from vk library!", #name);
#endif
	
		#include "vulkanfunctions.inl"
	}

	void loadGlobalFunctions(void)
	{
#ifdef WIN32
		#define GLOBAL_LEVEL_VULKAN_FUNCTION( name )					 \
		name = (PFN_##name)vkGetInstanceProcAddr(nullptr, #name);		 \
		if (name == nullptr)											 \
			Sys_FatalError("Could not load %s from vk library!", #name);
#endif

		#include "vulkanfunctions.inl"
	}

	void loadInstanceFunctions(void)
	{
#ifdef WIN32
		#define INSTANCE_LEVEL_VULKAN_FUNCTION( name )					\
		name = (PFN_##name)vkGetInstanceProcAddr(m_vkInstance, #name);  \
		if (name == nullptr)											\
			Sys_FatalError("Could not load %s from vk library!", #name);
#endif
		#include "vulkanfunctions.inl"
	}

	void instanceGetExtensions(void)
	{
		uint32_t count;
		VkResult result = VK_SUCCESS;

		result = vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr);
		if (result != VK_SUCCESS || count == 0)
			Sys_FatalError("Could not get number of vk instance extensions!");

		m_vInstanceExtensions.resize(count);
		result = vkEnumerateInstanceExtensionProperties(nullptr, &count, &m_vInstanceExtensions[0]);
		if (result != VK_SUCCESS || count == 0)
			Sys_FatalError("Could not get vk instance extensions!");

#ifdef DEBUG
		m_pPrintf("\n\n=== VULKAN INSTANCE EXTENSIONS: ===\n");
		for (unsigned int i = 0; i < m_vInstanceExtensions.size(); i++)
		{
			m_pPrintf("%s\n", m_vInstanceExtensions[i].extensionName);
		}
		m_pPrintf("=== === === === === === ===\n\n");
#endif
	};

	void instanceCreate(void)
	{
		VkResult result = VK_SUCCESS;

		for (auto &desExt : m_vDesiredExtensions)
		{
			bool bFound = false;
			for (auto &curExt : m_vInstanceExtensions)
			{
				if (!strncmp(curExt.extensionName, desExt, 32))
				{
					bFound = true;
					break;
				}
			}

			if (!bFound)
				Sys_FatalError("%s not supported!", desExt);
		}

		VkApplicationInfo appInfo;
		appInfo.sType				= VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext				= nullptr;
		appInfo.pApplicationName	= VK_APP_NAME;
		appInfo.applicationVersion	= VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName			= VK_ENGINE_NAME;
		appInfo.engineVersion		= VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion			= VK_MAKE_VERSION(1, 0, 0);

		VkInstanceCreateInfo createInfo;
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pNext = nullptr;
		createInfo.flags = 0;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = nullptr;
		createInfo.enabledExtensionCount = 
			static_cast<uint32_t>(m_vDesiredExtensions.size());
		createInfo.ppEnabledExtensionNames =
			(m_vDesiredExtensions.size()>0)?&m_vDesiredExtensions[0]:nullptr;

		result = vkCreateInstance(&createInfo, nullptr, &m_vkInstance);
		if (result != VK_SUCCESS || m_vkInstance == VK_NULL_HANDLE)
			Sys_FatalError("Could not create vk instance!");
	};

#ifdef WIN32
	HMODULE m_hVulkanLib;
#endif WIN32

	vulkan_print m_pPrintf;
	std::vector<VkExtensionProperties> m_vInstanceExtensions;
	std::vector<char const *> m_vDesiredExtensions;
	VkInstance	m_vkInstance;
};

#endif