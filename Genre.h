#pragma once

#include <string>
#include <stdio.h>

namespace St
{
	class Genre
	{
	public:
		std::string genreName;

		Genre();
		Genre(std::string curname);
	};
}