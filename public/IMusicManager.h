//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#ifndef IMUSICMANAGER_H
#define IMUSICMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "interface.h"

#define MUSICMANAGER_NOT_LOOPING 0
#define MUSICMANAGER_LOOPING 1

//-----------------------------------------------------------------------------
// Purpose: ???
//-----------------------------------------------------------------------------
class IMusicManager : public IBaseInterface
{
public:
	// virtual destructor from IBaseInterface

	// param1 must be one of [2, 3, 4, 5, 6, 7]
	// param2 is "looping" if non-zero
	virtual void	StartTrack(int track, char looping) = 0;

	virtual void	StopTrack() = 0;

	virtual void	FadeoutTrack() = 0;

	virtual bool	IsPlayingTrack(int track) = 0;

	// Returns whether current track is number 1 ???
	virtual bool	Unknown1() = 0;
};

#endif
