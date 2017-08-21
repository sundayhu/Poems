
// My PoemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "My Poem.h"
#include "My PoemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyPoemDlg 对话框



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


// CMyPoemDlg 消息处理程序

BOOL CMyPoemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	flag=true;
	GetDlgItem(IDC_EDIT1)->SetWindowText(theApp.m_name);//
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyPoemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyPoemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyPoemDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyPoemDlg::OnBnClickedButton1()//下一首
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
			GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//不能多次添加，否则会覆盖
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
	// TODO:  在此添加控件通知处理程序代码
}

void CMyPoemDlg::inittree()//诗人列表
{
	m_list.DeleteAllItems();
	int i, j;
	cstr1 = "", cstr2 = "";
	for (i = 0; i < theApp.m_Cpoem.A_len; i++)
	{
		cstr1 = theApp.m_Cpoem.Au[i].m_author.c_str();
		hItem = m_list.InsertItem(cstr1, TVI_ROOT);//添加根节点
		cstr2 = theApp.m_Cpoem.Au[i].m_poems[0]->m_title.c_str();
		cstr2 += "(";
		cstr2 += theApp.m_Cpoem.Au[i].m_poems[0]->m_author.c_str();
		cstr2 += ")";
		hSubItem = m_list.InsertItem(cstr2, hItem);//添加第一个孩子节点
		for (j = 1; j < theApp.m_Cpoem.Au[i].m_poems.size(); j++)
		{
			cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_title.c_str();
			cstr2 += "(";
			cstr2 += theApp.m_Cpoem.Au[i].m_poems[j]->m_author.c_str();
			cstr2 += ")";
			hSubItem = m_list.InsertItem(cstr2, hItem, hSubItem);//添加孩子节点
		}
	}
}
void CMyPoemDlg::inittree2()//朝代
{
	m_list.DeleteAllItems();
	int i, j;
	for (i = 0; i < theApp.m_Cpoem.D_len; i++)
	{
		cstr1 = theApp.m_Cpoem.Dy[i].m_dynasty.c_str();
		hItem = m_list.InsertItem(cstr1, TVI_ROOT);//添加根节点
		cstr2 = theApp.m_Cpoem.Dy[i].m_poems[0]->m_title.c_str();
		cstr2 += "(";
		cstr2 += theApp.m_Cpoem.Dy[i].m_poems[0]->m_author.c_str();
		cstr2 += ")";
	    hSubItem = m_list.InsertItem(cstr2, hItem);//添加第一个孩子节点
		for (j = 1; j < theApp.m_Cpoem.Dy[i].m_poems.size(); j++)
		{
			cstr2 = theApp.m_Cpoem.Dy[i].m_poems[j]->m_title.c_str();
			cstr2 += "(";
			cstr2 += theApp.m_Cpoem.Dy[i].m_poems[j]->m_author.c_str();
			cstr2 += ")";
			hSubItem = m_list.InsertItem(cstr2, hItem, hSubItem);//添加孩子节点
		}
	}
}


void CMyPoemDlg::OnClickTree1(NMHDR *pNMHDR, LRESULT *pResult)//响应鼠标点击
{
	// TODO:  在此添加控件通知处理程序代码
	int i,j, k;
	if (flag)
	{
		cstr3 = "", cstr2 = "", cstr1 = "";
		CPoint pt = GetCurrentMessage()->pt;   //获取当前鼠标点击消息的坐标点
		m_list.ScreenToClient(&pt);   //将鼠标的屏幕坐标，转换成树形控件的客户区坐标
		UINT uFlags = 0;
		HTREEITEM hItem = m_list.HitTest(pt, &uFlags);//然后做点击测试
		if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//如果点击的位置是在节点位置上面
		{
			m_list.SelectItem(hItem);
			//获取开始我们设置的数据，注意这就是我为什么开始要每个节点设置不同的数据的原因。当然，如果你的数据节点比较少，你也可以通过获取节点的文字，如上面设置的"海淀区"，然后通过字符串比较来判断点击了哪个节点
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
						cstr2+="\r\n";//追加换行符
						cstr3 += cstr2;
						cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_author.c_str();
						cstr2 += "\r\n";//追加换行符
						cstr3 += cstr2;
						cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_dynasty.c_str();
						cstr2 += "\r\n";//追加换行符
						cstr3 += cstr2;
						for (k = 0; k < theApp.m_Cpoem.Au[i].m_poems[j]->m_len; k++)
						{
							cstr2 = theApp.m_Cpoem.Au[i].m_poems[j]->m_content[k].c_str();
							cstr2 += "\r\n";//追加换行符
							cstr3 += cstr2;
						}
						GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//不能多次添加，否则会覆盖
					}
				}
			}
		}
	}
	else
	{
		CString cstr1, cstr2, cstr3;
		CPoint pt = GetCurrentMessage()->pt;   //获取当前鼠标点击消息的坐标点
		m_list.ScreenToClient(&pt);   //将鼠标的屏幕坐标，转换成树形控件的客户区坐标
		UINT uFlags = 0;
		HTREEITEM hItem = m_list.HitTest(pt, &uFlags);//然后做点击测试
		if ((hItem != NULL) && (TVHT_ONITEM & uFlags))//如果点击的位置是在节点位置上面
		{
			m_list.SelectItem(hItem);
			//获取开始我们设置的数据，注意这就是我为什么开始要每个节点设置不同的数据的原因。当然，如果你的数据节点比较少，你也可以通过获取节点的文字，如上面设置的"海淀区"，然后通过字符串比较来判断点击了哪个节点
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
						GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//不能多次添加，否则会覆盖
						break;
					}
					it++;
				}
			}
		}
	}
}


void CMyPoemDlg::OnBnClickedButton10()//朝代列表
{
	inittree2();
	flag = false;
}


void CMyPoemDlg::OnBnClickedButton2()//上一首
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
			GetDlgItem(IDC_EDIT3)->SetWindowText(cstr3);//不能多次添加，否则会覆盖
			break;
		}
		it++;
	}
}


void CMyPoemDlg::OnBnClickedButton6()//收藏
{
	if (theApp.F)
	{
		MessageBox(_T("请先登录！"));
	}
	else
	{

		int i;
		bool judge = true;
		vector<CUser*>::iterator it_ = theApp.m_Cuser.m_user.begin();
		while (it_ != theApp.m_Cuser.m_user.end())
		{
			if ((*it_)->m_name.c_str() == theApp.m_name)//找到当前用户
			{
				for (i = 0; i < (*it_)->c_len; i++)
				{
					if ((*it_)->m_collect[i].c_str() == theApp.m_poem)
					{
						MessageBox(_T("已收藏！"));
						judge = false;
						break;
					}
				}
				if (judge)
				{
					(*it_)->m_collect[(*it_)->c_len] = LPCTOSTRING(theApp.m_poem.GetBuffer(theApp.m_poem.GetLength()));
					(*it_)->c_len++;
					MessageBox(_T("添加成功！"));
				}
				break;
			}
			it_++;
		}
	}
}
string CMyPoemDlg::LPCTOSTRING(LPCWSTR pwszSrc)//转化格式
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

void CMyPoemDlg::OnBnClickedButton7()//已学过
{
	if (theApp.F)
	{
		MessageBox(_T("请先登录！"));
	}
	else
	{

		int i;
		bool judge = true;
		vector<CUser*>::iterator it_ = theApp.m_Cuser.m_user.begin();
		while (it_ != theApp.m_Cuser.m_user.end())
		{
			if ((*it_)->m_name.c_str() == theApp.m_name)//找到当前用户
			{
				for (i = 0; i < (*it_)->s_len; i++)
				{
					if ((*it_)->m_studyed[i].c_str() == theApp.m_poem)
					{
						MessageBox(_T("已学过！"));
						judge = false;
						break;
					}
				}
				if (judge)
				{
					(*it_)->m_studyed[(*it_)->s_len] = LPCTOSTRING(theApp.m_poem.GetBuffer(theApp.m_poem.GetLength()));
					(*it_)->s_len++;
					MessageBox(_T("添加成功！"));
				}
				break;
			}
		it_++;
    	}
	}
}


void CMyPoemDlg::OnBnClickedButton5()//个人中心
{
	if (theApp.F)
	{
		MessageBox(_T("请先登录！"));
	}
	else
	{
		CPerson person;
		person.DoModal();
	}
}


void CMyPoemDlg::OnBnClickedButton9()//搜索
{
	m_list.DeleteAllItems();
	//UpdateData(TRUE);//要接受用户的输入就 true，要输出结果给用户就 false
	hItem = m_list.InsertItem(_T("搜索结果"), TVI_ROOT);//添加根节点

	CString get_search,cstr;//要 搜索的诗的题目
	string str,str1;
	bool flag1 = false;
	GetDlgItem(IDC_EDIT2)->GetWindowText(get_search);
	int len = get_search.GetLength();//要 搜索的诗的题目的长度；

	vector<CPoem*>::iterator it = theApp.m_Cpoem.m_poem.begin();
	while (it != theApp.m_Cpoem.m_poem.end())
	{
		str = (*it)->m_title.substr(0,2*len);//截取长度(中文要乘2)
		str1 = (*it)->m_author.substr(0, 2 * len);
		if (get_search == str.c_str())
		{
			flag1 = true;
			cstr = (*it)->m_title.c_str();
			hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//添加孩子节点
		}
		else if (get_search == str1.c_str())
		{
			flag1 = true;
			cstr = (*it)->m_title.c_str();
			cstr += "(";
			cstr += (*it)->m_author.c_str();
			cstr += ")";
			hSubItem = m_list.InsertItem(cstr, hItem, hSubItem);//添加孩子节点
		}
		it++;
	}
	if (flag1==false)
		hSubItem = m_list.InsertItem(_T("您搜索的诗不存在"), hItem, hSubItem);//添加孩子节点
}

void CMyPoemDlg::OnBnClickedButton3()//切换账户
{
	CLogin login;
	login.DoModal();
	GetDlgItem(IDC_EDIT1)->SetWindowText(theApp.m_name);
}



void CMyPoemDlg::OnBnClickedButton4()//播放音乐
{
	//PlaySound("SystemStart", NULL, SND_ALIAS | SND_ASYNC);
}


void CMyPoemDlg::OnBnClickedButton11()//不播放
{
	// TODO:  在此添加控件通知处理程序代码
}
