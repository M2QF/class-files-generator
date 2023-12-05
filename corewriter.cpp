#include "corewriter.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;
void CoreWriter::write(){
    //create the .cpp file
    ofstream file(FileWriter::getFilename() + ".cpp");
    if(!file.is_open()){
        throw runtime_error("Error creating file " + FileWriter::getFilename() + ".cpp");
    }

    cout << "Writing " << FileWriter::getFilename() << ".cpp" << endl;
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
    cout << "Done writing " << FileWriter::getFilename() << ".cpp" << endl;
    file.close();
}
