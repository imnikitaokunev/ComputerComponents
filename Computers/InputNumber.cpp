#include "InputException.h"

#define MIN 0
#define MAX 100000			
#define MAXCORES 32			//Макс. количество ядер - 32
#define MAXFREQUENCY 5200	//Макс. частота процессора - 5200MHz
#define MAXCAPACITY 64		//Макс. размер ОЗУ - 64ГБ
#define MAXVRAM 12			//Макс. объем видеопамяти - 12Гб
#define MAXDRIVE 4096		//Макс. размер жесткого диска - 4Тб

template <class T>
T inputNumber()
{
	T number;	
	bool flag;

	do
	{
		try
		{
			flag = false;
			cin >> number;
			if (!cin.good() || cin.peek() != '\n')
				throw InputException("Некорректный ввод.", "Введено не число.");
		}
		catch (InputException ex)
		{
			flag = true;
			cin.clear();
			rewind(stdin);
			cout << ex.what() << endl;
			cout << ex.code() << endl;
		}
		catch (...)
		{
			cout << "Произошла ошибка." << endl;
			cin.clear();
			rewind(stdin);
		}
	} while (flag);

	return number;
}

template <class T>
T inputNumber(T min, T max)
{
	T number;
	bool flag;

	do
	{
		try
		{
			flag = false;
			cin >> number;
			if (!cin.good() || cin.peek() != '\n')
				throw InputException("Некорректный ввод.", "Введено не число.");
			if (number < min || number > max)
				throw InputException("Некорректный ввод.", "Неверные границы числа.");
		}
		catch (InputException ex)
		{
			flag = true;
			cin.clear();
			rewind(stdin);
			cout << ex.what() << endl;
			cout << ex.code() << endl;
			cout << "Введите число от " << min << " до " << max << endl;
		}
		catch (...)
		{
			flag = true;
			cout << "Произошла ошибка." << endl;
			cin.clear();
			rewind(stdin);
			cout << "Введите число от " << min << " до " << max << endl;
		}

	} while (flag);

	return number;
}
