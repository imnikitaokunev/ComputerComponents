#include "CPU.h"

void CPU::setCountOfCores(int cores)
{
	countOfCores = cores;
}

void CPU::setBaseFrequency(int freq)
{
	baseFrequency = freq;
}

int CPU::getCountOfCores() const
{
	return countOfCores;
}

int CPU::getBaseFrequency() const
{
	return baseFrequency;
}

void CPU::title()
{
	cout << setw(67) << "---Процессоры---" << endl;
}

void CPU::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(8) << "Cores" << setw(4) << "|" << setw(8)
		<< "Freq." << endl;

	cout << setw(57) << "-----------|----------|-----------|----------" << endl;
}

void CPU::change()
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
			<< "\t3. Количество ядер процессора." << endl
			<< "\t4. Базовая частота процессора." << endl
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
			cout << "Новое количество ядер процессора: ";
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '4':
			cout << "Новая базовая частота процесора: ";
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}
		cout << "Нажмите любую кнопку, чтобы изменить что-то еще." << endl;
		cout << "Если вы больше не хотите что-то изменить, нажмите 0:   ";
		choice = _getch();
		cout << choice << endl;

	} while (choice != '0');

}

void CPU::search(bool* flag)
{
	CPU temp;
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  По каким полям вы желаете совершить поиск?" << endl;
		cout << "\t1. Модель." << endl
			<< "\t2. Стоимость." << endl
			<< "\t3. Количество ядер процессора." << endl
			<< "\t4. Базовая частота процессора." << endl
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
			cout << "Количество ядер процессора: ";
			flag[COUNTOFCORES] = true;
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '4':
			cout << "Базовая частота процесора: ";
			flag[BASEFREQUENCY] = true;
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "Некорректный ввод." << endl;;
			system("pause");
			break;
		}
		cout << "Нажмите любую кнопку, чтобы добавить что-то еще." << endl;
		cout << "Если вы не хотите добавить что-то еще, нажмите 0:   ";
		choice = _getch();
		cout << choice << endl;

	} while (choice != '0');

}

void CPU::changeField()
{
	char choice;

	system("cls");
	this->title();
	cout << endl;
	cout << "  По какому полю построить дерево?" << endl;
	cout << "\t1. Модель." << endl
		<< "\t2. Стоимость." << endl
		<< "\t3. Количество ядер процессора." << endl
		<< "\t4. Базовая частота процессора." << endl
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
		field = COUNTOFCORES;
		break;
	case '4':
		field = BASEFREQUENCY;
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

bool CPU::isEqual(CPU& other)
{
	if (field == COST)
		if (this->cost == other.cost)
			return true;
	if (field == MODEL)
		if (this->model == other.model)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency == other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores == other.countOfCores)
			return true;

	return false;
}

bool CPU::isEqual(CPU& other, bool* flag)
{
	if (flag[COST] == true)
		if (this->cost != other.cost)
			return false;
	if (flag[MODEL] == true)
		if (this->model != other.model)
			return false;	
	if (flag[BASEFREQUENCY] == true)
		if (this->baseFrequency != other.baseFrequency)
			return false;
	if (flag[COUNTOFCORES] == true)
		if (this->countOfCores != other.countOfCores)
			return false;

	return true;
}

bool CPU::operator==(CPU& other)
{
	if (this->cost != other.cost)
		return false;
	if (this->model != other.model)
		return false;
	if (this->baseFrequency != other.baseFrequency)
		return false;
	if (this->countOfCores != other.countOfCores)
		return false;

	return true;
}

bool CPU::operator>(CPU& other)
{
	if (field == COST)
		if (this->cost > other.cost)
			return true;
	if (field == MODEL)
		if (this->model > other.model)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency > other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores > other.countOfCores)
			return true;

	return false;
}

bool CPU::operator<(CPU& other)
{
	if (field == COST)
		if (this->cost < other.cost)
			return true;
	if (field == MODEL)
		if (this->model < other.model)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency < other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores < other.countOfCores)
			return true;

	return false;
}

istream& operator >> (istream& in, CPU& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "Количество ядер: ";
	obj.countOfCores = inputNumber(MIN, MAXCORES);
	cout << "Базовая частота: ";
	obj.baseFrequency = inputNumber(MIN, MAXFREQUENCY);
	return in;
}

ostream& operator << (ostream& out, CPU& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	out << setw(4) << "|" << setw(8) << obj.countOfCores << setw(4) << "|" << setw(8)
		<< obj.baseFrequency;
	return out;
}

ifstream& operator >> (ifstream& fin, CPU& obj)
{
	fin >> dynamic_cast<ElectronicDevice&> (obj);
	fin >> obj.countOfCores;
	fin >> obj.baseFrequency;
	fin.get();

	return fin;
}

ofstream& operator << (ofstream& fout, CPU& obj)
{
	fout << dynamic_cast<ElectronicDevice&> (obj);
	fout << ' ' << obj.countOfCores << ' ' << obj.baseFrequency;

	return fout;
}

void CPU::writeToBinary(ofstream& out, CPU& obj)
{
	out.write(obj.model.c_str(), sizeof(obj.model));
	out.write(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	out.write(reinterpret_cast<char*>(&obj.countOfCores), sizeof(obj.countOfCores));
	out.write(reinterpret_cast<char*>(&obj.baseFrequency), sizeof(obj.baseFrequency));
	out.write("\n", sizeof("\n"));
}

void CPU::readFromBinary(ifstream& in, CPU& obj)
{
	in.read(const_cast<char*>(obj.model.c_str()), sizeof(obj.model));
	in.read(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	in.read(reinterpret_cast<char*>(&obj.countOfCores), sizeof(obj.countOfCores));
	in.read(reinterpret_cast<char*>(&obj.baseFrequency), sizeof(obj.baseFrequency));
	string buf;
	getline(in, buf, '\n');
	in.get();
}
