
// My PoemDlg.h : ͷ�ļ�
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
#include"Poem.h"
#include"Control_poem.h"
#include"Person.h"
#include "afxcmn.h"

// CMyPoemDlg �Ի���
class CMyPoemDlg : public CDialogEx
{
// ����
public:
	CMyPoemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYPOEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnLbnSelchangeList1();
	CTreeCtrl m_list;
	HTREEITEM hItem;
	HTREEITEM hSubItem;
	void inittree();
	void inittree2();
	string LPCTOSTRING(LPCWSTR pwszSrc);//CString תstring
	CString cstr1, cstr2, cstr3,cstr;
	bool flag;
	afx_msg void OnClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton11();
};
