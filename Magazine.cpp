#include "Magazine.h"


St::Magazine::Magazine()
{
	name = "d";
	genre.genreName = "detektiv";
	publisher.publisherName = "izdatel";
	publishingYear = 1000;
	publishingMonth = 12;
}

St::Magazine::Magazine(string name, string genre, string publisher, int year, int month)
{
	this->name = name;
	this->genre.genreName = genre;
	this->publisher.publisherName = publisher;

}

void St::Magazine::Input(Magazine* m)
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string year;
	string month;
	string a;
	std::cout << "Введите данные журнала в следующем порядке: " << endl;
	cout << "Название: ";
	getline(cin, m->name);
	cout << "Жанр: ";
	getline(cin, m->genre.genreName);
	cout << "Издатель: ";
	getline(cin, m->publisher.publisherName);
	cout << "Год издания: ";
	getline(cin, year);
	cout << "Месяц изания: ";
	getline(cin, month);
	m->publishingYear = stoi(year);
	m->publishingMonth = stoi(month);
}

void St::Magazine::Output(Magazine m)
{
	setlocale(LC_ALL, "Rus");
	std::cout << "Информация о журнале " << m.name << " жанр: " << m.genre.genreName << " издатель: " << m.publisher.publisherName
		<< " год издания: " << m.publishingYear << " месяц издания: " << m.publishingMonth << std::endl;
}

void St::Magazine::SetName(string name)
{
	this->name = name;
}

string St::Magazine::GetName()
{
	return name;
}

void St::Magazine::SetGenre(string genre)
{
	this->genre.genreName = genre;
}

string St::Magazine::GetGenre()
{
	return genre.genreName;
}

void St::Magazine::SetPublisher(string publisher)
{
	this->publisher.publisherName = publisher;
}

string St::Magazine::GetPublisher()
{
	return publisher.publisherName;
}

void St::Magazine::SetYear(string year)
{
	int y = stoi(year);
	publishingYear = y % 2022;
}

void St::Magazine::SetYear(int year)
{
	publishingYear = year % 2022;
}

int St::Magazine::GetYear()
{
	return publishingYear;
}

void St::Magazine::SetMonth(string month)
{
	int m = stoi(month);
	publishingMonth = m % 12;
}

void St::Magazine::SetMonth(int month)
{
	publishingMonth = month % 12;
}

int St::Magazine::GetMonth()
{
	return publishingMonth;
}

void St::Magazine::SetCreatedCount(string count)
{
	int c = stoi(count);
	createdCount = //модуль
}