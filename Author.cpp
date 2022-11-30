#include "Author.h"

namespace St
{
	Author<std::string>::Author()
	{
		Author::name = "Lenin";
	}

	Author<std::string>::Author(std::string name)
	{
		Author::name = name;
	}
}
