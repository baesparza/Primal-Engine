#pragma once
#include <fstream>
#include <string>
#include <sstream>

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