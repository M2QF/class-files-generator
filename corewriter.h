#pragma once
#include "filewriter.h"
class CoreWriter :
    public FileWriter
{
public: 
    //constructor
    CoreWriter(const CoreWriter&) = delete;
    CoreWriter(const std::string& classname, const std::string& filename) : FileWriter(classname, filename) {};
    //destructor
    virtual ~CoreWriter() = default;

    CoreWriter& operator=(const CoreWriter&) = delete;
    CoreWriter(const CoreWriter&) = delete;

    //method that will create and write the .cpp file
    virtual void write() override;
};

