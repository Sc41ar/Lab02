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

	

	enum GenreName
	{
		detective = 1,
		comedy,
		thriller,
		horror,
		epic,
		poem,
		childlitreture
	};

	enum PublisherName
	{
		Zarya = 1,
		Epos,
		RNT
	};



	struct Genre
	{
	public:
		GenreName genreName;
		bool isExplicit;
		static void GetExplicity(Genre* genreObj)
		{
			if (genreObj->genreName == 1 || genreObj->genreName == 3 || genreObj->genreName == 4)
				genreObj->isExplicit = true;
			else
				genreObj->isExplicit = false;
		}
		static string GetGenreInStr(Genre* genreObj)
		{
			switch (genreObj->genreName)
			{
			case 0:
				return "Детектив"; break;
			case 1:
				return "Комедия"; break;
			case 2:
				return "Триллер"; break;
			case 3:
				return "Ужасы"; break;
			case 4:
				return "Эпос"; break;
			case 5:
				return "Стих"; break;
			case 6:
				return "Детская литература"; break;
			default:
				return ""; break;
			}
		}

		static GenreName GetGenreFromString(string genreDiscription)
		{
			if (genreDiscription == "детектив" || genreDiscription == "Детектив")
				return detective;
			else if (genreDiscription == "комедия" || genreDiscription == "Комедия")
				return comedy;
			else if (genreDiscription == "триллер" || genreDiscription == "Триллер")
				return thriller;
			else if (genreDiscription == "ужасы" || genreDiscription == "Ужасы")
				return horror;
			else if (genreDiscription == "эпос" || genreDiscription == "Эпос")
				return epic;
			else if (genreDiscription == "стих" || genreDiscription == "Стих")
				return poem;
			else if (genreDiscription == "детская" || genreDiscription == "Детская")
				return childlitreture;
			else
				return detective;
		}
	};

	struct Author
	{
	public:

		string name;
	};

	struct Publisher
	{
	public:
		PublisherName name;

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

	struct Book
	{
	private:
		Genre genre;
		Author author;
		Publisher publisher;
		int publishingYear;

	public:
		string name;
		static void Input(Book* b)
		{
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			string genreStr, publisherStr;
			cout << "Введите данные книги в следующем порядке: название, жанр, автор, издатель, год издания: (разделяйте информацию знаками пробел)" << endl;

			cin >> b->name >> genreStr >> b->author.name >> publisherStr >> b->publishingYear;
			b->genre.genreName = Genre::GetGenreFromString(genreStr);
			Genre::GetExplicity(&(b->genre));
			b->publisher.name = Publisher::GetPublisherFormString(publisherStr);
		}

		static void Output(Book* b)
		{
			setlocale(LC_ALL, "Rus");

			string genreStr, publisherStr;
			genreStr = Genre::GetGenreInStr(&(b->genre));
			publisherStr = Publisher::GetPublisherInString(&(b->publisher));
			cout << "Информация о книге " << b->name << " жанр: " << genreStr << " автор: "
				<< b->author.name << " издатель: " << publisherStr << " год издания: " << b->publishingYear << endl;
		}
	};

	struct Magazine
	{
	private:
		Genre genre;
		Publisher publisher;
		int publishingYear;
		int publishingMonth;
	public:

		string name;
		static void Input(Magazine* m)
		{
			setlocale(LC_ALL, "Rus");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			string genreStr, publisherStr;
			cout << "Введите данные журнала в следующем порядке: название, жанр, издатель, год издания, месяц издания: (разделяйте информацию знаками пробел" << endl;
			cin >> m->name >> genreStr >> publisherStr >> m->publishingYear >> m->publishingMonth;
			m->genre.genreName = Genre::GetGenreFromString(genreStr);
			Genre::GetExplicity(&(m->genre));
			m->publisher.name = Publisher::GetPublisherFormString(publisherStr);
		}

		static void Output(Magazine m)
		{
			setlocale(LC_ALL, "Rus");

			string genreStr, publisherStr;
			genreStr = Genre::GetGenreInStr(&(m.genre));
			publisherStr = Publisher::GetPublisherInString(&(m.publisher));
			cout << "Информация о журнале " << m.name << " жанр: " << genreStr << " издатель: " << publisherStr
				<< " год издания: " << m.publishingYear << " месяц издания" << m.publishingMonth << endl;
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
}


