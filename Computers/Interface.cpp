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
			cpu.fun("Cpu");
			break;
		case '2': 
			memory.fun("Memory");
			break;
		case '3': 
			graphicscard.fun("GraphicsCard");
			break;
		case '4':
			computer.fun("Computer");
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
void Interface<T>::fun(string fileName)
{
	Tree<T> tree;
	Iterator<T> iterator(tree);
	Algorithm<T> algorithm(tree);
	OutputIterator<T> outputIterator(cout, "\n");
	TextFile<T> textFile(fileName + ".txt");
	BinaryFile<T> binaryFile(fileName + ".dat");

	char choice;
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
			<< "\t7. �����������." << endl
			<< "\t8. �������� � ����." << endl
			<< "\t9. ��������� �� �����." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl;

		switch (choice)
		{
		case '1':
		{
			system("cls");
			obj.title();										
			cout << "���������� ������ ��������" << endl;
			T temp;
			cin >> temp;
			tree.add(temp);
			cout << "������� " << temp.getModel() << " ������� ��������." << endl;
			break;
		}
		case '2':
		{
			system("cls");
			obj.title();
			obj.header();		

			/*		if (!tree.Empty())
			{
				iterator = tree.begin();
				while (iterator != tree.end())
				{
					cout << *iterator << endl;
					++iterator;
				}
			}*/

			Iterator<T> beg(tree), en(tree);
			beg = tree.begin();
			en = tree.end();
			algorithm.copy(beg, en, outputIterator);
			cout << endl << "����� ���������: " << algorithm.calculateCountOfNodes(beg, en) << endl;
			cout << "������ ������: " << tree.height() << endl;
			break;
		}
		case '3':
		{
			system("cls");
			obj.title();
			obj.header();

	/*		if (!tree.Empty())
			{
				iterator = tree.begin();
				while (iterator != tree.end())
				{
					cout << *iterator << endl;
					++iterator;
				}
			}*/

			Iterator<T> beg(tree), en(tree);
			beg = tree.begin();
			en = tree.end();
			algorithm.copy(beg, en, outputIterator);
			cout << endl;
			cout << "����� ������� �� ������ ��������?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			if (ptr != nullptr)
			{
				(ptr->key).change();
				cout << "������� " << temp.getModel() << " ������� �������." << endl;
			}
			else
			{
				cout << "������ �� �������." << endl;
			}
			break;
		}
		case '4':
		{
			system("cls");
			obj.title();
			obj.header();
			
			/*if (!tree.Empty())
			{
				iterator = tree.begin();
				while (iterator != tree.end())
				{
					cout << *iterator << endl;
					++iterator;
				}
			}*/

			Iterator<T> beg(tree), en(tree);
			beg = tree.begin();
			en = tree.end();
			algorithm.copy(beg, en, outputIterator);
			cout << endl;
			cout << "����� ������� �� ������ �������?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			if (ptr != nullptr)
			{
				tree.deleteNode(ptr);
				cout << "������� " << temp.getModel() << " ������� ������." << endl;
			}
			else
			{
				cout << "������ �� �������." << endl;
			}
			break;
		}
		case '5':
		{
			system("cls");
			obj.title();
			tree.removeTree();
			cout << "��� �������� �� ������ ���� �������." << endl;
			break;
		}
		case '6':
		{
			system("cls");
			T temp;
			bool flag[8] = { false, false, false, false, false, false, false, false };
			temp.search(flag);
			Iterator<T> beg(tree), en(tree);
			beg = tree.begin();
			en = tree.end();
			system("cls");
			algorithm.search(beg, en, temp, flag);
			break;
		}
		case '7':
		{
			system("cls");
			obj.title();
			Iterator<T> beg(tree), en(tree);
			beg = tree.begin();
			en = tree.end();
			int count = algorithm.calculateCountOfNodes(beg, en);
			T* arr = algorithm.toArray(beg, en);
			tree.removeTree();
			this->obj.changeField();
			algorithm.sortArray(arr, count);
			algorithm.toTree(arr, 0, count);
			delete[] arr;
			cout << "������ ������� �����������." << endl;
			break;
		}
		case '8':
		{
			system("cls");
			obj.title();

			Iterator<T> first(tree), last(tree);
			first = tree.begin();
			last = tree.end();

			cout << "\t1. �������� � ��������� ����." << endl
				<< "\t2. �������� � �������� ����." << endl
				<< "\t0. �����." << endl
				<< endl << "\t  >> ";
			char ch = _getch();
			cout << ch << endl << endl;

			/*switch (ch)
			{
			case '1':
				algorithm.writeToTextFile(beg, en, textFile);
				cout << "������� ������� �������� � ��������� ����." << endl;
				break;
			case '2':
				algorithm.writeToBinaryFile(beg, en, binaryFile);
				cout << "������� ������� �������� � �������� ����." << endl;
				break;
			case '0':
				break;
			default:
				break;
			}*/

			switch (ch)
			{
			case '1':
			{
				textFile.openForWrite();
				while (first != last)
				{
					textFile.write(*first);
					++first;
				}
				textFile.closeWrite();
				//algorithm.writeToTextFile(beg, en, textFile);
				cout << "������� ������� �������� � ��������� ����." << endl;
				break;
			}
			case '2':
			{
				binaryFile.openForWrite();
				while (first != last)
				{
					binaryFile.write(*first);
					++first;
				}
				binaryFile.closeWrite();
				//algorithm.writeToBinaryFile(beg, en, binaryFile);
				cout << "������� ������� �������� � �������� ����." << endl;
				break;
			}
			case '0':
				break;
			default:
				break;
			}

			break;
		}
		case '9':
		{
			system("cls");
			obj.title();

			Iterator<T> first(tree), last(tree);
			first = tree.begin();
			last = tree.end();

			cout << "\t1. ��������� �� ���������� �����." << endl
				<< "\t2. ��������� �� ��������� �����." << endl
				<< "\t0. �����." << endl
				<< endl << "\t  >> ";
			char ch = _getch();
			cout << ch << endl << endl;
			int count = 0;

			/*switch (ch)
			{
			case '1':
				count = algorithm.readFromTextFile(textFile);
				cout << endl;
				cout << "��������� "<< count <<" �������� �� ���������� �����." << endl;
				break;
			case '2':
				count = algorithm.readFromBinaryFile(binaryFile);
				cout << endl;
				cout << "��������� " << count << " �������� �� ��������� �����." << endl;\
				break;
			case '0':
				break;
			default:
				break;
			}*/

			switch (ch)
			{
			case '1':
			{
				//count = algorithm.readFromTextFile(textFile);
				T temp;
				int count = 0;
				temp.header();

				textFile.openForRead();
				while (true)
				{
					textFile.read(temp);
					if (textFile.endFile())
						break;
					cout << temp << endl;
					tree.add(temp);
					++count;
				}
				textFile.closeRead();

				cout << endl;
				cout << "��������� " << count << " �������� �� ���������� �����." << endl;
				break;
			}
			case '2':
			{
				//count = algorithm.readFromBinaryFile(binaryFile);
				T temp;
				int count = 0;
				temp.header();

				binaryFile.openForRead();
				while (true)
				{
					binaryFile.read(temp);
					if (binaryFile.endFile())
						break;
					cout << temp << endl;
					tree.add(temp);
					++count;
				}
				binaryFile.closeRead();

				cout << endl;
				cout << "��������� " << count << " �������� �� ��������� �����." << endl;
				break;
			}
			case '0':
				break;
			default:
				break;
			}

			break;
		}
		case '0': 
			break;
		default:
			cout << endl;
			cout << "������������ ����." << endl;
			break;
		}
		cout << "������� ����� ������ ��� �����������...";
		system("pause > nul");
	} while (choice != '0');

}
