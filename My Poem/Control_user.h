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
	int m_len;//�û�������

	void Getlen();//��ȡ�û�����
	void Save();//���������˻��Ļ�����Ϣ
	void Read();//��ȡ�����˻��Ļ�����Ϣ
};

