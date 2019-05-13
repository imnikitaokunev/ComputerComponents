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
		cout << setw(80) << "-----Меню компьютерных комплектующих-----" << endl;
		cout << "\t1. Процессоры." << endl
			<< "\t2. Оперативная память." << endl
			<< "\t3. Видеокарты." << endl
			<< "\t4. Готовые компьтеры." << endl
			<< "\t0. Выход." << endl
			<< endl << "\t  >> ";
		choice = _getch();

		switch (choice)
		{
		case '1': 
			cpu.fun();
			break;
		case '2': 
			memory.fun();
			break;
		case '3': 
			graphicscard.fun();
			break;
		case '4':
			computer.fun();
			break;
		case '0':
			exit(1);
		default:
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}

	} while (choice != '0');

}

template <class T>
void Interface<T>::fun()
{
	Tree<T> tree;
	Iterator<T> iterator(tree);

	char choice;
	do
	{
		system("cls");
		obj.title();
		cout << "\t1. Добавить." << endl
			<< "\t2. Просмотреть." << endl
			<< "\t3. Изменить." << endl
			<< "\t4. Удалить." << endl
			<< "\t5. Удалить все." << endl
			<< "\t6. Поиск." << endl
			//<< "\t7. Сортировка." << endl
			//<< "\t8. Запись в файл." << endl
			//<< "\t9. Чтение из файла." << endl
			<< "\t0. Выход." << endl
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
			cout << "Элемент " << temp.getModel() << " успешно добавлен." << endl;
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			obj.title();
			cout << endl;
			obj.header();

			if (!tree.Empty())
			{
				iterator = tree.begin();
				while (iterator != tree.end())
				{
					cout << *iterator << endl;
					++iterator;
				}
			}

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

			if (!tree.Empty())
			{
				iterator = tree.begin();
				T tmp;
				while (iterator != tree.end())
				{
					tmp = *iterator;
					cout << tmp << endl;
					++iterator;
				}
			}

			cout << endl;
			cout << "Какой элемент вы хотите изменить?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			cout << endl;
			if (ptr != nullptr)
			{
				ptr->key.change();
				cout << "Элемент " << temp.getModel() << " успешно изменен." << endl;
			}
			else
			{
				cout << "Ничего не найдено." << endl;
			}
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			obj.title();
			cout << endl;
			obj.header();
			
			if (!tree.Empty())
			{
				iterator = tree.begin();
				while (iterator != tree.end())
				{
					cout << *iterator << endl;
					++iterator;
				}
			}

			cout << endl;
			cout << "Какой элемент вы хотите удалить?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			cout << endl;
			if (ptr != nullptr)
			{
				tree.deleteNode(ptr);
				cout << "Элемент " << temp.getModel() << " успешно удален." << endl;
			}
			else
			{
				cout << "Ничего не найдено." << endl;
			}

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
			Algorithm<T> algorithm(tree);
			system("cls");
			T temp;
			bool flag[8] = { false, false, false, false, false, false, false, false };
			temp.search(flag);
			algorithm.search(tree.begin(), tree.end(), temp, flag);
			system("pause");
			break;
		}
		/*case '6':
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
				cout << "  В каком порядке сортировать?" << endl;
				cout << "\t1. По возрастанию." << endl
					<< "\t2. По убыванию." << endl
					<< "\t0. Назад." << endl
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
					cout << "Некорректный ввод." << endl;;
					system("pause");
					break;
				}
			} while (choice != '1' && choice != '2');

			obj.title();
			cout << endl;
			obj.header();
			tree.show();
			cout << endl << "  Успешно отсортировано." << endl;
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
				cout << "  В какой файл записать?" << endl;
				cout << "\t1. Текстовый." << endl
					<< "\t2. Бинарный." << endl
					<< "\t0. Назад." << endl
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
					cout << "Некорректный ввод." << endl;;
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
				cout << "  Из какого файла прочитать?" << endl;
				cout << "\t1. Текстовый." << endl
					<< "\t2. Бинарный." << endl
					<< "\t0. Назад." << endl
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
					cout << "Некорректный ввод." << endl;;
					system("pause");
					break;
				}
			} while (choice != '1' && choice != '2');

			break;
		}*/
		case '0': 
			break;
		default:
			cout << endl;
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}
	} while (choice != '0');

}
