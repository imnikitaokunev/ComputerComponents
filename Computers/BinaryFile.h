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
	void openForWrite();		//��������� ���� ��� ������
	void closeWrite();			//��������� ����, �������� ��� ������
	void openForRead();			//��������� ���� ��� ������
	void closeRead();			//��������� ����, �������� ��� ������
	bool isOpenForRead();		//���������� true, ���� ���� ������ ��� ������, � false, ���� ���
	bool isOpenForWrite();		//���������� true, ���� ���� ������ ��� ������, � false, ���� ���
	void remoteForRead();		//������������� ��������� ��� ������ �� ������ �����
	void remoteForWrite();		//������������� ��������� ��� ������ �� ������ �����
	bool endFile();				//���������� true, ���� ��� ��������� ����� �����, � false, ���� ���
	void write(T& obj);			//���������� ������ obj � ����
	void read(T& obj);			//������ ������ �� ����� � obj
};
