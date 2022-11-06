#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include <functional>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"

using namespace std;

namespace St
{
	class Book
	{
		friend static void Output(Book& b);
	private:
		Genre genre;
		Author author;
		Publisher publisher;
		int publishingYear;
		std::string name;
	public:
		

		Book();

		Book(std::string name);

		Book(std::string authorName, std::string genreName, int year);

		void SetName(string name);

		string GetName();

		void SetGenre(string genre);

		string GetGenre();

		void SetAuthor(string author);

		string GetAuthor();

		void SetYear(string year);

		void SetYear(int year);

		int GetYear();

		void SetPublisher(string publisher);

		string GerPublisher();

		static void Input(Book* b);

		/*static void Output(Book* b);*/
	};

	void St::Output(Book& b)
	{
		setlocale(LC_ALL, "Rus");
		std::cout << "Информация о книге \"" << b.name << "\" жанр: " << b.genre.genreName << " автор: "
			<< b.author.name << " издатель: " << b.publisher.publisherName << " год издания: " << b.publishingYear << std::endl;
	}
}