#pragma once
#include <iostream>
#include <string>
using namespace std;

template< class T>
class OutputIterator
{
private:
	const char* delim;							//��������� ��������� �������
	ostream* stream;							//����� ������
public:
	OutputIterator(ostream& ostream)
	{
		this->stream = &ostream;
		this->delim = nullptr;
	}
	OutputIterator(ostream& ostream, const char* delim)
	{
		this->stream = &ostream;
		this->delim = delim;
	}
	~OutputIterator()
	{

	}
	OutputIterator<T>& operator= (T& value);	//������� �� ����� ������ value
	OutputIterator<T>& operator*();				//�������������� �������� ������
	OutputIterator<T>& operator++();			//������� � ���������� ��������
};


