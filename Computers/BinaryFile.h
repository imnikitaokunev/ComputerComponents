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
	void openForWrite();		//Открывает файл для записи
	void closeWrite();			//Закрывает файл, открытый для записи
	void openForRead();			//Открывает файл для чтения
	void closeRead();			//Закрывает файл, открытый для чтения
	bool isOpenForRead();		//Возвращает true, если файл открыт для чтения, и false, если нет
	bool isOpenForWrite();		//Возвращает true, если файл открыт для записи, и false, если нет
	void remoteForRead();		//Устанавливает указатель для чтения на начало файла
	void remoteForWrite();		//Устанавливает указатель для записи на начало файла
	bool endFile();				//Возвращает true, если был достигнут конец файла, и false, если нет
	void write(T& obj);			//Записывает объект obj в файл
	void read(T& obj);			//Читает объект из файла в obj
};
