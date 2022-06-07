#include <iostream>
#include "Book.h"
#include "Human.h"
#include "Biblioteka.h"

using namespace std;

Book::Book()
{
	nazvanie = nullptr;
	avtor = nullptr;
	janr = nullptr;
	svobodna = true;
	number = 0;
}

Book::Book(const char* nazvanie, const char* janr, const char* avtor)
{
	this->nazvanie = new char[strlen(nazvanie) + 1];
	this->janr = new char[strlen(janr) + 1];
	this->avtor = new char[strlen(avtor) + 1];

	strcpy_s(this->nazvanie, strlen(nazvanie) + 1, nazvanie);
	strcpy_s(this->janr, strlen(janr) + 1, janr);
	strcpy_s(this->avtor, strlen(avtor) + 1, avtor);
}

Book::Book(const Book& other)
{
	this->nazvanie = new char[strlen(other.nazvanie) + 1];
	this->janr = new char[strlen(other.janr) + 1];
	this->avtor = new char[strlen(other.avtor) + 1];

	strcpy_s(this->nazvanie, strlen(other.nazvanie) + 1, other.nazvanie);
	strcpy_s(this->janr, strlen(other.janr) + 1, other.janr);
	strcpy_s(this->avtor, strlen(other.avtor) + 1, other.avtor);
}

Book::~Book()
{
	delete[] nazvanie;
	delete[] avtor;
	delete[] janr;
}

void Book::AddBook()
{
	srand(time(0));
	nazvanie = new char[100];
	avtor = new char[100];
	janr = new char[10];
	number++;

	cout << "Введите название " << endl;
	cin >> nazvanie;
	cout << "Введите автора " << endl;
	cin >> avtor;
	cout << "Введите жанр " << endl;
	cin >> janr;
}

void Book::PrintBook()
{
	setlocale(0, "");
	cout << "Название " << nazvanie << endl;
	cout << "Автор " << avtor << endl;
	cout << "Жанр " << janr << endl;
	cout << "Свободна " << svobodna << endl;
	cout << "Номер " << number << endl;
}

const char* Book::GetNazvanie()
{
	return nazvanie;
}

void Book::SetNazvanie(const char* col)
{
	if (this->nazvanie != nullptr)
		delete[]nazvanie;
	this->nazvanie = new char[strlen(col) + 1];
	strcpy_s(this->nazvanie, strlen(col) + 1, col);
}

const char* Book::GetAvtor()
{
	return avtor;
}

void Book::SetAvtor(const char* col)
{
	if (this->avtor != nullptr)
		delete[]avtor;
	this->avtor = new char[strlen(col) + 1];
	strcpy_s(this->avtor, strlen(col) + 1, col);
}

const char* Book::GetJanr()
{
	return janr;
}

void Book::SetJanr(const char* col)
{
	if (this->janr != nullptr)
		delete[]janr;
	this->janr = new char[strlen(col) + 1];
	strcpy_s(this->janr, strlen(col) + 1, col);
}
