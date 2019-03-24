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
	cout << setw(67) << "---����������---" << endl;
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

istream& operator >>(istream& in, Computer& obj)
{
	in >> dynamic_cast<CPU&> (obj);
	cout << "����� �����������: ";
	obj.memorySize = inputNumber(MIN, MAXVRAM);
	cout << "��� ���: ";
	obj.memoryType = inputStringWithNums();
	cout << "������� ���: ";
	obj.capacity = inputNumber(MIN, MAXCAPACITY);
	cout << "���������: ";
	obj.drive = inputNumber(MIN, MAXDRIVE);
	return in;
}

void Computer::change()
{
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  ����� ���� �� ������� ��������?" << endl;
		cout << "\t1. ������." << endl
			<< "\t2. ���������." << endl
			<< "\t3. ��� ���." << endl
			<< "\t4. ����� ���." << endl
			<< "\t5. ����� �����������." << endl
			<< "\t6. ���������� ���� ����������." << endl
			<< "\t7. ������� ������� ����������." << endl
			<< "\t8. ����� ����������." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl << endl;

		switch (choice)
		{
		case '1':
			cout << "����� ������: "; 
			this->model = inputStringWithNums();
			break;
		case '2':
			cout << "����� ���������: ";
			this->cost = inputNumber(MIN, MAX);
			break;
		case '3':
			cout << "����� ��� ���: ";
			this->memoryType = inputStringWithNums();
			break;
		case '4':
			cout << "����� ����� ���: ";
			this->capacity = inputNumber(MIN, MAXCAPACITY);
			break;
		case '5':
			cout << "����� ����� �����������: ";
			this->memorySize = inputNumber(MIN, MAXVRAM);
			break;
		case '6':
			cout << "����� ���������� ���� ����������: ";
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '7':
			cout << "����� ������� ������� ���������: ";
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '8':
			cout << "����� ����� ����������: ";
			this->drive = inputNumber(MIN, MAXDRIVE);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "������������ ����." << endl;;
			system("pause");
			break;
		}
		cout << "������� �������� ���-�� ���?(1 - ��/0 - ���) ";
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
		cout << "  �� ����� ����� �� ������� ��������� �����?" << endl;
		cout << "\t1. ������." << endl
			<< "\t2. ���������." << endl
			<< "\t3. ��� ���." << endl
			<< "\t4. ����� ���." << endl
			<< "\t5. ����� �����������." << endl
			<< "\t6. ���������� ���� ����������." << endl
			<< "\t7. ������� ������� ����������." << endl
			<< "\t8. ����� ����������." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl << endl;

		switch (choice)
		{
		case '1':
			cout << "������: ";
			flag[MODEL] = true;
			this->model = inputStringWithNums();
			break;
		case '2':
			cout << "���������: ";
			flag[COST] = true;
			this->cost = inputNumber(MIN, MAX);
			break;
		case '3':
			cout << "��� ���: ";
			flag[MEMORYTYPE] = true;
			this->memoryType = inputStringWithNums();
			break;
		case '4':
			cout << "����� ���: ";
			flag[CAPACITY] = true;
			this->capacity = inputNumber(MIN, MAXCAPACITY);
			break;
		case '5':
			cout << "����� �����������: ";
			flag[MEMORYSIZE] = true;
			this->memorySize = inputNumber(MIN, MAXVRAM);
			break;
		case '6':
			cout << "���������� ���� ����������: ";
			flag[COUNTOFCORES] = true;
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '7':
			cout << "������� ������� ���������: ";
			flag[BASEFREQUENCY] = true;
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '8':
			cout << "����� ����������: ";
			flag[DRIVE] = true;
			this->drive = inputNumber(MIN, MAXDRIVE);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "������������ ����." << endl;;
			system("pause");
			break;
		}
		cout << "������� �������� ���-�� ���?(1 - ��/0 - ���) ";
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
	cout << "  �� ������ ���� ��������� ������?" << endl;
	cout << "\t1. ������." << endl
		<< "\t2. ���������." << endl
		<< "\t3. ��� ���." << endl
		<< "\t4. ����� ���." << endl
		<< "\t5. ����� �����������." << endl
		<< "\t6. ���������� ���� ����������." << endl
		<< "\t7. ������� ������� ����������." << endl
		<< "\t8. ����� ����������." << endl
		<< "\t0. �����." << endl
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
		cout << "������������ ����." << endl;;
		system("pause");
		break;
	}
}

ostream& operator <<(ostream& out, Computer& obj)
{
	out << dynamic_cast <CPU&> (obj);
	out << setw(4) << "|" << setw(7) << obj.memorySize << setw(4) << "|" << setw(6)
		<< obj.memoryType << setw(4) << "|" << setw(11) << obj.capacity << setw(4)
		<< "|" << setw(8) << obj.drive;
	return out;
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

bool Computer::isEqual(Computer& other, bool *flag)
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
