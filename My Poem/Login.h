#pragma once
#include<windows.h>
#include <atlstr.h>       //非MFC程序使用CString，请加上该头文件
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"Enroll.h"

// CLogin 对话框

class CLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogin();
	CEnroll m_enroll;

// 对话框数据
	enum { IDD = IDD_DIALOG_Login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();

	CString m_name;
	CString m_key;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
