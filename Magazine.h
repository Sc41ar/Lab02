#pragma once

#include <string>
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include <iostream>
#include <Windows.h>
#include "Litreture.h"
#include <functional>
#include <clocale>

using namespace std;

namespace St
{
	class Magazine : private Literature
	{
	private:
		int publishingMonth;
		static int createdCount;
	public:

		Magazine();

		Magazine(std::string name, std::string genName, std::string publish, int year, int month);

		static string* GetOutputStr(Magazine* m, string* output);

		void Input();

		static void Output(Magazine* m);

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