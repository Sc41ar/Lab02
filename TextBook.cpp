#include "TextBook.h"

void TextBook::Input()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string  year, course;
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
	cout << "Введите тему учебника: ";
	getline(cin, theme);
	cout << "ВВедите год обучения, для которого этот учебник предназначен";
	getline(cin, course);
	function<bool(string)> is_number = [](string sy)
	{
		return !sy.empty() && find_if(sy.begin(), sy.end(), [](char c) {return !isdigit(c); }) == sy.end(); //Возвращает проверку на то, является ли строка числом и не пустая ли она.
	};
	while (!is_number(year) || !is_number(course))
	{
		cout << "Введите год издания числом) ";
		getline(cin, year);
		cout << "Введите год обучения числом: ";
		getline(cin, course);
	}
	this->course = stoi(course);
	publishingYear = stoi(year) % 2023;
}

TextBook TextBook::operator= (Book b)
{
	this->author = b.GetAuthor();
	this->name = b.GetName();
	this->publishingYear = b.GetYear();
	this->genre = b.GetGenre();
	this->publisher = b.GetPublisher();
	course = 1;
	theme = "неопределена";
	return *this;
}

ostream& operator<<(ostream& out, TextBook& b)
{
	out << "Информация о книге: \"" << b.GetName() << "\" Жанр: " << b.GetGenre() << " Автор: " << b.GetAuthor() << " Издатель: " << b.GetPublisher() << " Год издания: " << b.GetYear();
	return out;
}