#pragma once

#include <string>

class FileWriter
{
public:
	FileWriter() = delete;
	FileWriter(const std::string& classname, const std::string& filename) : classname(classname), filename(filename) {};

	virtual ~FileWriter() = default;

	virtual void write() = 0;
private:
	std::string classname;
	std::string filename;
};

