
#include <stdio.h>
#include <iostream>
#include <string>
#include <clocale>
#include <cctype>
#include <windows.h>
#include "Book.h"
#include "Magazine.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int bookCount = 0, magazineCount = 0;
	cout << "Введите количество книг в библиотеке ";
	cin >> bookCount;
	cout << endl << "Введите количество журналов в библиотеке ";
	cin >> magazineCount;
	St::Book* bookArray = new St::Book[bookCount];
	for (int i = 0; i < bookCount; i++)
	{
		St::Book::Input(&(bookArray[i]));
	}
	St::Magazine* magazineArray = new St::Magazine[magazineCount];
	St::Magazine::SetCreatedCount(magazineCount);
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Input(&magazineArray[i]);
	}
	string requiredBook, requiredMagazine;
	cout << "Введите название книги и журнала, о которых вывести информацию" << endl;
	cin >> requiredBook >> requiredMagazine;
	for (int i = 0; i < bookCount; i++)
	{
		if (bookArray[i].name == requiredBook)
			St::Book::Output(&(bookArray[i]));
	}
	for (int i = 0; i < magazineCount; i++)
	{
		if (magazineArray[i].name == requiredMagazine)
			St::Magazine::Output(magazineArray[i]);
	}

	cout << "Количество записанных в библиотеку журналов " << St::Magazine::GetCreatedCount();


	delete[] bookArray;
	delete[] magazineArray;
}


