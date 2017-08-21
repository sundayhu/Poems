#include "stdafx.h"
#include "Control_poem.h"


CControl_poem::CControl_poem()
{
	A_len = 0;
	D_len = 0;
}


CControl_poem::~CControl_poem()
{
}


// 读入文件
void CControl_poem::Read()
{
	stringstream ss;
	string str,t;
	int count,len;
	for (int i = 1; i <= 33; i++)
	{
		ss.clear();//
		ss.str("");//重新初始化
		ss << i;
		ss >> str;
		t = str + '.' + 't' + 'x' + 't';
		//cout << t << endl;
		count = 0;
		len = 0;
		CPoem *poem = new CPoem;
		ifstream in;
		in.open(t);
		if (!in)
		{
			cerr << "无法正常打开此文件" << endl;
		}
		while (in.good() && !in.eof()) //依次读入文件
		{
			if (count == 0)
			{
				getline(in, poem->m_title);
			}
			else if (count == 1)
			{
				getline(in, poem->m_author);
			}
			else if (count == 2)
			{
				getline(in, poem->m_dynasty);
			}
			else{
				getline(in, poem->m_content[len]);
				len++;
			}
			count++;
		}
		in.close();
		poem->m_len = len;
		m_poem.push_back(poem);
	}
}


// 将诗词分类别
void CControl_poem::Classify()
{
	int count;
	//诗人列表
	vector<CPoem*>::iterator it = m_poem.begin();
	Au[0].m_author = (*it)->m_author;
	Au[0].m_poems.push_back(*it);
	it++;
	A_len++;
	while (it != m_poem.end())
	{
		count = 0;
		for (int i = 0; i < A_len; i++)
		{
			if (Au[i].m_author != (*it)->m_author)
			{
				count++;
			}
			else
			{
				Au[i].m_poems.push_back(*it);
			}
		}
		if (count == A_len)
		{
			Au[A_len].m_author = (*it)->m_author;
			Au[A_len].m_poems.push_back(*it);
			A_len++;
		}
		it++;
	}
	//朝代列表
	vector<CPoem*>::iterator it_ = m_poem.begin();
	Dy[0].m_dynasty = (*it_)->m_dynasty;
	Dy[0].m_poems.push_back(*it_);
	it_++;
	D_len++;
	while (it_ != m_poem.end())
	{
		count = 0;
		for (int i = 0; i < D_len; i++)
		{
			if (Dy[i].m_dynasty != (*it_)->m_dynasty)
			{
				count++;
			}
			else
			{
				Dy[i].m_poems.push_back(*it_);
			}
		}
		if (count == D_len)
		{
			Dy[D_len].m_dynasty = (*it_)->m_dynasty;
			Dy[D_len].m_poems.push_back(*it_);
			D_len++;
		}
		it_++;
	}
}
