#pragma once
#include "Genre.h"
#include "Author.h"
#include "Publisher.h"
#include <iostream>

using namespace St;
using namespace std;

class Literature
{
protected:
	std::string name;
	Genre genre;
	Publisher publisher;
	int publishingYear;
public:
	Literature();
	Literature(string name, string genre, string publisher, int publishingYear);
	~Literature();
	virtual void Input();
};

