#pragma once

#include <string>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include <iostream>
#include <Windows.h>
#include <clocale>

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

		Magazine()
		{
			name = "ј";
			genre.genreName = "Ќаучный";
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
			std::cout << "¬ведите данные журнала в следующем пор€дке: название, жанр, издатель, год издани€, мес€ц издани€: (раздел€йте информацию знаками пробел" << std::endl;
			std::cin >> m->name >> m->genre.genreName >> m->publisher.publisherName >> m->publishingYear >> m->publishingMonth;
		}

		static void Output(Magazine m)
		{
			setlocale(LC_ALL, "Rus");
			std::cout << "»нформаци€ о журнале " << m.name << " жанр: " << m.genre.genreName << " издатель: " << m.publisher.publisherName
				<< " год издани€: " << m.publishingYear << " мес€ц издани€: " << m.publishingMonth << std::endl;
		}
	};
}