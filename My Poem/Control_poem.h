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
#include <sstream>

class CControl_poem
{
public:
	CControl_poem();
	~CControl_poem();
	vector<CPoem*>m_poem;
	struct
	{
		string m_author;
		vector<CPoem*>m_poems;
	}Au[400];
	struct
	{
		string m_dynasty;
		vector<CPoem*>m_poems;
	}Dy[100];
	int A_len;//作者的长度
	int D_len;//时期的长度
	
	
	// 读入文件
	void Read();
	// 将诗词分类别
	void Classify();
};

