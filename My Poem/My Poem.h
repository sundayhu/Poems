
// My Poem.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once
#include<windows.h>
#include <atlstr.h>       //非MFC程序使用CString，请加上该头文件
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"User.h"
#include"Control_poem.h"
#include"Poem.h"

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include"Login.h"

// CMyPoemApp: 
// 有关此类的实现，请参阅 My Poem.cpp
//

class CMyPoemApp : public CWinApp
{
public:
	CMyPoemApp();
	CLogin lo;

// 重写
public:
	virtual BOOL InitInstance();

// 实现
	CControl_user m_Cuser;
	CControl_poem m_Cpoem;
	CString m_name;//当前用户
	CString m_poem;//当前诗
	bool F;//游客身份

	DECLARE_MESSAGE_MAP()
};

extern CMyPoemApp theApp;