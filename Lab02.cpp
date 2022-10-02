// Lab02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>
#include <cctype>

using namespace std;

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

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Hello World!\n";
}

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
		else if (genreDiscription == "детская литература" || genreDiscription == "Детская литература")
			return childlitreture;
		else
			return detective;
	}
};

struct Author
{
private:
	int birthyear;

public:

	string name;
	string getAuthorData(Author author)
	{
		return name + to_string(birthyear);
	}
};

struct Publisher
{
public:
	PublisherName name;
};

struct Book
{
private:
	string name;
	Genre genre;
	Author author;
	Publisher publisher;
	int publishingYear;

public:
	static void Input(Book* b)
	{
		string genreStr, publisherStr;
		cout << "Введите данные книги в следующем порядке: название, жанр, автор, издатель, год издания: " << endl;
		cin >> b->name >> genreStr >> b->author.name >> publisherStr >> b->publishingYear;
		b->genre.genreName = Genre::GetGenreFromString(genreStr);
		Genre::GetExplicity(&(b->genre));
	}

	static void Output(Book b)
	{
		string genreStr, publisherStr;
		genreStr = Genre.GetGenreInStr(&genre);
		cout << <<
	}
};