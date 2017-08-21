#pragma once
#include<windows.h>
#include <atlstr.h>       //非MFC程序使用CString，请加上该头文件
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"User.h"
#include"Poem.h"
#include"Control_poem.h"
#include "afxcmn.h"
#include <sstream>
#include "afxwin.h"

// CPerson 对话框

class CPerson : public CDialogEx
{
	DECLARE_DYNAMIC(CPerson)

public:
	CPerson(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPerson();

// 对话框数据
	enum { IDD = IDD_DIALOG_User };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CTreeCtrl m_list;
	HTREEITEM hItem;
	HTREEITEM hSubItem;
	bool flag;
	afx_msg void OnClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
};
