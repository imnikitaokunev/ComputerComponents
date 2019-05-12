#include "Computer.h"


void Computer::setDrive(int dr)
{
	drive = dr;
}

int Computer::getDrive() const
{
	return drive;
}

void Computer::title()
{
	cout << setw(67) << "---Компьютеры---" << endl;
}

void Computer::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(8) << "Cores" << setw(4) << "|" << setw(8)
		<< "Freq." << setw(4) << "|" << setw(7) << "VRAM" << setw(4) << "|" 
		<< setw(6) << "RAM" << setw(4) << "|" << setw(11) << "Capacity" << setw(4)
		<< "|" << setw(8) << "Drive" << endl;
	cout << setw(105) << "----------|----------|-----------|-----------|----------|---------|--------------|----------" << endl;
}

void Computer::change()
{
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  Какие поля вы желаете изменить?" << endl;
		cout << "\t1. Модель." << endl
			<< "\t2. Стоимость." << endl
			<< "\t3. Тип ОЗУ." << endl
			<< "\t4. Объем ОЗУ." << endl
			<< "\t5. Объем видеопамяти." << endl
			<< "\t6. Количество ядер процессора." << endl
			<< "\t7. Базовая частота процессора." << endl
			<< "\t8. Объем винчестера." << endl
			<< "\t0. Назад." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl << endl;

		switch (choice)
		{
		case '1':
			cout << "Новая модель: ";
			this->model = inputStringWithNums();
			break;
		case '2':
			cout << "Новая стоимость: ";
			this->cost = inputNumber(MIN, MAX);
			break;
		case '3':
			cout << "Новый тип ОЗУ: ";
			this->memoryType = inputStringWithNums();
			break;
		case '4':
			cout << "Новый объем ОЗУ: ";
			this->capacity = inputNumber(MIN, MAXCAPACITY);
			break;
		case '5':
			cout << "Новый объем видеопамяти: ";
			this->memorySize = inputNumber(MIN, MAXVRAM);
			break;
		case '6':
			cout << "Новое количество ядер процессора: ";
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '7':
			cout << "Новая базовая частота процесора: ";
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '8':
			cout << "Новый объем винчестера: ";
			this->drive = inputNumber(MIN, MAXDRIVE);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}
		cout << "Желаете изменить что-то еще?(1 - да/0 - нет) ";
		choice = _getch();
		cout << choice << endl;

	} while (choice != '0');

}

void Computer::search(bool* flag)
{
	Computer temp;
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  По каким полям вы желаете совершить поиск?" << endl;
		cout << "\t1. Модель." << endl
			<< "\t2. Стоимость." << endl
			<< "\t3. Тип ОЗУ." << endl
			<< "\t4. Объем ОЗУ." << endl
			<< "\t5. Объем видеопамяти." << endl
			<< "\t6. Количество ядер процессора." << endl
			<< "\t7. Базовая частота процессора." << endl
			<< "\t8. Объем винчестера." << endl
			<< "\t0. Назад." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl << endl;

		switch (choice)
		{
		case '1':
			cout << "Модель: ";
			flag[MODEL] = true;
			this->model = inputStringWithNums();
			break;
		case '2':
			cout << "Стоимость: ";
			flag[COST] = true;
			this->cost = inputNumber(MIN, MAX);
			break;
		case '3':
			cout << "Тип ОЗУ: ";
			flag[MEMORYTYPE] = true;
			this->memoryType = inputStringWithNums();
			break;
		case '4':
			cout << "Объем ОЗУ: ";
			flag[CAPACITY] = true;
			this->capacity = inputNumber(MIN, MAXCAPACITY);
			break;
		case '5':
			cout << "Объем видеопамяти: ";
			flag[MEMORYSIZE] = true;
			this->memorySize = inputNumber(MIN, MAXVRAM);
			break;
		case '6':
			cout << "Количество ядер процессора: ";
			flag[COUNTOFCORES] = true;
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '7':
			cout << "Базовая частота процесора: ";
			flag[BASEFREQUENCY] = true;
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '8':
			cout << "Объем винчестера: ";
			flag[DRIVE] = true;
			this->drive = inputNumber(MIN, MAXDRIVE);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}
		cout << "Желаете добавить что-то еще?(1 - да/0 - нет) ";
		choice = _getch();
		cout << choice << endl;

	} while (choice != '0');

}

