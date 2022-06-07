#pragma once
class Book
{
	char* nazvanie;
	char* avtor;
	char* janr;
	bool svobodna;
	int number;
public:
	Book() = default;
	Book(const char* nazvanie, const char* janr, const char* avtor);
	Book(const Book& other);

	~Book();
	void AddBook();
	void PrintBook();

	const char* GetNazvanie();
	void SetNazvanie(const char* col);

	const char* GetAvtor();
	void SetAvtor(const char* col);

	const char* GetJanr();
	void SetJanr(const char* col);
};

