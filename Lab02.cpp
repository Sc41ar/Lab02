// Lab02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <clocale>
#include <cctype>
#include <windows.h>

using namespace std;

namespace St
{

	enum PublisherName
	{
		Zarya = 1,
		Epos,
		RNT
	};



	class Genre
	{
	public:
		string genreName;

		Genre()
		{
			genreName = "Детектив";
		}
		Genre(string curname)
		{
			genreName = curname;
		}
	};

	class Author
	{
	public:

		string name;

		Author()
		{
			name = "Lenin";
		}
		Author(string inputName)
		{
			name = inputName;
		}
	};

	class Publisher
	{
	public:
		PublisherName name;

		Publisher()
		{
			name = Zarya;
		}

		Publisher(string inputName)
		{
			name = GetPublisherFormString(inputName);
		}

		static PublisherName GetPublisherFormString(string pubDescription)
		{
			if (pubDescription == "Заря" || pubDescription == "заря")
				return Zarya;
			else if (pubDescription == "эпос" || pubDescription == "Эпос")
				return Epos;
			else if (pubDescription == "РНТ" || pubDescription == "рнт")
				return RNT;
			else
				return Zarya;
		}

		static string GetPublisherInString(Publisher* publisher)
		{
			switch (publisher->name)
			{
			case Zarya:
				return "Заря"; break;
			case Epos:
				return "Эпос"; break;
			case RNT:
				return "РНТ"; break;
			default:
				return "Заря"; break;
			}
		}
	};

	class Book
	{
	private:
		Genre genre;
		Author author;
		Publisher publisher;
		int publishingYear;

	public:
		string name;

		Book()
		{
			genre.genreName = "Детектив";
			author.name = "Рубик";
			publisher.name = Zarya;
			publishingYear = 0;
		}

		Book(string genreName)
		{
			genre.genreName = genreName;
		}

		Book(string genreName, string authorName, string publisherName, int year)
		{
			genre.genreName = genreName;
			author.name = authorName;
			publisher.name = Publisher::GetPublisherFormString(publisherName);
			publishingYear = year;
		}

		Book(string authorName, PublisherName name, int year) : Book(genre.genreName = "Детектив")
		{
			author.name = authorName;
			publisher.name = name;
			publishingYear = year;
		}

		static void Input(Book* b)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			string genreStr, publisherStr;
			cout << "Введите данные книги в следующем порядке: название, жанр, автор, издатель, год издания: (разделяйте информацию знаками пробел)" << endl;

			cin >> b->name >> b->genre.genreName >> b->author.name >> publisherStr >> b->publishingYear;
			b->publisher.name = Publisher::GetPublisherFormString(publisherStr);
		}

		static void Output(Book* b)
		{
			setlocale(LC_ALL, "Rus");

			string publisherStr;
			publisherStr = Publisher::GetPublisherInString(&(b->publisher));
			cout << "Информация о книге " << b->name << " жанр: " << b->genre.genreName << " автор: "
				<< b->author.name << " издатель: " << publisherStr << " год издания: " << b->publishingYear << endl;
		}
	};

	class Magazine
	{
	private:
		Genre genre;
		Publisher publisher;
		int publishingYear;
		int publishingMonth;
	public:
		string name;

		Magazine()
		{
			name = "А";
			genre.genreName = "Научный";
			publisher.name = Zarya;
			publishingYear = 0;
			publishingMonth = 0;
		}

		Magazine(string name, string genName, string publish, int year, int month)
		{
			name = name;
			genre.genreName = genName;
			publisher.name = Publisher::GetPublisherFormString(publish);
			publishingYear = year;
			publishingMonth = month;
		}


		static void Input(Magazine* m)
		{
			setlocale(LC_ALL, "Rus");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			string publisherStr;
			cout << "Введите данные журнала в следующем порядке: название, жанр, издатель, год издания, месяц издания: (разделяйте информацию знаками пробел" << endl;
			cin >> m->name >> m->genre.genreName >> publisherStr >> m->publishingYear >> m->publishingMonth;
			m->publisher.name = Publisher::GetPublisherFormString(publisherStr);
		}

		static void Output(Magazine m)
		{
			setlocale(LC_ALL, "Rus");

			string publisherStr;
			publisherStr = Publisher::GetPublisherInString(&(m.publisher));
			cout << "Информация о журнале " << m.name << " жанр: " << m.genre.genreName << " издатель: " << publisherStr
				<< " год издания: " << m.publishingYear << " месяц издания: " << m.publishingMonth << endl;
		}
	};
}

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

	delete[] bookArray;
	delete[] magazineArray;
}


