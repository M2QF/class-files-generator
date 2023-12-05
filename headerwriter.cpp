#include "headerwriter.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void HeaderWriter::write()
{
	cout << "Writing header file " << getFilename() << ".h" << endl;
	ofstream file(getFilename() + ".h");

	if (!file.is_open())
	{
		throw runtime_error("Could not open file " + getFilename() + ".h");
	}
	else
	{
		cout << "Writing header file " << getFilename() << ".h" << endl;
	}

	file << "#pragma once" << endl;

	file << "class " << getClassname() << endl;
	file << "{" << endl;

	file << "public:" << endl;
	file << "\t" << getClassname() << "();" << endl;
	file << "\t" << "~" << getClassname() << "();" << endl;

	file << "private:" << endl;
	file << "\t" << endl;

	file << "};" << endl;

	cout << "Finished writing header file " << getFilename() << ".h" << endl;

	file.close();
}
