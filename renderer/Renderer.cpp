/*
* File: Renderer.cpp
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#include <iostream>
#include "vulkanfunctions.h"
#include "vulkanloader.h"
#include "Renderer.h"
#include <Windows.h>

static CRenderer g_Renderer;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CRenderer, IRenderer, RENDERER_INTERFACE_VERSION, g_Renderer);

CRenderer::CRenderer(void)
{
	m_pVulkanLdr = NULL;
}

CRenderer::~CRenderer(void)
{
	if (m_pVulkanLdr != NULL) {
		delete m_pVulkanLdr;
		m_pVulkanLdr = NULL;
	}
	delete this;
}

bool CRenderer::Initialize(CreateInterfaceFn *pFactoryList, int iNumFactories)
{
	return true;
}

void CRenderer::Start(cl_enginefuncs_s *pEngineFuncs, int iInterfaceVersion, IAppSystem *system)
{
	m_engineFuncs = *pEngineFuncs;

	if (iInterfaceVersion != CLDLL_INTERFACE_VERSION)
		Sys_FatalError("Incompatible client library with renderer library!");

	memcpy(&m_engineFuncs, pEngineFuncs, sizeof(cl_enginefunc_t));

	m_pVulkanLdr = new CVulkanLoader(m_engineFuncs.Con_Printf);
}

void CRenderer::Shutdown(void)
{

}