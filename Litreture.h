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
	virtual string GetName()
	{
		return name;
	}
	virtual string GetPublisher()
	{
		return publisher.publisherName;
	}
	virtual int GetYear()
	{
		return publishingYear;
	}
	virtual string GetGenre()
	{
		return genre.genreName;
	}
	virtual void Input()
	{

		string year;
		cout << "������� ��������: ";
		getline(cin, name);
		cout << "\n���� : ";
		getline(cin, genre.genreName);
		cout << "\n��������: ";
		getline(cin, publisher.publisherName);
		cout << "\n��� ����������: ";
		getline(cin, year);
		publishingYear = stoi(year);
	};
};

