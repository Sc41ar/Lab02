#include "Book.h"

St::Book::Book()
{
	name = "din";
	genre.genreName = "Dong";
	author.name = "Dong";
	publisher.publisherName = "Ha-ha";
	publishingYear = 1000;
}

St::Book::Book(string name)
{
	this->name = name;
}

St::Book::Book(string authorName, string genreName, int year)
{
	author.name = authorName;
	genre.genreName = genreName;
	publishingYear = year;
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

string St::Book::GerPublisher()
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

void St::Book::Input(Book* b)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string  year;
	std::cout << "������� ������ ����� � ��������� �������: ��������, ����, �����, ��������, ��� �������:" << std::endl;
	cout << "�������� ";
	getline(cin, b->name);
	cout << "���� ";
	getline(cin, b->genre.genreName);
	cout << "����� ";
	getline(cin, b->author.name);
	cout << "��������: ";
	getline(cin, b->publisher.publisherName);
	cout << "��� �������: ";
	getline(cin, year);
	function<bool(string)> is_number = [](string sy)														
	{
		return !sy.empty() && find_if(sy.begin(), sy.end(), [](char c) {return !isdigit(c); }) == sy.end(); //���������� �������� �� ��, �������� �� ������ ������ � �� ������ �� ���.
	};
	while (!is_number(year))
	{
		cout << "������� ��� ������� ������) ";
		getline(cin, year);
	}
	b->publishingYear = stoi(year) % 2023;
}

//void St::Book::Output(Book* b)
//{
//	setlocale(LC_ALL, "Rus");
//	std::cout << "���������� � ����� \"" << b->name << "\" ����: " << b->genre.genreName << " �����: "
//		<< b->author.name << " ��������: " << b->publisher.publisherName << " ��� �������: " << b->publishingYear << std::endl;
//}

