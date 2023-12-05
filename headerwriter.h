/**
 * @file headerwriter.h
 * @author AiglonDore
 * @brief Provides the {@link HeaderWriter} class
 * @version 1.1.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "filewriter.h"

/**
 * @brief The HeaderWriter class writes the .h file.
 * 
 */
class HeaderWriter :
    public FileWriter
{
    /**
     * @brief Construct a new Header Writer object
     * @warning Deleted
     * 
     */
    HeaderWriter(const HeaderWriter&) = delete;
    /**
     * @brief Assignment operator
     * @warning Deleted
     * @return HeaderWriter& 
     */
    HeaderWriter& operator=(const HeaderWriter&) = delete;

public:
    /**
     * @brief Construct a new Header Writer object
     * @warning Deleted
     * 
     */
    HeaderWriter() = delete;
    /**
     * @brief Construct a new Header Writer object
     * 
     * @param classname The name of the class
     * @param filename The name of the file
     */
    explicit HeaderWriter(const std::string& classname, const std::string& filename) : FileWriter(classname, filename) {};
    /**
     * @brief Destroy the Header Writer object
     * 
     */
    virtual ~HeaderWriter() = default;

    /**
     * @brief Write the .h file
     * @throws runtime_error if the file could not be opened
     * @param mutex The mutex to lock
     */
    virtual void write(std::mutex* mutex= nullptr) override;
};
