
// My PoemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "My Poem.h"
#include "My PoemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyPoemDlg �Ի���



CMyPoemDlg::CMyPoemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyPoemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyPoemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_list);
}

BEGIN_MESSAGE_MAP(CMyPoemDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMyPoemDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyPoemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CMyPoemDlg::OnBnClickedButton8)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CMyPoemDlg::OnClickTree1)
	ON_BN_CLICKED(IDC_BUTTON10, &CMyPoemDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyPoemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyPoemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyPoemDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyPoemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CMyPoemDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyPoemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyPoemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON11, &CMyPoemDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CMyPoemDlg ��Ϣ�������

BOOL CMyPoemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	flag=true;
	GetDlgItem(IDC_EDIT1)->SetWindowText(theApp.m_name);//
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyPoemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyPoemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyPoemDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyPoemDlg::OnBnClickedButton1()//��һ��
{
	int i, j ,k;
	cstr3="",cstr2="",cstr1="";
	cstr1 = theApp.m_poem;
	vector<CPoem*>::iterator it = theApp.m_Cpoem.m_poem.begin();
	while (it != theApp.m_Cpoem.m_poem.end()-1)
	{
		cstr = (*it)->m_title.c_str();
		cstr += "(";
		cstr += (*it)->m_author.c_str();
		cstr += ")";
		if (cstr == cstr1)
		{
			it++;
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
			GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//���ܶ����ӣ�����Ḳ��
			break;
		}
		it++;
	}
}


void CMyPoemDlg::OnBnClickedButton8()
{
	inittree();
	flag = true;
}


void CMyPoemDlg::OnLbnSelchangeList1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CMyPoemDlg::inittree()//ʫ���б�
{
	m_list.DeleteAllItems();
	int i, j;
	cstr1 = "", cstr2 = "";
	for (i = 0; i < theApp.m_Cpoem.A_len; i++)
	{
		cstr1 = theApp.m_Cpoem.Au[i].m_author.c_str();
		hItem = m_list.InsertItem(cstr1, TVI_ROOT);//��Ӹ��ڵ�
		cstr2 = theApp.m_Cpoem.Au[i].m_poems[0]->m_title.c_str();
		cstr2 += "(";
		cstr2 += theApp.m_Cpoem.Au[i].m_poems[0]->m_author.c_str();
		cstr2 += ")";
		hSubItem = m_list.InsertItem(cstr2, hItem);//��ӵ�һ�����ӽڵ�
		for (j = 1; j < theApp.m_Cpoem.Au[i].m_poems.size(); j++)
		{
			cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_title.c_str();
			cstr2 += "(";
			cstr2 += theApp.m_Cpoem.Au[i].m_poems[j]->m_author.c_str();
			cstr2 += ")";
			hSubItem = m_list.InsertItem(cstr2, hItem, hSubItem);//��Ӻ��ӽڵ�
		}
	}
}
void CMyPoemDlg::inittree2()//����
{
	m_list.DeleteAllItems();
	int i, j;
	for (i = 0; i < theApp.m_Cpoem.D_len; i++)
	{
		cstr1 = theApp.m_Cpoem.Dy[i].m_dynasty.c_str();
		hItem = m_list.InsertItem(cstr1, TVI_ROOT);//��Ӹ��ڵ�
		cstr2 = theApp.m_Cpoem.Dy[i].m_poems[0]->m_title.c_str();
		cstr2 += "(";
		cstr2 += theApp.m_Cpoem.Dy[i].m_poems[0]->m_author.c_str();
		cstr2 += ")";
	    hSubItem = m_list.InsertItem(cstr2, hItem);//��ӵ�һ�����ӽڵ�
		for (j = 1; j < theApp.m_Cpoem.Dy[i].m_poems.size(); j++)
		{
			cstr2 = theApp.m_Cpoem.Dy[i].m_poems[j]->m_title.c_str();
			cstr2 += "(";
			cstr2 += theApp.m_Cpoem.Dy[i].m_poems[j]->m_author.c_str();
			cstr2 += ")";
			hSubItem = m_list.InsertItem(cstr2, hItem, hSubItem);//��Ӻ��ӽڵ�
		}
	}
}


void CMyPoemDlg::OnClickTree1(NMHDR *pNMHDR, LRESULT *pResult)//��Ӧ�����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int i,j, k;
	if (flag)
	{
		cstr3 = "", cstr2 = "", cstr1 = "";
		CPoint pt = GetCurrentMessage()->pt;   //��ȡ��ǰ�������Ϣ�������
		m_list.ScreenToClient(&pt);   //��������Ļ���꣬ת�������οؼ��Ŀͻ�������
		UINT uFlags = 0;
		HTREEITEM hItem = m_list.HitTest(pt, &uFlags);//Ȼ�����������
		if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//��������λ�����ڽڵ�λ������
		{
			m_list.SelectItem(hItem);
			//��ȡ��ʼ�������õ����ݣ�ע���������Ϊʲô��ʼҪÿ���ڵ����ò�ͬ�����ݵ�ԭ�򡣵�Ȼ�����������ݽڵ�Ƚ��٣���Ҳ����ͨ����ȡ�ڵ�����֣����������õ�"������"��Ȼ��ͨ���ַ����Ƚ����жϵ�����ĸ��ڵ�
			cstr1 = m_list.GetItemText(hItem);
			for (i = 0; i < theApp.m_Cpoem.A_len; i++)
			{
				for (j = 0; j < theApp.m_Cpoem.Au[i].m_poems.size(); j++)
				{
					cstr = theApp.m_Cpoem.Au[i].m_poems[j]->m_title.c_str();
					cstr += "(";
					cstr += theApp.m_Cpoem.Au[i].m_poems[j]->m_author.c_str();
					cstr += ")";
					if (cstr1 == cstr)
					{
						cstr = theApp.m_Cpoem.Au[i].m_poems[j]->m_title.c_str();
						cstr += "(";
						cstr += theApp.m_Cpoem.Au[i].m_poems[j]->m_author.c_str();
						cstr += ")";
						theApp.m_poem = cstr;
						cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_title.c_str();
						cstr2+="\r\n";//׷�ӻ��з�
						cstr3 += cstr2;
						cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_author.c_str();
						cstr2 += "\r\n";//׷�ӻ��з�
						cstr3 += cstr2;
						cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_dynasty.c_str();
						cstr2 += "\r\n";//׷�ӻ��з�
						cstr3 += cstr2;
						for (k = 0; k < theApp.m_Cpoem.Au[i].m_poems[j]->m_len; k++)
						{
							cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_content[k].c_str();
							cstr2 += "\r\n";//׷�ӻ��з�
							cstr3 += cstr2;
						}
						GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//���ܶ����ӣ�����Ḳ��
					}
				}
			}
		}
	}
	else
	{
		CString cstr1, cstr2, cstr3;
		CPoint pt = GetCurrentMessage()->pt;   //��ȡ��ǰ�������Ϣ�������
		m_list.ScreenToClient(&pt);   //��������Ļ���꣬ת�������οؼ��Ŀͻ�������
		UINT uFlags = 0;
		HTREEITEM hItem = m_list.HitTest(pt, &uFlags);//Ȼ�����������
		if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//��������λ�����ڽڵ�λ������
		{
			m_list.SelectItem(hItem);
			//��ȡ��ʼ�������õ����ݣ�ע���������Ϊʲô��ʼҪÿ���ڵ����ò�ͬ�����ݵ�ԭ�򡣵�Ȼ�����������ݽڵ�Ƚ��٣���Ҳ����ͨ����ȡ�ڵ�����֣����������õ�"������"��Ȼ��ͨ���ַ����Ƚ����жϵ�����ĸ��ڵ�
			cstr1 = m_list.GetItemText(hItem);
			for (i = 0; i < theApp.m_Cpoem.D_len; i++)
			{
				vector<CPoem*>::iterator it = theApp.m_Cpoem.Dy[i].m_poems.begin();
				while (it != theApp.m_Cpoem.Dy[i].m_poems.end())
				{
					cstr = (*it)->m_title.c_str();
					cstr += "(";
					cstr += (*it)->m_author.c_str();
					cstr += ")";
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
						GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//���ܶ����ӣ�����Ḳ��
						break;
					}
					it++;
				}
			}
		}
	}
}


