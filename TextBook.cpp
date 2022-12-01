#include "TextBook.h"

void TextBook::Input()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string  year, course;
	std::cout << "������� ������ ����� � ��������� �������: ��������, ����, �����, ��������, ��� �������:" << std::endl;
	cout << "�������� ";
	getline(cin, name);
	cout << "���� ";
	getline(cin, genre.genreName);
	cout << "����� ";
	getline(cin, author.name);
	cout << "��������: ";
	getline(cin, publisher.publisherName);
	cout << "��� �������: ";
	getline(cin, year);
	cout << "������� ���� ��������: ";
	getline(cin, theme);
	cout << "������� ��� ��������, ��� �������� ���� ������� ������������";
	getline(cin, course);
	function<bool(string)> is_number = [](string sy)
	{
		return !sy.empty() && find_if(sy.begin(), sy.end(), [](char c) {return !isdigit(c); }) == sy.end(); //���������� �������� �� ��, �������� �� ������ ������ � �� ������ �� ���.
	};
	while (!is_number(year) || !is_number(course))
	{
		cout << "������� ��� ������� ������) ";
		getline(cin, year);
		cout << "������� ��� �������� ������: ";
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
	theme = "������������";
	return *this;
}

ostream& operator<<(ostream& out, TextBook& b)
{
	out << "���������� � �����: \"" << b.GetName() << "\" ����: " << b.GetGenre() << " �����: " << b.GetAuthor() << " ��������: " << b.GetPublisher() << " ��� �������: " << b.GetYear();
	return out;
}