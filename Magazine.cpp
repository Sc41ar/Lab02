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
	function<bool(string)> is_number = [](string sy)
	{
		if (find_if(sy.begin(), sy.end(), [](char c) {return !isdigit(c); }) != sy.end())
			throw std::exception("Неверный ввод года или месяца издания\n");
		return !sy.empty(); //страшное лямбда выражение
	};
	try
	{
		m->publishingYear = stoi(year) % 2023;
		m->publishingMonth = stoi(month) % 13;
	}
	catch (std::exception& e)
	{
		cout << e.what();
		cout << "\nВведите год издания числом) ";
		getline(cin, year);
		cout << "\nА теперь месяц тоже числом) ";
		getline(cin, month);
		m->publishingYear = stoi(year) % 2023;
		m->publishingMonth = stoi(month) % 13;
	}
}

string* St::Magazine::GetOutputStr(Magazine* m, string* output)
{
	string year = to_string(m->publishingYear);
	string month = to_string(m->publishingMonth);
	*output = "Информация о журнале \"" + m->name + "\" \nжанр: " + m->genre.genreName + "\nиздатель: " + m->publisher.publisherName
		+ "\nгод издания: " + year + "\nмесяц издания: " + month;
	return output;
}

void St::Magazine::Output(Magazine m)
{
	setlocale(LC_ALL, "Rus");
	string out;

	std::cout << *(Magazine::GetOutputStr(&m, &out)) << std::endl;
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
	Magazine::createdCount = c;//модуль
}

void St::Magazine::SetCreatedCount(int count)
{
	/*if (count < 1)
	{
		throw std::exception("Неправирльный аргумент для количества журналов");
	}*/
	Magazine::createdCount = count;
}

int St::Magazine::GetCreatedCount()
{
	return createdCount;
}

int St::Magazine::createdCount = 0;

St::Magazine operator + (St::Magazine m1, St::Magazine m2)
{
	int curYear, curMonth;
	string name;
	auto determinant = [](int i1, int i2) {
		return i1 > i2 ? i1 : i2;
	};
	name = m1.GetName() + "и" + m2.GetName();
	curYear = determinant(m1.GetYear(), m2.GetYear());
	curMonth = determinant(m1.GetMonth(), m2.GetMonth());
	St::Magazine value(name, "Сборник", m2.GetPublisher(), curYear, curMonth);
	return value;
}

St::Magazine operator ++(St::Magazine m1)
{
	int month = (m1.GetMonth() + 1) % 13;
	int year = (m1.GetMonth() + 1) < 13 ? m1.GetYear() : m1.GetYear() + 1;
	return St::Magazine(m1.GetName(), m1.GetGenre(), m1.GetPublisher(), year, month);
}