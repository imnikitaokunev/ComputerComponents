#include "InputException.h"

#define MIN 0
#define MAX 100000			
#define MAXCORES 32			//����. ���������� ���� - 32
#define MAXFREQUENCY 5200	//����. ������� ���������� - 5200MHz
#define MAXCAPACITY 64		//����. ������ ��� - 64��
#define MAXVRAM 12			//����. ����� ����������� - 12��
#define MAXDRIVE 4096		//����. ������ �������� ����� - 4��

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
				throw InputException("������������ ����.", "������� �� �����.");
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
			cout << "��������� ������." << endl;
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
				throw InputException("������������ ����.", "������� �� �����.");
			if (number < min || number > max)
				throw InputException("������������ ����.", "�������� ������� �����.");
		}
		catch (InputException ex)
		{
			flag = true;
			cin.clear();
			rewind(stdin);
			cout << ex.what() << endl;
			cout << ex.code() << endl;
			cout << "������� ����� �� " << min << " �� " << max << endl;
		}
		catch (...)
		{
			flag = true;
			cout << "��������� ������." << endl;
			cin.clear();
			rewind(stdin);
			cout << "������� ����� �� " << min << " �� " << max << endl;
		}

	} while (flag);

	return number;
}
