
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
		cout << "\nВведите количество книг в библиотеке ";
		cin >> bookCount;
		cout << endl << "Введите количество журналов в библиотеке ";
		cin >> magazineCount;
		if (magazineCount < 0 || bookCount < 0)
			throw std::exception("\nНеправильный ввод колитчества журналов или книг\n");
	}
	catch (std::exception e)
	{
		cout << e.what();
		cout << "\nВведите количество книг в библиотеке ";
		cin >> bookCount;
		cout << endl << "Введите количество журналов в библиотеке ";
		cin >> magazineCount;
	}
	St::Book* bookArray = new St::Book[bookCount];
	cin.ignore();
	for (int i = 0; i < bookCount; i++)
	{
		bookArray[i];
		St::Book::Input(&(bookArray[i]));
	}
	St::Magazine* magazineArray = new St::Magazine[magazineCount];
	St::Magazine::SetCreatedCount(magazineCount);
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Input(&(magazineArray[i]));
	}
	for (int i = 0; i < bookCount; i++)
	{
		St::Output(bookArray[i]);
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


