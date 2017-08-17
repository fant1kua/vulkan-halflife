//========= Copyright © 2011-2014, Richard Rohac, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=================================================================================

#include "GameConsole.h"

static CGameConsole g_GameConsole;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CGameConsole, IGameConsole, GAMECONSOLE_INTERFACE_VERSION, g_GameConsole);

void CGameConsole::Activate(void)
{

}

void CGameConsole::Initialize(void)
{

}

void CGameConsole::Hide(void)
{

}

void CGameConsole::Clear(void)
{

}

bool CGameConsole::IsConsoleVisible(void)
{
	return true;
}

void CGameConsole::Printf(const char *pszFormat, ...)
{

}

void CGameConsole::DPrintf(const char *pszFormat, ...)
{

}

void CGameConsole::SetParent(VPANEL pParent)
{

}