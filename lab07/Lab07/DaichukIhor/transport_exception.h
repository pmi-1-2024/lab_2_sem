#pragma once
#ifndef TRANSPORT_EXCEPTION_H
#define TRANSPORT_EXCEPTION_H

#include <exception>
#include <string>

class TransportException : public std::exception {
    std::string message;
public:
    TransportException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif 
