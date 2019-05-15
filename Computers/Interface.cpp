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
			cout << "Некорректный ввод." << endl;;
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
		cout << "\t1. Добавить." << endl
			<< "\t2. Просмотреть." << endl
			<< "\t3. Изменить." << endl
			<< "\t4. Удалить." << endl
			<< "\t5. Удалить все." << endl
			<< "\t6. Поиск." << endl
			<< "\t7. Перестроить." << endl
			<< "\t8. Записать в файл." << endl
			<< "\t9. Прочитать из файла." << endl
			<< "\t0. Выход." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl;

		switch (choice)
		{
		case '1':
		{
			system("cls");
			obj.title();										
			cout << "Добавление нового элемента" << endl;
			T temp;
			cin >> temp;
			tree.add(temp);
			cout << "Элемент " << temp.getModel() << " успешно добавлен." << endl;
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
			cout << endl << "Всего элементов: " << algorithm.calculateCountOfNodes(beg, en) << endl;
			cout << "Высота дерева: " << tree.height() << endl;
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
			cout << "Какой элемент вы хотите изменить?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			if (ptr != nullptr)
			{
				(ptr->key).change();
				cout << "Элемент " << temp.getModel() << " успешно изменен." << endl;
			}
			else
			{
				cout << "Ничего не найдено." << endl;
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
			cout << "Какой элемент вы хотите удалить?" << endl;
			T temp;
			cin >> temp;
			Node<T>* ptr = tree.find(temp);
			if (ptr != nullptr)
			{
				tree.deleteNode(ptr);
				cout << "Элемент " << temp.getModel() << " успешно удален." << endl;
			}
			else
			{
				cout << "Ничего не найдено." << endl;
			}
			break;
		}
		case '5':
		{
			system("cls");
			obj.title();
			tree.removeTree();
			cout << "Все элементы из дерева были удалены." << endl;
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
			cout << "Дерево успешно перестроено." << endl;
			break;
		}
		case '8':
		{
			system("cls");
			obj.title();

			Iterator<T> first(tree), last(tree);
			first = tree.begin();
			last = tree.end();

			cout << "\t1. Записать в текстовый файл." << endl
				<< "\t2. Записать в бинарный файл." << endl
				<< "\t0. Назад." << endl
				<< endl << "\t  >> ";
			char ch = _getch();
			cout << ch << endl << endl;

			/*switch (ch)
			{
			case '1':
				algorithm.writeToTextFile(beg, en, textFile);
				cout << "Объекты успешно записаны в текстовый файл." << endl;
				break;
			case '2':
				algorithm.writeToBinaryFile(beg, en, binaryFile);
				cout << "Объекты успешно записаны в бинарный файл." << endl;
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
				cout << "Объекты успешно записаны в текстовый файл." << endl;
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
				cout << "Объекты успешно записаны в бинарный файл." << endl;
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

			cout << "\t1. Прочитать из текстового файла." << endl
				<< "\t2. Прочитать из бинарного файла." << endl
				<< "\t0. Назад." << endl
				<< endl << "\t  >> ";
			char ch = _getch();
			cout << ch << endl << endl;
			int count = 0;

			/*switch (ch)
			{
			case '1':
				count = algorithm.readFromTextFile(textFile);
				cout << endl;
				cout << "Прочитано "<< count <<" объектов из текстового файла." << endl;
				break;
			case '2':
				count = algorithm.readFromBinaryFile(binaryFile);
				cout << endl;
				cout << "Прочитано " << count << " объектов из бинарного файла." << endl;\
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
				cout << "Прочитано " << count << " объектов из текстового файла." << endl;
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
				cout << "Прочитано " << count << " объектов из бинарного файла." << endl;
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
			cout << "Некорректный ввод." << endl;
			break;
		}
		cout << "Нажмите любую кнопку для продолжения...";
		system("pause > nul");
	} while (choice != '0');

}
