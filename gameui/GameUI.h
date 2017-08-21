//========= Copyright © 2011-2014, Richard Rohac, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=================================================================================

#pragma once
#ifndef __GAMEUI_H__
#define __GAMEUI_H__

class CGameUI : public IGameUI
{
public:
	CGameUI(void);
	~CGameUI(void);

	bool Initialize(CreateInterfaceFn *pFactoryList, int iNumFactories);
	void Start(cl_enginefuncs_s *pEngineFuncs, int iInterfaceVersion, IAppSystem *system);
	void Shutdown(void);

	int ActivateGameUI(void);
	void ActivateDemoUI(void);
	bool HasExclusiveInput(void);
	void RunFrame(void);
	void ConnectToServer(const char *pszGame, int iIP, int iPort);
	void DisconnectFromServer(void);
	void HideGameUI(void);
	bool IsGameUIActive(void);
	void LoadingStarted(const char *resourceType, const char *resourceName);
	void LoadingFinished(const char *resourceType, const char *resourceName);
	void StartProgressBar(const char *progressType, int numProgressPoints);
	int ContinueProgressBar(int progressPoint, float progressFraction);
	void StopProgressBar(bool bError, const char *failureReasonIfAny, const char *extendedReason);
	int SetProgressBarStatusText(const char *statusText);

	void Unknown1(void *u1);
	void Unknown2(void *u1);
	void Unknown3(void *u1, void *u2);
	void Unknown4(void *u1, void *u2);

private:
	void LoadLibRenderer(CreateInterfaceFn *factoryList, int numFactories);
	void FreeLibRenderer(void);

	CreateInterfaceFn *m_pFactoryList;
	int m_iNumFactories;

	HINTERFACEMODULE m_hRendererModule;
	IRenderer *m_pRenderer;

	cl_enginefunc_t m_engineFuncs;
};

#endif