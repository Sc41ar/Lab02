// Lab02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
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
	cin.ignore(1, '\n');
	St::Book* bookArray = new St::Book[bookCount];
	for (int i = 0; i < bookCount; i++)
	{
		
		St::Book::Input(&(bookArray[i]));
	}
	St::Magazine* magazineArray = new St::Magazine[magazineCount];
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Input(&magazineArray[i]);
	}
	string requiredBook, requiredMagazine;
	
	for (int i = 0; i < bookCount; i++)
	{
		St::Book::Output(&(bookArray[i]));
	}
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Output(magazineArray[i]);
	}

	delete[] bookArray;
	delete[] magazineArray;
}


