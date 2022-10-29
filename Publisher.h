#pragma once

#include <string>

namespace St
{
	class Publisher
	{
	public:
		std::string publisherName;

		Publisher()
		{
			publisherName = "Zarya";
		}

		Publisher(std::string name)
		{
			publisherName = name;
		}
	};
}