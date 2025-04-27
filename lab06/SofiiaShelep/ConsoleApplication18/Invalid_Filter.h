#pragma once
#include <exception>
#include <string>
using namespace std;

class Invalid_Filter : public std::exception
{
private:
    string message;
public:
    Invalid_Filter(const string& msg) : message("invalid filter " + msg) {}
    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }
};

