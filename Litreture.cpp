#include "litreture.h"

using namespace St;

Literature::Literature()
{
	name = "Рижское";
	genre = Genre::Genre("Религия");
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
