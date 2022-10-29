#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"

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
			genre.genreName = "��������";
			author.name = "�����";
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

		Book(std::string authorName, std::string name, int year) : Book(genre.genreName = "��������")
		{
			author.name = authorName;
			publisher.publisherName = name;
			publishingYear = year;
		}

		static void Input(Book* b)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			std::cout << "������� ������ ����� � ��������� �������: ��������, ����, �����, ��������, ��� �������: (���������� ���������� ������� ������)" << std::endl;
			std::cin >> b->name >> b->genre.genreName >> b->author.name >> b->publisher.publisherName >> b->publishingYear;
		}

		static void Output(Book* b)
		{
			setlocale(LC_ALL, "Rus");
			std::cout << "���������� � ����� \"" << b->name << "\" ����: " << b->genre.genreName << " �����: "
				<< b->author.name << " ��������: " << b->publisher.publisherName << " ��� �������: " << b->publishingYear << std::endl;
		}
	};
}