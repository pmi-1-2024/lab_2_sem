#pragma once
#include <exception>
#include <string>
using namespace std;

struct FileError : public exception {
    string msg;
    FileError(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

struct DataError : public exception {
    string msg;
    DataError(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};