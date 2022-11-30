#include "Book.h"

St::Book::Book()
{
	name = "din";
	genre.genreName = "Dong";
	author.name = "Dong";
	publisher.publisherName = "Ha-ha";
	publishingYear = 1000;
}

St::Book::Book(string name, string genreName, string publisher, string author, int year) : Literature(name, genreName, publisher, year)
{
	this->author.name = author;
}

void St::Book::SetName(string name)
{
	this->name = name;
}

string St::Book::GetName()
{
	return this->name;
}

void St::Book::SetGenre(string genre)
{
	this->genre.genreName = genre;
}

string St::Book::GetGenre()
{
	return this->genre.genreName;
}

void St::Book::SetAuthor(string author)
{
	this->author.name = author;
}

string St::Book::GetAuthor()
{
	return author.name;
}

void St::Book::SetPublisher(string publisher)
{
	this->publisher.publisherName = publisher;
}

string St::Book::GetPublisher()
{
	return publisher.publisherName;
}

void St::Book::SetYear(string year)
{
	this->publishingYear = stoi(year);
}

void St::Book::SetYear(int year)
{
	this->publishingYear = year;
}

int St::Book::GetYear()
{
	return publishingYear;
}

void St::Book::Input()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string  year;
	std::cout << "Введите данные книги в следующем порядке: название, жанр, автор, издатель, год издания:" << std::endl;
	cout << "Название ";
	getline(cin, name);
	cout << "Жанр ";
	getline(cin, genre.genreName);
	cout << "Автор ";
	getline(cin, author.name);
	cout << "Издатель: ";
	getline(cin, publisher.publisherName);
	cout << "Год издания: ";
	getline(cin, year);
	function<bool(string)> is_number = [](string sy)
	{
		return !sy.empty() && find_if(sy.begin(), sy.end(), [](char c) {return !isdigit(c); }) == sy.end(); //Возвращает проверку на то, является ли строка числом и не пустая ли она.
	};
	while (!is_number(year))
	{
		cout << "Введите год издания числом) ";
		getline(cin, year);
	}
	publishingYear = stoi(year) % 2023;
}

ostream& operator<<(ostream& out, Book& b)
{
	out << "Информация о книге: \"" << b.GetName() << "\" Жанр: " << b.GetGenre() << " Автор: " << b.GetAuthor() << " Издатель: " << b.GetPublisher() << " Год издания: " << b.GetYear();
	return out;
}

