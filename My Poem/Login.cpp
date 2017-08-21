// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "My Poem.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin 对话框

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


// CLogin 消息处理程序


void CLogin::OnBnClickedOk()//登陆
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_name);
	GetDlgItem(IDC_EDIT2)->GetWindowText(m_key);

	int i,n,count;
	
	n = theApp.m_Cuser.m_user.size();

	if (m_name.GetLength() == 0)
	{
		MessageBox(_T("用户名不能为空！"));
	}
	else
	{
		count = 0;
		for (i = 0; i < n; i++)
		{
			
			if (m_name == theApp.m_Cuser.m_user[i]->m_name.c_str())
			{
				if (m_key == theApp.m_Cuser.m_user[i]->m_key.c_str())//string转CString
				{
				    theApp.m_name = m_name;//当前用户
					theApp.F = false;
					CDialogEx::OnOK();
				}
				else
				{
					MessageBox(_T("密码错误！"));
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
			MessageBox(_T("该用户不存在！"));
		}
	}
}


void CLogin::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CLogin::OnBnClickedButton1()//注册
{
	
	m_enroll.DoModal();
}


void CLogin::OnBnClickedButton2()//游客
{
	theApp.F = true;
	theApp.m_name = "游客";
	CDialogEx::OnOK();
}
