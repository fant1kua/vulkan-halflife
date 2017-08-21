/*
* File: windows_common.h
*
* Copyright (c) Richard Rohac, 2011 - 2017, All rights reserved.
*
*/

#pragma once
#ifndef __WINDOWS_COMMON_H__
#define __WINDOWS_COMMON_H__

#ifdef _WIN32

#define NTDDI_VERSION		0x06010000 // Win7
#define _WIN32_WINNT		0x0601
#define WINVER				0x0601
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

inline void Sys_FatalError(char *pszFormat, ...) {
	char szBuffer[512];
	va_list argList;

	va_start(argList, pszFormat);
	vsprintf_s(szBuffer, pszFormat, argList);

	MessageBox(NULL, szBuffer, "Sys_FatalError()", MB_OK | MB_ICONERROR | MB_SETFOREGROUND);

	va_end(argList);
	exit(-1);
}

#endif

#endif