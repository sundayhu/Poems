#pragma once
#include<windows.h>
#include <atlstr.h>       //非MFC程序使用CString，请加上该头文件
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"User.h"

// CEnroll 对话框

class CEnroll : public CDialogEx
{
	DECLARE_DYNAMIC(CEnroll)

public:
	CEnroll(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEnroll();

// 对话框数据
	enum { IDD = IDD_DIALOG_Enroll };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	
	CString m_name;
	CString m_key1;
	CString m_key2;
	bool judge();//判定注册用户
	string LPCTOSTRING(LPCWSTR pwszSrc);//CString 转string

};
