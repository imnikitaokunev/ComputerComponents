#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class File
{
protected:
	string fileName;			//Название файла
	ifstream fin;				//Объект для чтения
	ofstream fout;				//Объект для записи

public:
	File(string fileName)
	{
		this->fileName = fileName;
	}
	~File()
	{

	}
};
