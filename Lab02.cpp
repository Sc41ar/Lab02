// Lab02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

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

int main()
{
	cout << "Hello World!\n";
}

struct Genre
{
public:
	GenreName genreName;
	bool isExplicit;
	static void setExplicity(Genre* genreobj)
	{
		if (genreobj->genreName == 1 || genreobj->genreName == 3 || genreobj->genreName == 4)
			genreobj->isExplicit = true;
		else
			genreobj->isExplicit = false;
	}
};

struct Author
{
private:
	int birthyear;
	string name;
public:
	string getAuthorData(Author author)
	{
		return name + to_string(birthyear);
	}
};

