#include "Input.h"

string inputString()
{
	bool flag;
	string str;

	do
	{
		rewind(stdin);
		try
		{
			flag = false;
			getline(cin, str);
			for (int i = 0; str[i]; i++)
			{
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] <'a' || str[i] > 'z') && str[i] != ' ' && str[i] != '-')
					throw InputException("������������ ����.", "����������� ���������� ���������.");

			}
		}
		catch (InputException ex)
		{
			flag = true;
			cout << ex.what() << endl;
			cout << ex.code() << endl;
		}
		catch (...)
		{
			cout << "��������� ������." << endl;
		}


	} while (flag);

	return str;
}

string inputStringWithNums()
{
	bool flag;
	string str;

	do
	{
		rewind(stdin);
		try
		{
			flag = false;
			getline(cin, str);
			for (int i = 0; str[i]; i++)
			{
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] <'a' || str[i] > 'z') && str[i] != ' ' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
					throw InputException("������������ ����.", "����������� ���������� ��������� � �����.");
				if (str == "AMD")
					throw "������ ��������� � ������ ������.";
			}
		}
		catch (InputException ex)
		{
			flag = true;
			cout << ex.what() << endl;
			cout << ex.code() << endl;
		}
		catch (const char* str)
		{
			str = "";
			throw;
		}
		catch (...)
		{
			cout << "��������� ������." << endl;
		}
	} while (flag);

	return str;
}
