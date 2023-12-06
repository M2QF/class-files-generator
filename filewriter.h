/**
 * @file filewriter.h
 * @author AiglonDore and sarahnourgh
 * @brief Provides the {@link FileWriter} class
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
	/**
	 * @brief Construct a new File Writer object
	 * @warning Deleted
	 * 
	 */
	FileWriter() = delete;

	/**
	 * @brief Construct a new File Writer object
	 * 
	 */
	FileWriter(const std::string& classname, const std::string& filename) : classname(classname), filename(filename) {};

	/**
	 * @brief Destroy the File Writer object
	 * 
	 */
	virtual ~FileWriter() = default;

	/**
	 * @brief Writes the file
	 * @param mutex mutex to lock
	 */
	virtual void write(std::mutex* mutex = nullptr) = 0;

	/**
	 * @brief Get the Classname object
	 * 
	 * @return const std::string& class name
	 */
	const std::string& getClassname() const { return classname; }
	/**
	 * @brief Get the Filename object
	 * 
	 * @return const std::string& file name
	 */
	const std::string& getFilename() const { return filename; }

private:
	/**
	 * @brief class name
	 * 
	 */
	std::string classname;
	/**
	 * @brief file name
	 * 
	 */
	std::string filename;
};

