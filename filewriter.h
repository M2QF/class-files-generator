#pragma once

#include <string>
#include <mutex>

class FileWriter
{
public:
	FileWriter() = delete;
	FileWriter(const std::string& classname, const std::string& filename) : classname(classname), filename(filename) {};

	virtual ~FileWriter() = default;

	virtual void write(std::mutex* = nullptr) = 0;

	const std::string& getClassname() const { return classname; }
	const std::string& getFilename() const { return filename; }
private:
	std::string classname;
	std::string filename;
};

