
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <clocale>
#include <cctype>
#include <windows.h>
#include "Book.h"
#include "Magazine.h"
#include "Lab02.h"
#include <vector>
#include "TextBook.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	int bookCount = 0, magazineCount = 0;
	vector<Book*> books;

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
	for (int i = 0; i < bookCount; i++)
	{
		cout << "Книга (1) или Учебник (2)";
		int check;
		cin >> check;
		cin.ignore();
		if (check == 2)
			books.push_back(new TextBook());
		else
			books.push_back(new Book());
		(*books[i]).Input();
	}
	std::cin.ignore();

	St::Magazine* magazineArray = new St::Magazine[magazineCount];
	St::Magazine::SetCreatedCount(magazineCount);
	for (int i = 0; i < magazineCount; i++)
	{
		magazineArray[i].St::Magazine::Input();
	}
	sort(books.begin(), books.end(), [](Book* b1, Book* b2)
		{
			return b1->GetName().compare(b2->GetName()) >= 0;
		});
	for (int i = 0; i < bookCount; i++)
	{
		St::Output(*(books[i]));
	}
	for (int i = 0; i < magazineCount; i++)
	{
		St::Magazine::Output(&magazineArray[i]);
	}

	cout << "\nВведите название и автора искомой книги";
	string name, author;
	getline(cin, name);
	getline(cin, author);
	for (auto e : books)
	{
		if (e->GetName().compare(name) == 0 && e->GetAuthor().compare(author) == 0)
		{
			cout << "\nИскомая книга: ";
			St::Output(*e);
		}
		delete e;
	}

	cout << "\nКоличество записанных в библиотеку журналов " << St::Magazine::GetCreatedCount() << endl;

	delete[] magazineArray;
	return 0;
}


