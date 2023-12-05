/**
 * @file corewriter.h
 * @author sarahnourgh
 * @brief Provides the {@link CoreWriter} class
 * @version 1.1.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "filewriter.h"

/**
 * @brief The CoreWriter class writes the .cpp file.
 * 
 */
class CoreWriter :
    public FileWriter
{
public: 
    /**
     * @brief Construct a new Core Writer object
     * @warning Deleted
     * 
     */
    CoreWriter() = delete;
    
    /**
     * @brief Construct a new Core Writer object
     * @warning Deleted
     * 
     */
    CoreWriter(const CoreWriter&) = delete;

    /**
     * @brief Construct a new Core Writer object
     * 
     * @param classname The name of the class
     * @param filename The name of the file
     */
    explicit CoreWriter(const std::string& classname, const std::string& filename) : FileWriter(classname, filename) {};
    
    /**
     * @brief Destroy the Core Writer object
     * 
     */
    virtual ~CoreWriter() = default;

    /**
     * @brief Assignment operator
     * @warning Deleted
     * 
     * @return CoreWriter& 
     */
    CoreWriter& operator=(const CoreWriter&) = delete;

    /**
     * @brief Write the .cpp file
     * 
     * @param mutex The mutex to lock
     */
    virtual void write(std::mutex* mutex = nullptr) override;
};

