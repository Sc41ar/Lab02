#pragma once

#include <string>

namespace St
{
	class Author
	{
	public:

		std::string name;

		Author()
		{
			name = "Lenin";
		}
		Author(std::string inputName)
		{
			name = inputName;
		}
	};
}