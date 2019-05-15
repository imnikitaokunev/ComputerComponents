#include "TextFile.h"

template <class T>
void TextFile<T>::openForWrite()
{
	fout.open(fileName, ios::trunc);
}

template <class T>
void TextFile<T>::closeWrite()
{
	if (this->isOpenForWrite())
		fout.close();
}

template <class T>
void TextFile<T>::openForRead()
{
	fin.open(fileName, ios::in);
}

template <class T>
void TextFile<T>::closeRead()
{
	if (this->isOpenForRead())
		fin.close();
}

template <class T> 
bool TextFile<T>::isOpenForRead()
{
	if (!fin.is_open())
		return false;
	else
		return true;
}

template <class T>
bool TextFile<T>::isOpenForWrite()
{
	if (!fout.is_open())
		return false;
	else
		return true;
}

template <class T>
void TextFile<T>::remoteForRead()
{
	if (this->isOpenForRead())
	{
		fin.seekg(0, ios::beg);
		fin.clear();
	}
}

template <class T>
void TextFile<T>::remoteForWrite()
{
	if (this->isOpenForWrite())
	{
		fout.seekp(0, ios::beg);
		fout.clear();
	}
}

template <class T>
bool TextFile<T>::endFile()
{
	if (fin.eof())
		return true;
	else
		return false;
}

template <class T>
void TextFile<T>::write(T& obj)
{
	fout << obj << endl;
}

template <class T>
void TextFile<T>::read(T& obj)
{
	fin >> obj;
}
