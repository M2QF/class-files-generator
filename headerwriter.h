#pragma once
#include "filewriter.h"

class HeaderWriter :
    public FileWriter
{
    HeaderWriter(const HeaderWriter&) = delete;
    HeaderWriter& operator=(const HeaderWriter&) = delete;

public:
    HeaderWriter() = delete;
    explicit HeaderWriter(const std::string& classname, const std::string& filename) : FileWriter(classname, filename) {};
    virtual ~HeaderWriter() = default;

    virtual void write(std::mutex* = nullptr) override;
};

