
#include "UserDefinedType.h"

UserType::UserType() : firstName("Unnamed"), lastName("Unknown"), score(0) {}

bool UserType::operator>(const UserType& other) const
{
    if (score != other.score)
    {
        return score > other.score;
    }
    if (lastName != other.lastName)
    {
        return lastName > other.lastName;
    }
    return firstName > other.firstName;
}

string UserType::FetchSurname() const
{
    return lastName;
}

istream& operator>>(istream& is, UserType& obj)
{
    cout << "Enter first name: ";
    is >> obj.firstName;
    cout << "Enter last name: ";
    is >> obj.lastName;
    cout << "Enter score: ";
    is >> obj.score;
    return is;
}

ostream& operator<<(ostream& os, const UserType& obj)
{
    os << "Name: " << obj.firstName << ", Surname: " << obj.lastName << ", Score: " << obj.score;
    return os;
}
