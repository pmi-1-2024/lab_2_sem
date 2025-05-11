

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct UserType {
private:
    string firstName;
    string lastName;
    int score;

public:
    UserType();
    bool operator>(const UserType& other) const;
    friend istream& operator>>(istream& is, UserType& obj);
    friend ostream& operator<<(ostream& os, const UserType& obj);
    string FetchSurname() const;
};