void Computer::changeField()
{
	char choice;

	system("cls");
	this->title();
	cout << endl;
	cout << "  По какому полю построить дерево?" << endl;
	cout << "\t1. Модель." << endl
		<< "\t2. Стоимость." << endl
		<< "\t3. Тип ОЗУ." << endl
		<< "\t4. Объем ОЗУ." << endl
		<< "\t5. Объем видеопамяти." << endl
		<< "\t6. Количество ядер процессора." << endl
		<< "\t7. Базовая частота процессора." << endl
		<< "\t8. Объем винчестера." << endl
		<< "\t0. Назад." << endl
		<< endl << "\t  >> ";
	choice = _getch();
	cout << choice << endl << endl;

	switch (choice)
	{
	case '1':
		field = MODEL;
		break;
	case '2':
		field = COST;
		break;
	case '3':
		field = MEMORYTYPE;
		break;
	case '4':
		field = CAPACITY;
		break;
	case '5':
		field = MEMORYSIZE;
		break;
	case '6':
		field = COUNTOFCORES;
		break;
	case '7':
		field = BASEFREQUENCY;
		break;
	case '8':
		field = DRIVE;
		break;
	case '0':
		break;
	default:
		cout << endl;
		cout << "Некорректный ввод." << endl;;
		system("pause");
		break;
	}
}

bool Computer::isEqual(Computer& other)
{
	if (field == COST)
		if (this->cost == other.cost)
			return true;
	if (field == MODEL)
		if (this->model == other.model)
			return true;
	if (field == CAPACITY)
		if (this->capacity == other.capacity)
			return true;
	if (field == MEMORYTYPE)
		if (this->memoryType == other.memoryType)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize == other.memorySize)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency == other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores == other.countOfCores)
			return true;
	if (field == DRIVE)
		if (this->drive == other.drive)
			return true;

	return false;
}

bool Computer::isEqual(Computer& other, bool* flag)
{
	if (flag[COST] == true)
		if (this->cost != other.cost)
			return false;
	if (flag[MODEL] == true)
		if (this->model != other.model)
			return false;
	if (flag[CAPACITY] == true)
		if (this->capacity != other.capacity)
			return false;
	if (flag[MEMORYTYPE] == true)
		if (this->memoryType != other.memoryType)
			return false;
	if (flag[MEMORYSIZE] == true)
		if (this->memorySize != other.memorySize)
			return false;
	if (flag[BASEFREQUENCY] == true)
		if (this->baseFrequency != other.baseFrequency)
			return false;
	if (flag[COUNTOFCORES] == true)
		if (this->countOfCores != other.countOfCores)
			return false;
	if (flag[DRIVE] == true)
		if (this->drive != other.drive)
			return false;

	return true;
}

bool Computer::operator==(Computer& other)
{
	if (this->cost != other.cost)
		return false;
	if (this->model != other.model)
		return false;
	if (this->capacity != other.capacity)
		return false;
	if (this->memoryType != other.memoryType)
		return false;
	if (this->memorySize != other.memorySize)
		return false;
	if (this->baseFrequency != other.baseFrequency)
		return false;
	if (this->countOfCores != other.countOfCores)
		return false;
	if (this->drive != other.drive)
		return false;

	return true;
}

bool Computer::operator>(Computer& other)
{
	if (field == COST)
		if (this->cost > other.cost)
			return true;
	if (field == MODEL)
		if (this->model > other.model)
			return true;
	if (field == CAPACITY)
		if (this->capacity > other.capacity)
			return true;
	if (field == MEMORYTYPE)
		if (this->memoryType > other.memoryType)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize > other.memorySize)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency > other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores > other.countOfCores)
			return true;
	if (field == DRIVE)
		if (this->drive > other.drive)
			return true;

	return false;
}

