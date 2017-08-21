#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
class CPoem
{
public:
	CPoem();
	~CPoem();
	string m_title;
	string m_author;
	string m_dynasty;
	string m_content[400];
	int m_len;//诗的内容的长度

};

