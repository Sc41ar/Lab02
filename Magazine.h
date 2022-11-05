#pragma once

#include <string>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include <iostream>
#include <Windows.h>

#include <functional>
#include <clocale>

using namespace std;

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

		static void SetCreatedCount(string count);

		static void SetCreatedCount(int count);

		static int GetCreatedCount();

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


	};
}