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
	char choice;
	do
	{
		system("cls");
		obj.title();
		cout << "\t1. Добавить." << endl
			<< "\t2. Просмотреть." << endl
			<< "\t3. *Редактировать." << endl
			<< "\t4. Удалить." << endl
			<< "\t5. Удалить все." << endl
			<< "\t6. Поиск." << endl
			<< "\t7. Сортировка." << endl
			<< "\t8. Отмена последних изменений." << endl
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
			tree.show();
			cout << endl;
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			cout << "Введите элемент, который вы хотите удалить." << endl;
			T temp;
			bool flag[8] = { true, true, true, true, true, true, true, true };
			cin >> temp;
			Node<T>* ptr = tree.find(temp, flag);
			cout << endl;
			if (ptr != nullptr)
			{
				tree.remove(ptr, flag);
				cout << "Элемент " << temp.getModel() << " успешно удален." << endl;
			}
			else
				cout << "Ничего не найдено." << endl;
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
			cout << "Введите модель: ";
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
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}
	} while (choice != '0');
}
