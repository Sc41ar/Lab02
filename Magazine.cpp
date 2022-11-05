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
	string year, month;
	std::cout << "������� ������ ������� � ��������� �������: " << endl;
	cout << "��������: ";
	getline(cin, m->name);
	cout << "����: ";
	getline(cin, m->genre.genreName);
	cout << "��������: ";
	getline(cin, m->publisher.publisherName);
	cout << "��� �������: ";
	getline(cin, year);
	cout << "����� ������: ";
	getline(cin, month);
	function<bool(string)> is_number = [](string sy) {
		return !sy.empty() && find_if(sy.begin(), sy.end(), [](char c) {return !isdigit(c); }) == sy.end(); //�������� ������ ���������
	};
	while (!is_number(year) || !is_number(month))
	{
		cout << "������� ��� ������� ������) ";
		getline(cin, year);
		cout << "� ������ ����� ���� ������) ";
		getline(cin, month);
	}
	m->publishingYear = stoi(year) % 2023;
	m->publishingMonth = stoi(month) % 13;
}

void St::Magazine::Output(Magazine m)
{
	setlocale(LC_ALL, "Rus");
	std::cout << "���������� � ������� \"" << m.name << "\" ����: " << m.genre.genreName << " ��������: " << m.publisher.publisherName
		<< " ��� �������: " << m.publishingYear << " ����� �������: " << m.publishingMonth << std::endl;
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
	Magazine::createdCount = c;//������
}

void St::Magazine::SetCreatedCount(int count)
{
	Magazine::createdCount = count;
}

int St::Magazine::GetCreatedCount()
{
	return createdCount;
}




int St::Magazine::createdCount = 0;