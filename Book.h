#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"

using namespace std;

namespace St
{
	class Book
	{
	private:
		Genre genre;
		Author author;
		Publisher publisher;
		int publishingYear;

	public:
		std::string name;

		Book()
		{
			genre.genreName = "Детектив";
			author.name = "Рубик";
			publisher.publisherName = "Zarya";
			publishingYear = 0;
		}

		Book(std::string genreName)
		{
			genre.genreName = genreName;
		}

		Book(std::string genreName, std::string authorName, std::string publisherName, int year)
		{
			genre.genreName = genreName;
			author.name = authorName;
			publisher.publisherName = publisherName;
			publishingYear = year;
		}

		Book(std::string authorName, std::string name, int year) : Book(genre.genreName = "Детектив")
		{
			author.name = authorName;
			publisher.publisherName = name;
			publishingYear = year;
		}

		static void Input(Book* b)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			string year;
			std::cout << "Введите данные книги в следующем порядке: название, жанр, автор, издатель, год издания: (разделяйте информацию знаками пробел)" << std::endl;
			cout << "Название ";
			getline(cin, b->name);
			cout << "Жанр ";
			getline(cin, b->genre.genreName);
			cout << "Автор ";
			getline(cin, b->author.name);
			cout << "Издатель: ";
			getline(cin, b->publisher.publisherName);
			cout << "Год издания: ";
			getline(cin, year);
			b->publishingYear = stoi(year);
		}

		static void Output(Book* b)
		{
			setlocale(LC_ALL, "Rus");
			std::cout << "Информация о книге \"" << b->name << "\" жанр: " << b->genre.genreName << " автор: "
				<< b->author.name << " издатель: " << b->publisher.publisherName << " год издания: " << b->publishingYear << std::endl;
		}
	};
}