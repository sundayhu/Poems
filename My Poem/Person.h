#pragma once
#include<windows.h>
#include <atlstr.h>       //��MFC����ʹ��CString������ϸ�ͷ�ļ�
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

// CPerson �Ի���

class CPerson : public CDialogEx
{
	DECLARE_DYNAMIC(CPerson)

public:
	CPerson(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPerson();

// �Ի�������
	enum { IDD = IDD_DIALOG_User };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
