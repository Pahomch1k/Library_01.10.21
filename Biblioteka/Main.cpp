#include <iostream>
#include "Book.h"
#include "Human.h"
#include "Biblioteka.h"
using namespace std;



int main()
{
	setlocale(0, "");
	Book book1;
	book1.AddBook();
	book1.PrintBook();

	Human human1;
	human1.AddHuman();
	human1.PrintHuman();

}
