//#include "TextFile.h"
//
//template <class T> 
//bool TextFile<T>::isOpenForRead()
//{
//	if (!fin.is_open())
//		return false;
//	else
//		return true;
//}
//
//template <class T>
//bool TextFile<T>::isOpenForWrite()
//{
//	if (!fout.is_open())
//		return false;
//	else
//		return true;
//}
//
//template <class T>
//void TextFile<T>::remote()
//{
//	fileStream.seekg(0, ios::beg);
//	fileStream.seekp(0, ios::beg);
//	fileStream.clear();
//}
//
//template <class T>
//bool TextFile<T>::endFile()
//{
//	if (fileStream.eof())
//		return true;
//	else
//		return false;
//}
//
//template <class T>
//void TextFile<T>::write(T& obj)
//{
//	fileStream << obj;
//}
//
//template <class T>
//void TextFile<T>::read(T& obj)
//{
//	fileStream >> obj;
//}
