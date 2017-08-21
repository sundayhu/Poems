// Person.cpp : 实现文件
//

#include "stdafx.h"
#include "My Poem.h"
#include "Person.h"
#include "afxdialogex.h"


// CPerson 对话框

IMPLEMENT_DYNAMIC(CPerson, CDialogEx)

CPerson::CPerson(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPerson::IDD, pParent)
{

}

CPerson::~CPerson()
{
}

void CPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_list);
}


BEGIN_MESSAGE_MAP(CPerson, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPerson::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CPerson::OnClickTree1)
	ON_BN_CLICKED(IDC_BUTTON5, &CPerson::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CPerson::OnBnClickedButton3)
END_MESSAGE_MAP()


// CPerson 消息处理程序
BOOL CPerson::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化代码
	GetDlgItem(IDC_EDIT2)->SetWindowText(theApp.m_name);
	flag = false;
	stringstream ss;
	string str;
	CString cstr;
	vector<CUser*>::iterator it = theApp.m_Cuser.m_user.begin();
	while (it != theApp.m_Cuser.m_user.end())
	{
		if ((*it)->m_name.c_str() == theApp.m_name)
		{
			ss.clear();//
			ss.str("");//重新初始化
			ss << (*it)->c_len;
			ss >> str;
			cstr = str.c_str();
			GetDlgItem(IDC_EDIT3)->SetWindowText(cstr);
			ss.clear();//
			ss.str("");//重新初始化
			ss << (*it)->s_len;
			ss >> str;
			cstr = str.c_str();
			GetDlgItem(IDC_EDIT4)->SetWindowText(cstr);
			break;
		}
		it++;
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPerson::OnBnClickedButton1()//添加列表
{
	m_list.DeleteAllItems();
	int i;
	CString cstr;
	vector<CUser*>::iterator it = theApp.m_Cuser.m_user.begin();
	while (it != theApp.m_Cuser.m_user.end())
	{
		if ((*it)->m_name.c_str() == theApp.m_name)
		{
			hItem = m_list.InsertItem(_T("收藏列表"), TVI_ROOT);//添加根节点
			for (i = 0; i < (*it)->c_len; i++)
			{
				cstr = (*it)->m_collect[i].c_str();
				hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//添加孩子节点
			}
			hItem = m_list.InsertItem(_T("学习记录"), TVI_ROOT);//添加根节点
			for (i = 0; i < (*it)->s_len; i++)
			{
				cstr = (*it)->m_studyed[i].c_str();
				hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//添加孩子节点
			}
			break;
		}
		it++;
	}
}


void CPerson::OnClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int i, j, k;
	CString cstr1, cstr2, cstr3,cstr;
	CPoint pt = GetCurrentMessage()->pt;   //获取当前鼠标点击消息的坐标点
	m_list.ScreenToClient(&pt);   //将鼠标的屏幕坐标，转换成树形控件的客户区坐标
	UINT uFlags = 0;
	HTREEITEM hItem = m_list.HitTest(pt, &uFlags);//然后做点击测试
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//如果点击的位置是在节点位置上面
	{
		m_list.SelectItem(hItem);
		//获取开始我们设置的数据，注意这就是我为什么开始要每个节点设置不同的数据的原因。当然，如果你的数据节点比较少，你也可以通过获取节点的文字，如上面设置的"海淀区"，然后通过字符串比较来判断点击了哪个节点
		cstr1 = m_list.GetItemText(hItem);
		vector<CPoem*>::iterator it = theApp.m_Cpoem.m_poem.begin();
		while (it != theApp.m_Cpoem.m_poem.end())
		{
			cstr = (*it)->m_title.c_str();
			cstr += "(";
			cstr += (*it)->m_author.c_str();
			cstr += ")";
			theApp.m_poem = cstr;
			if (cstr == cstr1)
			{
				cstr = (*it)->m_title.c_str();
				cstr += "(";
				cstr += (*it)->m_author.c_str();
				cstr += ")";
				theApp.m_poem = cstr;
				cstr2 = (*it)->m_title.c_str();
				cstr2 += "\r\n";//追加换行符
				cstr3 += cstr2;
				cstr2 = (*it)->m_author.c_str();
				cstr2 += "\r\n";//追加换行符
				cstr3 += cstr2;
				cstr2 = (*it)->m_dynasty.c_str();
				cstr2 += "\r\n";//追加换行符
				cstr3 += cstr2;
				for (k = 0; k < (*it)->m_len; k++)
				{
					cstr2 = (*it)->m_content[k].c_str();
					cstr2 += "\r\n";//追加换行符
					cstr3 += cstr2;
				}
				GetDlgItem(IDC_EDIT1)->SetWindowText(cstr3);//不能多次添加，否则会覆盖
				break;
			}
			it++;
		}
	}
	*pResult = 0;
}



void CPerson::OnBnClickedButton5()//清空列表
{
	int i;
	vector<CUser*>::iterator it = theApp.m_Cuser.m_user.begin();
	while (it != theApp.m_Cuser.m_user.end())
	{
		if ((*it)->m_name.c_str() == theApp.m_name)
		{
			for (i = 0; i < (*it)->c_len; i++)
			{
				(*it)->m_collect[i] = "";
			}
			for (i = 0; i < (*it)->s_len; i++)
			{
				(*it)->m_studyed[i] = "";
			}
			(*it)->c_len = 0;
			(*it)->s_len = 0;
			GetDlgItem(IDC_EDIT3)->SetWindowText(_T("0"));
			GetDlgItem(IDC_EDIT4)->SetWindowText(_T("0"));
			break;
		}
		it++;
	}
	m_list.DeleteAllItems();
}


void CPerson::OnBnClickedButton3()
{
	SendMessage(WM_CLOSE);
}
