#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class StudentException : public runtime_error {
public:
    StudentException(const string& message)
        : runtime_error("Student Error: " + message) {
    }
};
