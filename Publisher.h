#pragma once

#include <string>

namespace St
{
	class Publisher
	{
	public:
		std::string publisherName;

		Publisher();

		Publisher(std::string name);
	};
}