void CMyPoemDlg::OnBnClickedButton10()//�����б�
{
	inittree2();
	flag = false;
}


void CMyPoemDlg::OnBnClickedButton2()//��һ��
{
	int i, j, k;
	cstr3 = "", cstr2 = "", cstr1 = "";
	cstr1 = theApp.m_poem;
	vector<CPoem*>::iterator it = theApp.m_Cpoem.m_poem.begin();
	it++;
	while (it != theApp.m_Cpoem.m_poem.end())
	{
		cstr = (*it)->m_title.c_str();
		cstr += "(";
		cstr += (*it)->m_author.c_str();
		cstr += ")";
		if (cstr == cstr1)
		{
			it--;
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
			GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//���ܶ����ӣ�����Ḳ��
			break;
		}
		it++;
	}
}


void CMyPoemDlg::OnBnClickedButton6()//�ղ�
{
	if (theApp.F)
	{
		MessageBox(_T("���ȵ�¼��"));
	}
	else
	{

		int i;
		bool judge = true;
		vector<CUser*>::iterator it_ = theApp.m_Cuser.m_user.begin();
		while (it_ != theApp.m_Cuser.m_user.end())
		{
			if ((*it_)->m_name.c_str() == theApp.m_name)//�ҵ���ǰ�û�
			{
				for (i = 0; i < (*it_)->c_len; i++)
				{
					if ((*it_)->m_collect[i].c_str() == theApp.m_poem)
					{
						MessageBox(_T("���ղأ�"));
						judge = false;
						break;
					}
				}
				if (judge)
				{
					(*it_)->m_collect[(*it_)->c_len] = LPCTOSTRING(theApp.m_poem.GetBuffer(theApp.m_poem.GetLength()));
					(*it_)->c_len++;
					MessageBox(_T("��ӳɹ���"));
				}
				break;
			}
			it_++;
		}
	}
}
string CMyPoemDlg::LPCTOSTRING(LPCWSTR pwszSrc)//ת����ʽ
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

