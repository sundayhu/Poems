#pragma once
#include<windows.h>
#include <atlstr.h>       //��MFC����ʹ��CString������ϸ�ͷ�ļ�
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"Enroll.h"

// CLogin �Ի���

class CLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogin();
	CEnroll m_enroll;

// �Ի�������
	enum { IDD = IDD_DIALOG_Login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();

	CString m_name;
	CString m_key;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
