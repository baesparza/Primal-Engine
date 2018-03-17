#include "fileutils.h"


namespace primal
{

	fileutils::fileutils()
	{
	}


	fileutils::~fileutils()
	{
	}

	std::string read_file(const char* filePath)
	{
		std::fstream stream(filePath);

		std::string line;
		std::stringstream ss;

		while (getline(stream, line))
		{
				ss << line << '\n';
		}
		return ss.str();
	}

}