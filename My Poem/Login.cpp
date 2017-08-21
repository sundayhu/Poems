// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "My Poem.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin �Ի���

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin::IDD, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CLogin::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLogin::OnBnClickedButton2)
END_MESSAGE_MAP()


// CLogin ��Ϣ�������


void CLogin::OnBnClickedOk()//��½
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_name);
	GetDlgItem(IDC_EDIT2)->GetWindowText(m_key);

	int i,n,count;
	
	n = theApp.m_Cuser.m_user.size();

	if (m_name.GetLength() == 0)
	{
		MessageBox(_T("�û�������Ϊ�գ�"));
	}
	else
	{
		count = 0;
		for (i = 0; i < n; i++)
		{
			
			if (m_name == theApp.m_Cuser.m_user[i]->m_name.c_str())
			{
				if (m_key == theApp.m_Cuser.m_user[i]->m_key.c_str())//stringתCString
				{
				    theApp.m_name = m_name;//��ǰ�û�
					theApp.F = false;
					CDialogEx::OnOK();
				}
				else
				{
					MessageBox(_T("�������"));
					break;
				}

			}
			else
			{
				count++;
			}
		}
		if (count == n)
		{
			MessageBox(_T("���û������ڣ�"));
		}
	}
}


void CLogin::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CLogin::OnBnClickedButton1()//ע��
{
	
	m_enroll.DoModal();
}


void CLogin::OnBnClickedButton2()//�ο�
{
	theApp.F = true;
	theApp.m_name = "�ο�";
	CDialogEx::OnOK();
}