void CMyPoemDlg::OnBnClickedButton7()//��ѧ��
{
	if (theApp.F)
	{
		MessageBox(_T("���ȵ�¼��"));
	}
	else
	{

		int i;
		bool judge = true;
		vector<CUser*>::iterator it_ = theApp.m_Cuser.m_user.begin();
		while (it_ != theApp.m_Cuser.m_user.end())
		{
			if ((*it_)->m_name.c_str() == theApp.m_name)//�ҵ���ǰ�û�
			{
				for (i = 0; i < (*it_)->s_len; i++)
				{
					if ((*it_)->m_studyed[i].c_str() == theApp.m_poem)
					{
						MessageBox(_T("��ѧ����"));
						judge = false;
						break;
					}
				}
				if (judge)
				{
					(*it_)->m_studyed[(*it_)->s_len] = LPCTOSTRING(theApp.m_poem.GetBuffer(theApp.m_poem.GetLength()));
					(*it_)->s_len++;
					MessageBox(_T("��ӳɹ���"));
				}
				break;
			}
		it_++;
    	}
	}
}


void CMyPoemDlg::OnBnClickedButton5()//��������
{
	if (theApp.F)
	{
		MessageBox(_T("���ȵ�¼��"));
	}
	else
	{
		CPerson person;
		person.DoModal();
	}
}


void CMyPoemDlg::OnBnClickedButton9()//����
{
	m_list.DeleteAllItems();
	//UpdateData(TRUE);//Ҫ�����û�������� true��Ҫ���������û��� false
	hItem = m_list.InsertItem(_T("�������"), TVI_ROOT);//��Ӹ��ڵ�

	CString get_search,cstr;//Ҫ ������ʫ����Ŀ
	string str,str1;
	bool flag1 = false;
	GetDlgItem(IDC_EDIT2)->GetWindowText(get_search);
	int len = get_search.GetLength();//Ҫ ������ʫ����Ŀ�ĳ��ȣ�

	vector<CPoem*>::iterator it = theApp.m_Cpoem.m_poem.begin();
	while (it != theApp.m_Cpoem.m_poem.end())
	{
		str = (*it)->m_title.substr(0,2*len);//��ȡ����(����Ҫ��2)
		str1 = (*it)->m_author.substr(0, 2 * len);
		if (get_search == str.c_str())
		{
			flag1 = true;
			cstr = (*it)->m_title.c_str();
			hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//��Ӻ��ӽڵ�
		}
		else if (get_search == str1.c_str())
		{
			flag1 = true;
			cstr = (*it)->m_title.c_str();
			cstr += "(";
			cstr += (*it)->m_author.c_str();
			cstr += ")";
			hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//��Ӻ��ӽڵ�
		}
		it++;
	}
	if (flag1==false)
		hSubItem = m_list.InsertItem(_T("��������ʫ������"), hItem, hSubItem);//��Ӻ��ӽڵ�
}

void CMyPoemDlg::OnBnClickedButton3()//�л��˻�
{
	CLogin login;
	login.DoModal();
	GetDlgItem(IDC_EDIT1)->SetWindowText(theApp.m_name);
}



void CMyPoemDlg::OnBnClickedButton4()//��������
{
	//PlaySound("SystemStart", NULL, SND_ALIAS | SND_ASYNC);
}


void CMyPoemDlg::OnBnClickedButton11()//������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
