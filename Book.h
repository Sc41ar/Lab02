#pragma once

#include <string>
#include <Windows.h>
#include <iostream>
#include <functional>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include "Litreture.h"

using namespace std;

namespace St
{
	class Book : protected Literature
	{
		friend static void Output(Book& b);
	protected:
		Author<string> author;
	public:
		

		Book();

		Book(string name, std::string genreName, string publisher, string author, int year);

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

		string GetPublisher();

		void Input() override;

		/*static void Output(Book* b);*/
	};

	void St::Output(Book& b)
	{
		setlocale(LC_ALL, "Rus");
		std::cout << "Информация о книге \"" << b.name << "\" жанр: " << b.genre.genreName << " автор: "
			<< b.author.name << " издатель: " << b.publisher.publisherName << " год издания: " << b.publishingYear << std::endl;
	}
}