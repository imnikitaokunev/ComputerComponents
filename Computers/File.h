#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class File
{
protected:
	string fileName;
	ifstream fin;
	ofstream fout;

public:
	File(string fileName)
	{
		this->fileName = fileName;
	}
	~File()
	{

	}
};