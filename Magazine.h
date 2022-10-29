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
			name = "�";
			genre.genreName = "�������";
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
			std::cout << "������� ������ ������� � ��������� �������: " << endl;
			cout << "��������: ";
			getline(cin, m->name);
			cout << "����: ";
			getline(cin, m->genre.genreName);
			cout << "��������: ";
			getline(cin, m->publisher.publisherName);
			cout << "��� �������: ";
			getline(cin, year);
			cout << "����� ������: ";
			getline(cin, month);
			m->publishingYear = stoi(year);
			m->publishingMonth = stoi(month);
		}



		static void Output(Magazine m)
		{
			setlocale(LC_ALL, "Rus");
			std::cout << "���������� � ������� " << m.name << " ����: " << m.genre.genreName << " ��������: " << m.publisher.publisherName
				<< " ��� �������: " << m.publishingYear << " ����� �������: " << m.publishingMonth << std::endl;
		}
	};
}