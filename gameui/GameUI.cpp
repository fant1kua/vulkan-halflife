//========= Copyright © 2011-2014, Richard Rohac, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=================================================================================

#include <iostream>
#include "GameUI.h"
#include <Windows.h>

#pragma comment(lib, "opengl32.lib")

static CGameUI g_GameUI;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CGameUI, IGameUI, GAMEUI_INTERFACE_VERSION, g_GameUI);

CGameUI::CGameUI(void)
{
	m_iScreenWidth = 0;
	m_iScreenHeight = 0;
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

	wglMakeCurrent(NULL, NULL);

	return true;
}

void CGameUI::Start(cl_enginefuncs_s *pEngineFuncs, int iInterfaceVersion, IAppSystem *system)
{
	m_pEngineFuncs = pEngineFuncs;
}

void CGameUI::Shutdown(void)
{

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

void CGameUI::GetFrameConfig(void)
{
	/*SCREENINFO *pScreenInfo;

	m_pEngineFuncs->pfnGetScreenInfo(pScreenInfo);
	m_pEngineFuncs->pfnGetMousePos(pMousePOINT);

	m_iScreenWidth = pScreenInfo->iWidth;
	m_iScreenHeight = pScreenInfo->iHeight;

	m_flCursorPosX = pMousePOINT->x;
	m_flCursorPosY = pMousePOINT->y;*/
}