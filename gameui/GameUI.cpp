//========= Copyright © 2011-2014, Richard Rohac, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=================================================================================

#include <iostream>
#include "interface.h"
#include "IGameUI.h"
#include "IRenderer.h"
#include <../cl_dll/wrect.h>
#include <../cl_dll/cl_dll.h>
#include "GameUI.h"
#include "windows_common.h"

#pragma comment(lib, "opengl32.lib")

static CGameUI g_GameUI;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CGameUI, IGameUI, GAMEUI_INTERFACE_VERSION, g_GameUI);

CGameUI::CGameUI(void)
{
	m_hRendererModule = NULL;
	m_pRenderer = NULL;
	m_pFactoryList = NULL;
	m_iNumFactories = 0;

	memset(&m_engineFuncs, 0, sizeof(cl_enginefunc_t));
}

CGameUI::~CGameUI(void)
{
}

bool CGameUI::Initialize(CreateInterfaceFn *pFactoryList, int iNumFactories)
{
	// factorylist[0] -> hw.dll
	// factorylist[1] -> vgui2.dll
	// factorylist[2] -> FileSystem_Steam.dll
	// factoryList[3] -> GameUI.dll

	m_pFactoryList = pFactoryList;
	m_iNumFactories = iNumFactories;

	return true;
}

void CGameUI::Start(cl_enginefuncs_s *pEngineFuncs, int iInterfaceVersion, IAppSystem *system)
{
	m_engineFuncs = *pEngineFuncs;

	if (iInterfaceVersion != CLDLL_INTERFACE_VERSION)
		Sys_FatalError("Incompatible client library with GameUI library!");

	memcpy(&m_engineFuncs, pEngineFuncs, sizeof(cl_enginefunc_t));

	LoadLibRenderer(m_pFactoryList, m_iNumFactories);

	wglMakeCurrent(NULL, NULL);
	m_pRenderer->Start(pEngineFuncs, iInterfaceVersion, system);
}

void CGameUI::Shutdown(void)
{
	FreeLibRenderer();
}

int CGameUI::ActivateGameUI(void)
{
	return true;
}

void CGameUI::ActivateDemoUI(void)
{

}

bool CGameUI::HasExclusiveInput(void)
{
	return true;
}

void CGameUI::RunFrame(void)
{
}

void CGameUI::ConnectToServer(const char *pszGame, int iIP, int iPort)
{

}

void CGameUI::DisconnectFromServer(void)
{

}

void CGameUI::HideGameUI(void)
{

}

bool CGameUI::IsGameUIActive(void)
{
	return true;
}

void CGameUI::LoadingStarted(const char *resourceType, const char *resourceName)
{

}

void CGameUI::LoadingFinished(const char *resourceType, const char *resourceName)
{

}

void CGameUI::StartProgressBar(const char *progressType, int numProgressPoints)
{

}

int CGameUI::ContinueProgressBar(int progressPoint, float progressFraction)
{
	return 0;
}

void CGameUI::StopProgressBar(bool bError, const char *failureReasonIfAny, const char *extendedReason)
{

}

int CGameUI::SetProgressBarStatusText(const char *statusText)
{
	return true;
}

void CGameUI::Unknown1(void *u1)
{

}

void CGameUI::Unknown2(void *u1)
{

}

void CGameUI::Unknown3(void *u1, void *u2)
{

}

void CGameUI::Unknown4(void *u1, void *u2)
{

}

void CGameUI::LoadLibRenderer(CreateInterfaceFn *factoryList, int numFactories)
{
	char szPDir[512];

	if (!m_engineFuncs.COM_ExpandFilename(RENDERER_DLLNAME, szPDir, sizeof(szPDir)))
		Sys_FatalError("Could not load renderer library!");

	m_hRendererModule = Sys_LoadModule(szPDir);

	CreateInterfaceFn rendererFactory = Sys_GetFactory(m_hRendererModule);
	if (!rendererFactory)
		Sys_FatalError("Could not load factory from renderer library!");

	m_pRenderer = (IRenderer *)rendererFactory(RENDERER_INTERFACE_VERSION, NULL);
	if (!m_pRenderer)
		Sys_FatalError("Incorrect renderer library version detected!");

	if (!m_pRenderer->Initialize(factoryList, numFactories))
		Sys_FatalError("Could not initialize renderer library");
}

void CGameUI::FreeLibRenderer(void)
{
	if (m_pRenderer && m_hRendererModule) 
	{
		Sys_FreeModule(m_hRendererModule);
		m_hRendererModule = 0;
		m_pRenderer = NULL;
	}
}