/**
 * @file corewriter.cpp
 * @author sarahnourgh
 * @brief Implements {@link corewriter.h}
 * @version 1.1.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "corewriter.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void CoreWriter::write(std::mutex *coutMutex)
{
    //create the .cpp file
    ofstream file(FileWriter::getFilename() + ".cpp");
    if(!file.is_open())
    {
        throw runtime_error("Error creating file " + FileWriter::getFilename() + ".cpp");
    }
    if (coutMutex != nullptr)
    {
		coutMutex->lock();
	}

    cout << "Writing " << FileWriter::getFilename() << ".cpp" << endl;

    if (coutMutex != nullptr)
    {
        coutMutex->unlock();
    }

    //write the include statements
    file << "#include \"" << FileWriter::getClassname() << ".h\"" << endl;
    file << endl;

    //write the default constructor
    file << FileWriter::getClassname() << "::" << FileWriter::getClassname() << "(){" << endl;
    file << "}" << endl;
    file << endl;

    //write the default destructor 
    file << FileWriter::getClassname() << "::~" << FileWriter::getClassname() << "(){" << endl;
    file << "}" << endl;

    if (coutMutex != nullptr)
    {
		coutMutex->lock();
	}
    cout << "Done writing " << FileWriter::getFilename() << ".cpp" << endl;
    if (coutMutex != nullptr)
    {
		    coutMutex->unlock();
	}
    
    file.close();
}
