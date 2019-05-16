#pragma once
#include "CPU.h"

class GraphicsCard : virtual public ElectronicDevice
{
protected:
	int memorySize;	//����� �����������
	
public:
	GraphicsCard(string mdl = "", int cst = 0, int mem = 0) : ElectronicDevice(mdl, cst)
	{
		memorySize = mem;
	}
	~GraphicsCard()
	{

	}
	GraphicsCard(const GraphicsCard& other)
	{
		this->cost = other.cost;
		this->model = other.model;
		this->memorySize = other.memorySize;
	}

	void setMemorySize(int mem);
	int getMemorySize() const;
	virtual void title() override;										//��������� � ������ ������
	virtual void header() override;										//��������� �������

	void change();														//�������� ���� � �������
	void search(bool* flag);											//���������� ������ � ������ ��� ������
	void changeField();													//�������� ����, ����������� � field

	bool isEqual(GraphicsCard& other, bool* flag);						//���������� true, ���� this ����� other �� ����, ���������� field
	bool isEqual(GraphicsCard& other);									//���������� true, ���� this ����� other �� ����� �� flag
	bool operator == (GraphicsCard& other);								//���������� true, ���� ������� ����� �� ���� �����
	bool operator >(GraphicsCard& other);								//���������� true, ���� this ������ other �� ����, ���������� � field
	bool operator <(GraphicsCard& other);								//���������� true, ���� this ������ other �� ����, ���������� � field
	friend istream& operator >> (istream& in, GraphicsCard& obj);
	friend ostream& operator << (ostream& out, GraphicsCard& obj);
	friend ifstream& operator >> (ifstream& fin, GraphicsCard& obj);
	friend ofstream& operator << (ofstream& fout, GraphicsCard& obj);
	void writeToBinary(ofstream& fout, GraphicsCard& obj);				//���������� ������ obj � �������� ����
	void readFromBinary(ifstream& fin, GraphicsCard& obj);				//������ ������ obj �� ��������� �����
};
