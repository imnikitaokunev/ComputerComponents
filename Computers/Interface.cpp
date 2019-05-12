#include "Interface.h"

template <class T>
void Interface<T>::menu()
{
	Interface <CPU> cpu;
	Interface <Memory> memory;
	Interface <GraphicsCard> graphicscard;
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
			cpu.fun("CPU.txt", "CPU.dat");
			break;
		case '2': 
			memory.fun("Memory.txt", "Memory.dat");
			break;
		case '3': 
			graphicscard.fun("GraphicsCards.txt", "GraphicsCard.dat");
			break;
		case '4':
			computer.fun("Computers.txt", "Computers.dat");
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
void Interface<T>::fun(string textFileName, string binaryFileName)
{
	Tree<T> tree;
	char choice;
	// tree.readFile(fileName);
	BinaryFile<T> binaryFile(binaryFileName);

	do
	{
		system("cls");
		obj.title();
		cout << "\t1. ��������." << endl
			<< "\t2. �����������." << endl
			<< "\t3. ��������." << endl
			<< "\t4. �������." << endl
			<< "\t5. ������� ���." << endl
			<< "\t6. �����." << endl
			<< "\t7. ����������." << endl
			<< "\t8. ������ � ����." << endl
			<< "\t9. ������ �� �����." << endl
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
		case '3':
		{
			system("cls");
			obj.title();
			cout << endl;
			obj.header();
			tree.show();
			cout << endl;
			cout << "����� ������� �� ������ ��������?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			cout << endl;
			if (ptr != nullptr)
			{
				ptr->key.change();
				cout << "������� " << temp.getModel() << " ������� �������." << endl;
			}
			else
				cout << "������ �� �������." << endl;
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			obj.title();
			cout << endl;
			obj.header();
			tree.show();
			cout << endl;
			cout << "����� ������� �� ������ �������?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			cout << endl;
			if (ptr != nullptr)
			{
				tree.remove(temp);
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
			bool flag[8] = {false, false, false, false, false, false, false, false};
			temp.search(flag);
			obj.title();
			cout << endl;
			obj.header();
			tree.showByFilter(temp, flag);
			cout << endl;
			system("pause");
			break;
		}
		case '7':
		{
			do
			{
				system("cls");
				obj.title();
				cout << "  � ����� ������� �����������?" << endl;
				cout << "\t1. �� �����������." << endl
					<< "\t2. �� ��������." << endl
					<< "\t0. �����." << endl
					<< endl << "\t  >> ";
				choice = _getch();
				switch (choice)
				{
				case '1':
					tree.sort(SORTTYPE_FORWARD);
					break;
				case '2':
					tree.sort(SORTTYPE_BACKWARDS);
					break;
				case '0':
					break;
				default:
					cout << endl;
					cout << "������������ ����." << endl;;
					system("pause");
					break;
				}
			} while (choice != '1' && choice != '2');

			obj.title();
			cout << endl;
			obj.header();
			tree.show();
			cout << endl << "  ������� �������������." << endl;
			cout << endl;
			system("pause");
			break;
		}
		case '8':
		{
			do
			{
				system("cls");
				obj.title();
				cout << "  � ����� ���� ��������?" << endl;
				cout << "\t1. ���������." << endl
					<< "\t2. ��������." << endl
					<< "\t0. �����." << endl
					<< endl << "\t  >> ";
				choice = _getch();
				switch (choice)
				{
				case '1':
					tree.writeFile(textFileName);
					break;
				case '2':
					binaryFile.openForWrite();
					tree.writeToBinary(binaryFile);
					binaryFile.closeWrite();
					break;
				case '0':
					break;
				default:
					cout << endl;
					cout << "������������ ����." << endl;;
					system("pause");
					break;
				}
			} while (choice != '1' && choice != '2');

			break;
		}
		case '9':
		{
			do
			{
				system("cls");
				obj.title();
				cout << "  �� ������ ����� ���������?" << endl;
				cout << "\t1. ���������." << endl
					<< "\t2. ��������." << endl
					<< "\t0. �����." << endl
					<< endl << "\t  >> ";
				choice = _getch();
				switch (choice)
				{
				case '1':
					tree.readFile(textFileName);
					break;
				case '2':
					binaryFile.openForRead();
					tree.readFromBinary(binaryFile);
					binaryFile.closeRead();
					break;
				case '0':
					break;
				default:
					cout << endl;
					cout << "������������ ����." << endl;;
					system("pause");
					break;
				}
			} while (choice != '1' && choice != '2');

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

	//tree.writeFile(textFileName);
}
