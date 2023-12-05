/**
 * @file class-files-generator.cpp
 * @author AiglonDore and sarahnourgh
 * @brief Main file
 * @version 1.1.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// class-files-generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <thread>
#include <cstring>
#include <future>
#include <stdexcept>
#include <mutex>

#include "corewriter.h"
#include "headerwriter.h"


/**
 * @brief Prints the help message
 * 
 * @param name The name of the program
 */
static void print_help(const char *name) noexcept
{
    std::cout << "Usage: " << name << " [-f filename] <class-name>" << std::endl;
}

/**
 * @brief Validates the class name
 * 
 * @param clsName The class name
 * @return true if the class name is valid
 * @return false if the class name is invalid
 */
static bool validate_class_name(const std::string &clsName) noexcept
{
    std::cout << "Validating class name \"" << clsName << "\"..." << std::endl;
    if (clsName.empty())
    {
        std::cerr << "Class name cannot be empty" << std::endl;
        return false;
    }

    if (isdigit(clsName[0]))
    {
        std::cerr << "Class name cannot start with a digit" << std::endl;
        return false;
    }

    for (const char &c : clsName)
    {
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'))
        {
            std::cerr << "Class name can only contain digits, letters and underscores" << std::endl;
            return false;
        }
    }
    std::cout << "Class name \"" << clsName << "\" is valid." << std::endl;
    return true;
}

/**
 * @brief Main function
 * 
 * @param argc Main argument count
 * @param argv Main argument values
 * @return int output code
 */
int main(int argc, char *argv[])
{
    std::cout << "\t\t----Class files generator----" << std::endl;
    if (argc < 2)
    {
        print_help(argv[0]);
        return 0;
    }

    std::string filename = "";
    std::string classname = "";

    if (argc == 2)
    {
        classname = argv[1];
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "-f"))
        {
			std::cerr << "Invalid argument: " << argv[1] << std::endl;
			print_help(argv[0]);
			return 1;
		}

        filename = argv[2];
        classname = argv[3];
    }
    else
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        print_help(argv[0]);
        return 1;
    }

    if (!validate_class_name(classname))
    {
        std::cerr << "Invalid class name" << std::endl;
        return 1;
    }

    if (filename.empty())
    {
        filename = classname;
        std::cout << "No filename specified, using class name as filename" << std::endl;
#ifdef _WIN32
        std::transform(filename.cbegin(), filename.cend(), filename.begin(), std::tolower);
#else
        std::transform(filename.begin(), filename.end(), filename.begin(), [](unsigned char c) -> unsigned char
                       { return std::tolower(c); });
#endif
    }

    std::cout << "Core filename: " << filename << ".cpp" << std::endl;
    std::cout << "Header filename: " << filename << ".h" << std::endl;

    std::cout << "Generating files..." << std::endl;

    std::promise<void> promise;
    std::future<void> future = promise.get_future();

    std::mutex coutMutex;

    auto write_file = [&promise, &coutMutex](FileWriter& writer) -> void
        {
            try
            {
                writer.write(&coutMutex);
                promise.set_value();

                coutMutex.lock();
                std::cout << "Thread " << std::this_thread::get_id() << " finished." << std::endl;
                coutMutex.unlock();
            }
            catch (...)
            {
                promise.set_exception(std::current_exception());
            }
	};

    CoreWriter coreWriter(classname, filename);
    HeaderWriter headerWriter(classname, filename);

    std::thread coreThread(write_file, std::ref(coreWriter));

    try
    {
        headerWriter.write(&coutMutex);
        if (future.valid())
            future.get();
        else
        {
            throw std::runtime_error("Core thread is not valid");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error while generating files" << std::endl;
        std::cerr << e.what() << std::endl;
        coreThread.join();
        return 1;
    }

    coreThread.join();

    std::cout << "Done!" << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
