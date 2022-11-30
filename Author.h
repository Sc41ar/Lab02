#pragma once

#include <string>

namespace St
{
	template<typename T>
	class Author
	{
	public:

		T name;

		Author();
		Author(T inputName);
	};
}