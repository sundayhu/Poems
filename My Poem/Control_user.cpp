#include "stdafx.h"
#include "Control_user.h"


CControl_user::CControl_user()
{
}


CControl_user::~CControl_user()
{
}
void CControl_user::Getlen()
{
	string len;
	ifstream in;
	in.open("count.txt");
	if (!in)
	{
		cerr << "无法正常打开此文件" << endl;
	}
	getline(in, len);
	m_len = atoi(len.c_str());
	in.close();
}
void CControl_user::Read()
{
	Getlen();
	stringstream ss;
	ifstream in;
	string str, t,strs[400];
	int count,i,j=0;
	for (i = 1; i <= m_len; i++)
	{
		ss.clear();//
		ss.str("");//重新初始化
		ss << i;
		ss >> str;
		t = 'u' + str + '.' + 't' + 'x' + 't';
		count = 0;
		CUser *user = new CUser;
		in.open(t);
		if (!in)
		{
			cerr << "无法正常打开此文件" << endl;
		}
		while (in.good() && !in.eof()) //依次读入文件
		{
			if (count == 0)
			{
				getline(in, user->m_name);
			}
			else if (count == 1)
			{
				getline(in, user->m_key);
			}
			else
			{
				getline(in, user->m_collect[user->c_len]);
				user->c_len++;
			}
			count++;
		}
		in.close();

		ss.clear();//
		ss.str("");//重新初始化
		ss << i;
		ss >> str;
		t = 's' + str + '.' + 't' + 'x' + 't';
		in.open(t);
		if (!in)
		{
			cerr << "无法正常打开此文件" << endl;
		}
		count = 0;
		while (in.good() && !in.eof()) //依次读入文件
		{
			if (count < 0)
			{
				getline(in, str);
			}
			else
			{
				getline(in, user->m_studyed[user->s_len]);
				user->s_len++;
			}
			count++;
		}
		in.close();
		m_user.push_back(user);
	}
}
void CControl_user::Save()
{
	stringstream ss;
	ofstream out;
	string str, t;
	int i = 1;
	vector<CUser*>::iterator it = m_user.begin();
	while (it != m_user.end())
	{
		ss.clear();//
		ss.str("");//重新初始化
		ss << i;
		ss >> str;
		t = 'u' + str + '.' + 't' + 'x' + 't';
		out.open(t);
		out << (*it)->m_name;
		out << "\n";
		out << (*it)->m_key;
		if ((*it)->c_len != 0)
		{
			out << "\n";
			for (int j = 0; j < (*it)->c_len-1; j++)
			{
				out << (*it)->m_collect[j];
				out << "\n";
			}
			out << (*it)->m_collect[(*it)->c_len-1];
		}
		out.close();

		ss.clear();//
		ss.str("");//重新初始化
		ss << i;
		ss >> str;
		t = 's' + str + '.' + 't' + 'x' + 't';
		out.open(t);
		if ((*it)->s_len != 0)
		{
			for (int k = 0; k < (*it)->s_len - 1; k++)
			{
				out << (*it)->m_studyed[k];
				out << "\n";
			}
			out << (*it)->m_studyed[(*it)->s_len - 1];
		}
		out.close();

		it++;
		i++;
	}
	out.open("count.txt");
	out << m_len;
	out.close();
}