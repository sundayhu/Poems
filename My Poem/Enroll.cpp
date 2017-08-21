// Enroll.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "My Poem.h"
#include "Enroll.h"
#include "afxdialogex.h"


// CEnroll �Ի���

IMPLEMENT_DYNAMIC(CEnroll, CDialogEx)

CEnroll::CEnroll(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEnroll::IDD, pParent)
{

}

CEnroll::~CEnroll()
{
}

void CEnroll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEnroll, CDialogEx)
	ON_BN_CLICKED(IDOK, &CEnroll::OnBnClickedOk)
	
END_MESSAGE_MAP()


// CEnroll ��Ϣ�������
bool CEnroll::judge()
{
	int n, i;
	n = theApp.m_Cuser.m_user.size();
	for (i = 0; i < n; i++)
	{
		if (m_name == theApp.m_Cuser.m_user[i]->m_name.c_str())
		{
			MessageBox(_T("���û��Ѵ��ڣ�"));
			return false;
		}
	}
	if (m_key1.GetLength() == 0 || m_key2.GetLength() == 0)
	{
		MessageBox(_T("���벻��Ϊ�գ�"));
		return false;
	}
	else
	{

		if (m_key1 != m_key2)
		{
			MessageBox(_T("�����������벻��ͬ��"));
			return false;
		}
		else
		{
			if (m_key1.GetLength() < 5)
			{
				MessageBox(_T("���볤�Ȳ���5��"));
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

void CEnroll::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_name);
	GetDlgItem(IDC_EDIT2)->GetWindowText(m_key1);
	GetDlgItem(IDC_EDIT3)->GetWindowText(m_key2);
	//MessageBox(_T("���볤�Ȳ���5��"));
	if (judge())
	{
		CUser *user=new CUser;
		user->m_name = LPCTOSTRING(m_name.GetBuffer(m_name.GetLength()));
		user->m_key = LPCTOSTRING(m_key1.GetBuffer(m_key1.GetLength()));
		theApp.m_Cuser.m_user.push_back(user);
		theApp.m_Cuser.m_len++;

		CDialogEx::OnOK();
	}
}
string CEnroll::LPCTOSTRING(LPCWSTR pwszSrc)//ת����ʽ
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);

	if (nLen <= 0) return string("");

	char* pszDst = new char[nLen];
	if (NULL == pszDst) return string("");

	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;

	string strTemp(pszDst);
	delete[] pszDst;

	return strTemp;
}


