
// My Poem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once
#include<windows.h>
#include <atlstr.h>       //��MFC����ʹ��CString������ϸ�ͷ�ļ�
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"User.h"
#include"Control_poem.h"
#include"Poem.h"

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include"Login.h"

// CMyPoemApp: 
// �йش����ʵ�֣������ My Poem.cpp
//

class CMyPoemApp : public CWinApp
{
public:
	CMyPoemApp();
	CLogin lo;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	CControl_user m_Cuser;
	CControl_poem m_Cpoem;
	CString m_name;//��ǰ�û�
	CString m_poem;//��ǰʫ
	bool F;//�ο����

	DECLARE_MESSAGE_MAP()
};

extern CMyPoemApp theApp;