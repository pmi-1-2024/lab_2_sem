#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class DataException : public runtime_error {
public:
    explicit DataException(const string& message)
        : runtime_error(message) {}
};
