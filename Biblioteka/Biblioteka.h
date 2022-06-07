#pragma once
#include "Book.h"
#include "Human.h"
class Biblioteka
{
	Book* books_arr = nullptr;
	int count_of_books = 0;
	Human* visitors_arr = nullptr;
	int count_of_visitors = 0;
	char* library_name = nullptr;
	char** logs = nullptr;
	int logs_counter = 0;

public:

	Biblioteka() = default;
	Biblioteka(Book * books_arr, int count_of_books, Human* visitors_arr, int count_of_visitors, const char* library_name);

	Book* getBooksArr();
	Human* getVisitorsArr();
	int getCountOfBooks();
	int getCountOfVisitors();

	void output();
	void output_books();
	void output_visitors();
	void output_logs();

	void addBook();
	void addVisitor();

	void removeBook(Book * rem_book);
	void removeVisitor(Human* rem_vis);

	Human* findVisByID(int id);
	void addLog(const char* new_log);
	~Biblioteka();
};

