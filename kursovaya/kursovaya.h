
// kursovaya.h : главный файл заголовка для приложения kursovaya
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CkursovayaApp:
// О реализации данного класса см. kursovaya.cpp
//

class CkursovayaApp : public CWinAppEx
{
public:
	CkursovayaApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CkursovayaApp theApp;
