
#include <stdio.h>
#include <iostream>
#include <string>
#include <clocale>
#include <cctype>
#include <windows.h>
#include "Book.h"
#include "Magazine.h"
#include "Lab02.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int bookCount = 0, magazineCount = 0;
	try
	{
		cout << "\nВведите количество сборников в библиотеке ";
		std::cin >> bookCount;
		cout << endl << "Введите количество журналов в библиотеке ";
		std::cin >> magazineCount;
		if (magazineCount < 0 || bookCount < 0)
			throw std::exception("\nНеправильный ввод колитчества журналов или книг\n");
	}
	catch (std::exception e)
	{
		cout << e.what();
		cout << "\nВведите количество книг в библиотеке ";
		std::cin >> bookCount;
		cout << endl << "Введите количество журналов в библиотеке ";
		std::cin >> magazineCount;
	}
	St::Book** bookArray;
	int numberOfP;
	bookArray = new St::Book * [bookCount];
	for (int i = 0; i < bookCount; i++)
	{
		cout << "\nСколько в сборнике произведений: ";
		std::cin >> numberOfP;
		std::cin.ignore();
		for (int j = 0; j < numberOfP; j++)
		{
			bookArray[i] = new St::Book[numberOfP + 1];
			if (j == 0)
			{
				cout << "\nВведите данные о сборнике\n";
				St::Book::Input(&bookArray[i][0]);
				continue;
			}
			St::Book::Input(&bookArray[i][j]);
		}
	}

	/*else
	{
		St::Book* bookArray = new St::Book[bookCount];
		for (int i = 0; i < bookCount; i++)
		{
			St::Book::Input(&(bookArray[i]));
		}
	}*/
	std::cin.ignore();

	St::Magazine* magazineArray = new St::Magazine[magazineCount];
	St::Magazine::SetCreatedCount(magazineCount);
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Input(&(magazineArray[i]));
	}
	for (int i = 0; i < bookCount; i++)
	{
		for (int j = 0; j < numberOfP; j++)
		{
			if (j == 0)
			{
				cout << "\nИнформация о сборнике\n";
				St::Output(bookArray[i][j]);
				continue;
			}
			St::Output(bookArray[i][j]);
		}
	}
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Output(magazineArray[i]);
	}

	cout << "Количество записанных в библиотеку журналов " << St::Magazine::GetCreatedCount() << endl;


	delete[] bookArray;
	delete[] magazineArray;
	return 0;
}


