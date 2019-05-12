#pragma once
#include "File.h"

template <class T>
class BinaryFile : public File
{
	
public:
	BinaryFile(string fileName) : File(fileName)
	{
	
	}
	~BinaryFile()
	{
		this->closeRead();
		this->closeWrite();
	}
	void openForWrite();
	void closeWrite();
	void openForRead();
	void closeRead();
	bool isOpenForRead();
	bool isOpenForWrite();
	void remoteForRead();
	void remoteForWrite();
	bool endFile();
	void write(T& obj);
	void read(T& obj);
};
