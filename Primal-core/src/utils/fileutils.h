#pragma once
#include <string>

namespace primal
{
	std::string read_file(const char* filePath);

	class fileutils
	{
	public:
		fileutils();
		~fileutils();
	};

}