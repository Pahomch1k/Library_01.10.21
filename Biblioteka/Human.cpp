#include <iostream>
#include "Book.h"
#include "Human.h"
#include "Biblioteka.h"
using namespace std;

Human::Human()
{
	name = nullptr;
	suname = nullptr;
	id = 0;
	skolko_knig_vzayl = 0;
	skolko_knig_otdal = 0;
	book_on_hand = 0;
}

Human::~Human()
{
	delete[] name;
	delete[] suname;
}

void Human::AddHuman()
{
	srand(time(0));
	name = new char[100];
	suname = new char[100];

	cout << "Введите имя " << endl;
	cin >> name;
	cout << "Введите фамилию " << endl;
	cin >> suname;
	id = rand() % 9999999;
}

void Human::PrintHuman()
{
	setlocale(0, "");
	cout << "Имя " << name << endl;
	cout << "Фамилия " << suname << endl;
	cout << "ID " << id << endl;
	cout << "Сколько книг взял " << skolko_knig_vzayl << endl;
	cout << "Сколько книг отдал " << skolko_knig_otdal << endl;
	cout << "Сколько книг на руках " << book_on_hand << endl;
}

const char* Human::GetName()
{
	return name;
}

void Human::SetName(const char* col)
{
	if (this->name != nullptr)
		delete[]name;
	this->name = new char[strlen(col) + 1];
	strcpy_s(this->name, strlen(col) + 1, col);
}

const char* Human::GetSuname()
{
	return suname;
}

void Human::SetSuname(const char* col)
{
	if (this->suname != nullptr)
		delete[]suname;
	this->suname = new char[strlen(col) + 1];
	strcpy_s(this->suname, strlen(col) + 1, col);
}

int Human::Getid()
{
	return id;
}
