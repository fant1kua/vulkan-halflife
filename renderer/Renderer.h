/*
* File: Renderer.h
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "IRenderer.h"
#include <../cl_dll/wrect.h>
#include <../cl_dll/cl_dll.h>

class CRenderer : public IRenderer
{
public:
	CRenderer(void);
	~CRenderer(void);

	bool Initialize(CreateInterfaceFn *pFactoryList, int iNumFactories);
	void Start(cl_enginefuncs_s *pEngineFuncs, int iInterfaceVersion, IAppSystem *system);
	void Shutdown(void);

private:
	cl_enginefunc_t *m_pEngineFuncs;
};

#endif