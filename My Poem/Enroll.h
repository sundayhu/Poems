#pragma once
#include<windows.h>
#include <atlstr.h>       //��MFC����ʹ��CString������ϸ�ͷ�ļ�
#include <fstream> 
#include "string"
#include "CString"
using namespace std;
#include"Control_user.h"
#include"User.h"

// CEnroll �Ի���

class CEnroll : public CDialogEx
{
	DECLARE_DYNAMIC(CEnroll)

public:
	CEnroll(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEnroll();

// �Ի�������
	enum { IDD = IDD_DIALOG_Enroll };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	
	CString m_name;
	CString m_key1;
	CString m_key2;
	bool judge();//�ж�ע���û�
	string LPCTOSTRING(LPCWSTR pwszSrc);//CString תstring

};
