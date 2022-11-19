#include "litreture.h"

using namespace St;

Literature::Literature()
{
	name = "�������";
	genre = Genre::Genre("�������");
	publisher = Publisher::Publisher();
	publishingYear = 0;
}

Literature::Literature(string name, string genre, string publisher, int publishingYear)
{
	this->name = name;
	this->genre.genreName = genre;
	this->publisher.publisherName = publisher;
	this->publishingYear = publishingYear;
}

Literature::~Literature()
{
}

void Literature::Input()
{
	string year;
	cout << "������� �������� ������������: ";
	getline(cin, name);
	cout << "\n���� ������������: ";
	getline(cin, genre.genreName);
	cout << "\n��������: ";
	getline(cin, publisher.publisherName);
	cout << "\n��� ����������: ";
	getline(cin, year);
	publishingYear = stoi(year);

}