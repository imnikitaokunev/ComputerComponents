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
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] <'a' || str[i] > 'z') && str[i] != ' ')
					throw InputException("Некорректный ввод.", "Используйте английскуй раскладку.");
			}
		}
		catch (InputException ex)
		{
			flag = true;
			cout << ex.what() << endl;
			cout << ex.code() << endl;
		}

	} while (flag);

	return str;
}