#pragma once
#include <stdexcept>
#include <string>
using namespace std; 

//InvalidLogisticsDataException

class InvalidLDE : public  runtime_error {
public:
    explicit InvalidLDE(const  string& message)
        :  runtime_error("Invalid logistics data: " + message) {}
};
