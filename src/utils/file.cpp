#include "utils/file.h"

namespace FileSystem
{
	std::string readFile(std::string path)
	{
		std::ifstream stream(path);
		std::string line;
		std::stringstream ss;

		while (!stream.eof())
		{
			std::getline(stream, line);
			ss << line << "\n";
		}

		return ss.str();
	}
}