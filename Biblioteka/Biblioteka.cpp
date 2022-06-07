#include <iostream>
#include "Biblioteka.h"
#include "Book.h"
#include "Human.h"
using namespace std;

Biblioteka::Biblioteka(Book* books_arr, int count_of_books, Human* visitors_arr, int count_of_visitors, const char* library_name)
{
	// clear all pointer fields
	if (this->books_arr != nullptr)delete[] this->books_arr;
	if (this->visitors_arr != nullptr)delete[] this->visitors_arr;
	if (this->library_name != nullptr)delete[] this->library_name;

	// set new count of books and visiters
	this->count_of_books = count_of_books;
	this->count_of_visitors = count_of_visitors;

	// get memory from heap for array of books and visitors
	this->books_arr = new Book[count_of_books];
	this->visitors_arr = new Human[count_of_visitors];

	// get memory from heap for library name
	this->library_name = new char[strlen(library_name) + 1];


	// copy books and visitors from array
	for (int i = 0; i < count_of_books; i++)
	{
		this->books_arr[i] = books_arr[i];
	}
	for (int i = 0; i < count_of_visitors; i++)
	{
		this->visitors_arr[i] = visitors_arr[i];
	}

	// copy lib name from param
	strcpy_s(this->library_name, strlen(library_name) + 1, library_name);

	logs = new char* [++logs_counter];
	logs[0] = new char[26];
	strcpy_s(logs[0], 26, "Library has been created\n");
}

Book* Biblioteka::getBooksArr()
{
	return books_arr;
}

Human* Biblioteka::getVisitorsArr()
{
	return visitors_arr;
}

int Biblioteka::getCountOfBooks()
{
	return count_of_books;
}

int Biblioteka::getCountOfVisitors()
{
	return count_of_visitors;
}

void Biblioteka::output()
{
	this->addLog("Library output\n");

	cout << library_name << endl;
	cout << "Our books: " << endl;
	for (int i = 0; i < count_of_books; i++)
	{
		cout << books_arr[i].GetNazvanie() << endl;
	}
}

void Biblioteka::output_books()
{
	this->addLog("Book output\n");
	for (int i = 0; i < count_of_books; i++)
	{
		books_arr[i].PrintBook();
		cout << endl;
	}
}

void Biblioteka::output_visitors()
{
	for (int i = 0; i < count_of_visitors; i++)
	{
		visitors_arr[i].PrintHuman();
	}
}

void Biblioteka::output_logs()
{
	this->addLog("Logs output\n");
	for (int i = 0; i < logs_counter; i++)
	{
		cout << logs[i];
	}
}

void Biblioteka::addBook()
{
	this->addLog("Book was added");
	Book new_book;
	new_book.AddBook();

	Book* temp = new Book[count_of_books + 1];

	for (int i = 0; i < count_of_books; i++)
	{
		temp[i] = books_arr[i];
	}

	temp[count_of_books] = new_book;

	count_of_books++;

	delete[] books_arr;
	books_arr = temp;

	temp = nullptr;
}

void Biblioteka::addVisitor()
{
	this->addLog("Visitor was added");
	Human new_vis;
	new_vis.AddHuman();

	Human* temp = new Human[count_of_visitors + 1];

	for (int i = 0; i < count_of_visitors; i++)
	{
		temp[i] = visitors_arr[i];
	}

	temp[count_of_visitors] = new_vis;

	count_of_visitors++;

	delete[] visitors_arr;
	visitors_arr = temp;

	temp = nullptr;
}

void Biblioteka::removeBook(Book* rem_book)
{
	this->addLog("Book was removed");
	Book* temp = new Book[--count_of_books];

	for (int i = 0, j = 0; i < count_of_books; i++, j++)
	{
		if (&(books_arr[j]) == rem_book)j++;
		temp[i] = books_arr[j];
	}

	delete[] books_arr;
	books_arr = temp;

	temp = nullptr;
}

void Biblioteka::removeVisitor(Human* rem_vis)
{
	this->addLog("Visitor was removed\n");

	Human* temp = new Human[--count_of_visitors];

	for (int i = 0, j = 0; i < count_of_visitors; i++, j++)
	{
		if (&(visitors_arr[j]) == rem_vis)j++;
		temp[i] = visitors_arr[j];
	}

	delete[] visitors_arr;
	visitors_arr = temp;

	temp = nullptr;
}



Human* Biblioteka::findVisByID(int id)
{
	this->addLog("Output visitors\n");
	for (int i = 0; i < count_of_visitors; i++)
	{
		if (visitors_arr[i].Getid() == id) return &(visitors_arr[i]);
	}
	return nullptr;
}

void Biblioteka::addLog(const char* new_log)
{
	char** temp = new char* [this->logs_counter + 1];

	for (int i = 0; i < this->logs_counter; i++)
	{
		temp[i] = this->logs[i];
	}

	temp[this->logs_counter] = new char[strlen(new_log) + 1];
	strcpy_s(temp[this->logs_counter], strlen(new_log) + 1, new_log);

	this->logs_counter++;

	delete[] this->logs;

	this->logs = new char* [this->logs_counter];

	for (int i = 0; i < this->logs_counter; i++)
	{
		this->logs[i] = temp[i];
	}

	temp = nullptr;
}

Biblioteka::~Biblioteka()
{
	if (this->books_arr != nullptr)delete[] this->books_arr;
	if (this->visitors_arr != nullptr)delete[] this->visitors_arr;
	if (this->library_name != nullptr)delete[] this->library_name;

	for (int i = 0; i < logs_counter; i++)
	{
		delete[] logs[i];
	}
	delete[] logs;
}


