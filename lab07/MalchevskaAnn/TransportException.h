#pragma once
#include <exception>
#include <string>
using namespace std;

class TransportException : public exception {
private:
    string errorMessage;
public:
    TransportException(const string& err) : errorMessage(err) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};