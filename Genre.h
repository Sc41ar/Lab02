#pragma once

#include <string>
#include <stdio.h>

namespace St
{
	class Genre
	{
	public:
		std::string genreName;

		Genre()
		{
			genreName = "Детектив";
		}
		Genre(std::string curname)
		{
			genreName = curname;
		};
	};
}