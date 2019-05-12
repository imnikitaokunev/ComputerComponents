#pragma once
#include "File.h"

template <class T>
class TextFile : public File
{

public:
	TextFile(string fileName) : File(fileName)
	{
		//fileStream.open(fileName, ios::in | ios::out | ios::trunc);
		///fin.open(fileName, ios::in);
		//fout.open(fileName, ios::app);
		//if (!fileStream.is_open())
	//	{
			//cout << "Файл " << fileName << " не открыт." << endl;
			//return;
		//}
	}
	~TextFile() 
	{
	//	fileStream.close();
	}
	bool isOpenForRead();
	bool isOpenForWrite();
	void remote();
	bool endFile();
	void write(T& obj);
	void read(T& obj);
};