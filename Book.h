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

		static void Output(Book* b);
	};
}