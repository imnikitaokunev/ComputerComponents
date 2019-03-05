#include "Interface.h"

template <class T>
void Interface<T>::menu()
{
	//Interface <CPU> cpu;
	//Interface <Memory> memory;
	//Interface <GraphicsCard> graphicscard;
	Interface <Computer> computer;

	char choice;
	do
	{
		system("cls");
		cout << setw(80) << "-----���� ������������ �������������-----" << endl;
		cout << "\t1. ����������." << endl
			<< "\t2. ����������� ������." << endl
			<< "\t3. ����������." << endl
			<< "\t4. ������� ���������." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();

		switch (choice)
		{
		case '1': 
		//	cpu.fun();
			break;
		case '2': 
		//	memory.fun();
			break;
		case '3': 
		//	graphicscard.fun();
			break;
		case '4':
			computer.fun();
			break;
		case '0':
			exit(1);
		default:
			cout << "������������ ����." << endl;;
			system("pause");
			break;
		}

	} while (choice != '0');

}

template <class T>
void Interface<T>::fun()
{
	Tree<T> tree;
	char choice;
	do
	{
		system("cls");
		obj.title();
		cout << "\t1. ��������." << endl
			<< "\t2. �����������." << endl
			<< "\t3. *�������������." << endl
			<< "\t4. �������." << endl
			<< "\t5. ������� ���." << endl
			<< "\t6. �����." << endl
			<< "\t7. ����������." << endl
			<< "\t8. ������ ��������� ���������." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();

		switch (choice)
		{
		case '1':
		{
			system("cls");
			T temp;
			cin >> temp;
			tree.add(temp);
			cout << endl;
			cout << "������� " << temp.getModel() << " ������� ��������." << endl;
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			obj.title();
			cout << endl;
			obj.header();
			tree.show();
			cout << endl;
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			cout << "������� �������, ������� �� ������ �������." << endl;
			T temp;
			bool flag[8] = { true, true, true, true, true, true, true, true };
			cin >> temp;
			Node<T>* ptr = tree.find(temp, flag);
			cout << endl;
			if (ptr != nullptr)
			{
				tree.remove(ptr, flag);
				cout << "������� " << temp.getModel() << " ������� ������." << endl;
			}
			else
				cout << "������ �� �������." << endl;
			system("pause");
			break;
		}
		case '5':
		{
			tree.removeTree();
			break;
		}
		case '6':
		{
			system("cls");
			T temp;
			string model;
			bool flag[8];
			cout << "������� ������: ";
			cin >> model;
			temp.setModel(model);
			flag[MODEL] = true;
			obj.title();
			cout << endl;
			obj.header();
			tree.showByFilter(temp, flag);
			cout << endl;
			system("pause");
			break;
		}
		case '0': 
			break;
		default:
			cout << endl;
			cout << "������������ ����." << endl;;
			system("pause");
			break;
		}
	} while (choice != '0');
}
