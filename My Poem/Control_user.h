#pragma once
#include "User.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
#include <sstream>
class CControl_user
{
public:
	CControl_user();
	~CControl_user();
	vector<CUser*>m_user;
	int m_len;//用户的数量

	void Getlen();//获取用户数量
	void Save();//保存已有账户的基本信息
	void Read();//读取已有账户的基本信息
};

