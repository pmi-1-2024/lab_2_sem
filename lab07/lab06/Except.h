#pragma once

#include <exception>
#include <string>
using namespace std;

class TransportException : public exception {
    string message;
public:
    explicit TransportException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};