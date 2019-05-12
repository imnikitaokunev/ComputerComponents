#include "BinaryFile.h"

template <class T>
void BinaryFile<T>::openForWrite()
{
	fout.open(fileName, ios::trunc);
}

template <class T>
void BinaryFile<T>::closeWrite()
{
	if(this->isOpenForWrite())
		fout.close();
}

template <class T>
void BinaryFile<T>::openForRead()
{
	fin.open(fileName, ios::in);
}

template <class T>
void BinaryFile<T>::closeRead()
{
	if (this->isOpenForRead())
		fin.close();
}

template <class T>
bool BinaryFile<T>::isOpenForRead()
{
	if (!fin.is_open())
		return false;
	else
		return true;
}

template <class T>
bool BinaryFile<T>::isOpenForWrite()
{
	if (!fout.is_open())
		return false;
	else
		return true;
}

template <class T>
void BinaryFile<T>::remoteForRead()
{
	if (this->isOpenForRead())
	{
		fin.seekg(0, ios::beg);
		fin.clear();
	}
}

template <class T>
void BinaryFile<T>::remoteForWrite()
{
	if (this->isOpenForWrite())
	{
		fout.seekp(0, ios::beg);
		fout.clear();
	}
}

template <class T>
bool BinaryFile<T>::endFile()
{
	if (fin.eof())
		return true;
	else
		return false;
}

template <class T>
void BinaryFile<T>::write(T& obj)
{
	obj.writeToBinary(fout, obj);
}

template <class T>
void BinaryFile<T>::read(T& obj)
{
	obj.readFromBinary(fin, obj);
}
