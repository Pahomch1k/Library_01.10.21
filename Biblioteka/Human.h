#pragma once
class Human
{
	char* name;
	char* suname;
	int id;
	int skolko_knig_vzayl;
	int skolko_knig_otdal;
	int book_on_hand;

public:
	Human();
	~Human();
	void AddHuman();
	void PrintHuman();

	const char* GetName();
	void SetName(const char* col);

	const char* GetSuname();
	void SetSuname(const char* col);

	int Getid();
};

