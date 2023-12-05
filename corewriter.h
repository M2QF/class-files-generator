#pragma once
#include "filewriter.h"
class CoreWriter :
    public FileWriter
{
public: 
    //method that will create and write the .cpp file
    virtual void write() override;
};

