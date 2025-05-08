#ifndef TRANSPORT_EXCEPTION_H
#define TRANSPORT_EXCEPTION_H

#include <exception>
#include <string>

class TransportException : public std::exception {
private:
    std::string message;

public:
    explicit TransportException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif

