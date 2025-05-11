#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class TransportException : public runtime_error {
public:
    TransportException(const string& message)
        : runtime_error(message) {
    }
};

class TransportFileException : public TransportException {
public:
    TransportFileException(const string& message)
        : TransportException("File Error: " + message) {
    }
};

class TransportDataException : public TransportException {
public:
    TransportDataException(const string& message)
        : TransportException("Data Error: " + message) {
    }
};

class TransportCostException : public TransportException {
public:
    TransportCostException(const string& message)
        : TransportException("Cost Error: " + message) {
    }

};
