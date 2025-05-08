#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H
#include <iostream>
using namespace std;
class CustomException : public exception {
private:
	string message;
public: 
	CustomException(const string& msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};
#endif
