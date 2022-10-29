#pragma once

#include <string>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include <iostream>
#include <Windows.h>
#include <clocale>

using namespace std;

namespace St
{
	class Magazine
	{
	private:
		Genre genre;
		Publisher publisher;
		int publishingYear;
		int publishingMonth;
	public:
		std::string name;
		static const int maxPages = 40;

		Magazine()
		{
			name = "А";
			genre.genreName = "Научный";
			publisher.publisherName = "Zarya";
			publishingYear = 0;
			publishingMonth = 0;
		}

		Magazine(std::string name, std::string genName, std::string publish, int year, int month)
		{
			name = name;
			genre.genreName = genName;
			publisher.publisherName = publish;
			publishingYear = year;
			publishingMonth = month;
		}


		static void Input(Magazine* m)
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



		static void Output(Magazine m)
		{
			setlocale(LC_ALL, "Rus");
			std::cout << "Информация о журнале " << m.name << " жанр: " << m.genre.genreName << " издатель: " << m.publisher.publisherName
				<< " год издания: " << m.publishingYear << " месяц издания: " << m.publishingMonth << std::endl;
		}
	};
}