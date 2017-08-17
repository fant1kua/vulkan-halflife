/*
 * File: IRenderer.h
 *
 * Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
 *
 */

#ifndef IRENDERER_H
#define IRENDERER_H
#ifdef _WIN32
#pragma once
#endif

#include "interface.h"
#include "IAppSystem.h"

class IAppSystem;

class IRenderer : public IBaseInterface
{
public:
	// virtual destructor from IBaseInterface

	virtual bool Initialize(CreateInterfaceFn *factoryList, int numFactories) = 0;
	
	virtual void Start(struct cl_enginefuncs_s *enginefuncs, int interfaceVersion, IAppSystem *system) = 0;
	
	virtual void Shutdown() = 0;
};

#define RENDERER_INTERFACE_VERSION "Renderer017"

#endif