bool Computer::operator<(Computer& other)
{
	if (field == COST)
		if (this->cost < other.cost)
			return true;
	if (field == MODEL)
		if (this->model < other.model)
			return true;
	if (field == CAPACITY)
		if (this->capacity < other.capacity)
			return true;
	if (field == MEMORYTYPE)
		if (this->memoryType < other.memoryType)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize < other.memorySize)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency < other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores < other.countOfCores)
			return true;
	if (field == DRIVE)
		if (this->drive < other.drive)
			return true;

	return false;
}

istream& operator >>(istream& in, Computer& obj)
{
	in >> dynamic_cast<CPU&> (obj);
	cout << "Объем видеопамяти: ";
	obj.memorySize = inputNumber(MIN, MAXVRAM);
	cout << "Тип ОЗУ: ";
	obj.memoryType = inputStringWithNums();
	cout << "Емкость ОЗУ: ";
	obj.capacity = inputNumber(MIN, MAXCAPACITY);
	cout << "Винчестер: ";
	obj.drive = inputNumber(MIN, MAXDRIVE);
	return in;
}

ostream& operator <<(ostream& out, Computer& obj)
{
	out << dynamic_cast <CPU&> (obj);
	out << setw(4) << "|" << setw(7) << obj.memorySize << setw(4) << "|" << setw(6)
		<< obj.memoryType << setw(4) << "|" << setw(11) << obj.capacity << setw(4)
		<< "|" << setw(8) << obj.drive;
	return out;
}

ifstream& operator >> (ifstream &fin, Computer& obj)
{
	fin >> dynamic_cast<ElectronicDevice&>(obj);
	fin >> obj.countOfCores;
	fin >> obj.baseFrequency;
	fin >> obj.capacity;
	fin.get();
	getline(fin, obj.memoryType, '*');
	fin >> obj.memorySize;
	fin >> obj.drive;
	fin.get();

	return fin;
}

ofstream& operator << (ofstream& fout, Computer& obj)
{
	fout << dynamic_cast<ElectronicDevice&> (obj);
	fout << ' ' << obj.countOfCores << ' ' << obj.baseFrequency <<
		' ' << obj.memorySize << ' ' << obj.memoryType << "*" <<
		' ' << obj.capacity << ' ' << obj.drive;

	return fout;
}

void Computer::writeToBinary(ofstream& out, Computer& obj)
{
	out.write(obj.model.c_str(), sizeof(obj.model));
	out.write(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	out.write(reinterpret_cast<char*>(&obj.countOfCores), sizeof(obj.countOfCores));
	out.write(reinterpret_cast<char*>(&obj.baseFrequency), sizeof(obj.baseFrequency));
	out.write(reinterpret_cast<char*>(&obj.capacity), sizeof(obj.capacity));
	out.write(obj.memoryType.c_str(), sizeof(obj.memoryType));
	out.write(reinterpret_cast<char*>(&obj.memorySize), sizeof(obj.memorySize));
	out.write(reinterpret_cast<char*>(&obj.drive), sizeof(obj.drive));
	//out.write("\n", sizeof("\n"));
}

void Computer::readFromBinary(ifstream& in, Computer& obj)
{
	in.read(const_cast<char*>(obj.model.c_str()), sizeof(obj.model));
	in.read(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	in.read(reinterpret_cast<char*>(&obj.countOfCores), sizeof(obj.countOfCores));
	in.read(reinterpret_cast<char*>(&obj.baseFrequency), sizeof(obj.baseFrequency));
	in.read(reinterpret_cast<char*>(&obj.capacity), sizeof(obj.capacity));
	in.read(const_cast<char*>(obj.memoryType.c_str()), sizeof(obj.memoryType));
	in.read(reinterpret_cast<char*>(&obj.memorySize), sizeof(obj.memorySize));
	in.read(reinterpret_cast<char*>(&obj.drive), sizeof(obj.drive));
	//string buf;
	//getline(in, buf, '\n');
	//in.get();
}