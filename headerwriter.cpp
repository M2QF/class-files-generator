/**
 * @file headerwriter.cpp
 * @author AiglonDore
 * @brief Implements {@link headerwriter.h}.
 * @version 1.1.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "headerwriter.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void HeaderWriter::write(std::mutex *coutMutex)
{
	ofstream file(getFilename() + ".h");

	if (!file.is_open())
	{
		throw runtime_error("Could not open file " + getFilename() + ".h");
	}
	else
	{
		if (coutMutex != nullptr)
		{
			coutMutex->lock();
		}
		cout << "Writing header file " << getFilename() << ".h" << endl;
		if (coutMutex != nullptr)
		{
			coutMutex->unlock();
		}
	}

	file << "#pragma once" << endl;

	file << endl;

	file << "class " << getClassname() << endl;
	file << "{" << endl;

	file << "public:" << endl;
	file << "\t" << getClassname() << "();" << endl;
	file << "\t" << "~" << getClassname() << "();" << endl << endl;

	file << "private:" << endl;
	file << "\t" << endl;

	file << "};" << endl;

	if (coutMutex != nullptr)
	{
		coutMutex->lock();
	}

	cout << "Finished writing header file " << getFilename() << ".h" << endl;

	if (coutMutex != nullptr)
	{
		coutMutex->unlock();
	}

	file.close();
}
