//========= Copyright © 2011-2014, Richard Rohac, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=================================================================================

#pragma once
#ifndef __GAMECONSOLE_H__
#define __GAMECONSOLE_H__

#include "IGameConsole.h"

class CGameConsole : public IGameConsole
{
	void Activate(void);
	void Initialize(void);
	void Hide(void);
	void Clear(void);
	bool IsConsoleVisible(void);
	void Printf(const char *pszFormat, ...);
	void DPrintf(const char *pszFormat, ...);
	void SetParent(VPANEL pParent);
};

#define GAMEUI_INTERFACE_VERSION "GameUI007"

#endif