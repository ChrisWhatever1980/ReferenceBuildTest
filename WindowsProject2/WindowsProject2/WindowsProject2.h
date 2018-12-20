
// WindowsProject2.h: Hauptheaderdatei für die WindowsProject2-Anwendung
//
#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"       // Hauptsymbole


// CWindowsProject2App:
// Siehe WindowsProject2.cpp für die Implementierung dieser Klasse
//

class CWindowsProject2App : public CWinAppEx
{
public:
	CWindowsProject2App();


// Überschreibungen
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

extern CWindowsProject2App theApp;
