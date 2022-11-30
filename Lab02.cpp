
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
	system("chcp 1251");
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
		cout << "\nВведите данные о сборнике\n";
		bookArray[i] = new St::Book[numberOfP + 1];
		bookArray[i][0].St::Book::Input();
		for (int j = 1; j < numberOfP + 1; j++)
		{
			cout << "\nДанные о книге номер" << j << "\t";
			bookArray[i][j].St::Book::Input();
			bookArray[i][j].SetYear(bookArray[i][0].GetYear());
			bookArray[i][j].SetPublisher(bookArray[i][0].GetPublisher());
		}
	}
	std::cin.ignore();

	St::Magazine* magazineArray = new St::Magazine[magazineCount];
	St::Magazine::SetCreatedCount(magazineCount);
	for (int i = 0; i < magazineCount; i++)
	{
		magazineArray[i].St::Magazine::Input();
	}
	for (int i = 0; i < bookCount; i++)
	{

		cout << "\nИнформация о сборнике\n";
		St::Output(bookArray[i][0]);
		for (int j = 1; j < numberOfP+1; j++)
		{
			cout << endl;
			St::Output(bookArray[i][j]);
		}
	}
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Output(&magazineArray[i]);
	}

	cout << "\nКоличество записанных в библиотеку журналов " << St::Magazine::GetCreatedCount() << endl;


	delete[] bookArray;
	delete[] magazineArray;
	return 0;
}


