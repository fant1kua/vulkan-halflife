/*
* File: Renderer.cpp
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#include <iostream>
#include "Renderer.h"
#include <Windows.h>

static CRenderer g_Renderer;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CRenderer, IRenderer, RENDERER_INTERFACE_VERSION, g_Renderer);

CRenderer::CRenderer(void)
{
}

CRenderer::~CRenderer(void)
{
	delete this;
}

bool CRenderer::Initialize(CreateInterfaceFn *pFactoryList, int iNumFactories)
{
	return true;
}

void CRenderer::Start(cl_enginefuncs_s *pEngineFuncs, int iInterfaceVersion, IAppSystem *system)
{
	m_pEngineFuncs = pEngineFuncs;
}

void CRenderer::Shutdown(void)
{

}