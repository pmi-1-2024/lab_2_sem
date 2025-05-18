#pragma once
#include <iostream>
using namespace std;

class BaseTransport
{
public:
    virtual void print() = 0;
    virtual double getPrice() = 0;
    virtual void setDestination(const string& destination) = 0;
    virtual ~BaseTransport() {}
};