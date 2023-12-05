/**
 * @file filewriter.h
 * @author AiglonDore
 * @brief 
 * @version 1.1.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <string>
#include <mutex>

/**
 * @brief The FileWriter class is the base class for the header and core writers.
 * 
 */
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

