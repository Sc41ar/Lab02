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

		std::string name;
		Genre genre;
		Publisher publisher;
		int publishingYear;
		int publishingMonth;
		static int createdCount;
	public:

		Magazine();

		Magazine(std::string name, std::string genName, std::string publish, int year, int month);


		static void Input(Magazine* m);

		static void Output(Magazine m);

		void SetName(string name);

		string GetName();

		void SetGenre(string genre);

		string GetGenre();

		void SetPublisher(string publisher);

		string GetPublisher();

		void SetYear(string year);

		void SetYear(int year);

		int GetYear();

		void SetMonth(string month);

		void SetMonth(int month);

		int GetMonth();

		void SetCreatedCount(string count);

		void SetCreatedCount(int count);

		int GetCreatedCount();

	};


	int Magazine::createdCount = 0;
}