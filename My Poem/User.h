#pragma once
#include "Poem.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
class CUser
{
public:
	CUser();
	~CUser();
	string m_name;
	string m_key;//����
	string m_collect[100];
	string m_studyed[100];
	int c_len;//�ղع���ʫ
	int s_len;//ѧϰ����ʫ
};

