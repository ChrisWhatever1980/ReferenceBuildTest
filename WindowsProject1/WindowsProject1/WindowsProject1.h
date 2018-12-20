
// WindowsProject1.h: Hauptheaderdatei f�r die WindowsProject1-Anwendung
//
#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei f�r PCH einschlie�en"
#endif

#include "resource.h"       // Hauptsymbole


// CWindowsProject1App:
// Siehe WindowsProject1.cpp f�r die Implementierung dieser Klasse
//

class CWindowsProject1App : public CWinAppEx
{
public:
	CWindowsProject1App();


// �berschreibungen
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementierung
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWindowsProject1App theApp;
