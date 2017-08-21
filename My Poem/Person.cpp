// Person.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "My Poem.h"
#include "Person.h"
#include "afxdialogex.h"


// CPerson �Ի���

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


// CPerson ��Ϣ�������
BOOL CPerson::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
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
			ss.str("");//���³�ʼ��
			ss << (*it)->c_len;
			ss >> str;
			cstr = str.c_str();
			GetDlgItem(IDC_EDIT3)->SetWindowText(cstr);
			ss.clear();//
			ss.str("");//���³�ʼ��
			ss << (*it)->s_len;
			ss >> str;
			cstr = str.c_str();
			GetDlgItem(IDC_EDIT4)->SetWindowText(cstr);
			break;
		}
		it++;
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPerson::OnBnClickedButton1()//����б�
{
	m_list.DeleteAllItems();
	int i;
	CString cstr;
	vector<CUser*>::iterator it = theApp.m_Cuser.m_user.begin();
	while (it != theApp.m_Cuser.m_user.end())
	{
		if ((*it)->m_name.c_str() == theApp.m_name)
		{
			hItem = m_list.InsertItem(_T("�ղ��б�"), TVI_ROOT);//��Ӹ��ڵ�
			for (i = 0; i < (*it)->c_len; i++)
			{
				cstr = (*it)->m_collect[i].c_str();
				hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//��Ӻ��ӽڵ�
			}
			hItem = m_list.InsertItem(_T("ѧϰ��¼"), TVI_ROOT);//��Ӹ��ڵ�
			for (i = 0; i < (*it)->s_len; i++)
			{
				cstr = (*it)->m_studyed[i].c_str();
				hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//��Ӻ��ӽڵ�
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
	CPoint pt = GetCurrentMessage()->pt;   //��ȡ��ǰ�������Ϣ�������
	m_list.ScreenToClient(&pt);   //��������Ļ���꣬ת�������οؼ��Ŀͻ�������
	UINT uFlags = 0;
	HTREEITEM hItem = m_list.HitTest(pt, &uFlags);//Ȼ�����������
	if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//��������λ�����ڽڵ�λ������
	{
		m_list.SelectItem(hItem);
		//��ȡ��ʼ�������õ����ݣ�ע���������Ϊʲô��ʼҪÿ���ڵ����ò�ͬ�����ݵ�ԭ�򡣵�Ȼ�����������ݽڵ�Ƚ��٣���Ҳ����ͨ����ȡ�ڵ�����֣����������õ�"������"��Ȼ��ͨ���ַ����Ƚ����жϵ�����ĸ��ڵ�
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
				cstr2 += "\r\n";//׷�ӻ��з�
				cstr3 += cstr2;
				cstr2 = (*it)->m_author.c_str();
				cstr2 += "\r\n";//׷�ӻ��з�
				cstr3 += cstr2;
				cstr2 = (*it)->m_dynasty.c_str();
				cstr2 += "\r\n";//׷�ӻ��з�
				cstr3 += cstr2;
				for (k = 0; k < (*it)->m_len; k++)
				{
					cstr2 = (*it)->m_content[k].c_str();
					cstr2 += "\r\n";//׷�ӻ��з�
					cstr3 += cstr2;
				}
				GetDlgItem(IDC_EDIT1)->SetWindowText(cstr3);//���ܶ����ӣ�����Ḳ��
				break;
			}
			it++;
		}
	}
	*pResult = 0;
}



void CPerson::OnBnClickedButton5()//����б�
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
