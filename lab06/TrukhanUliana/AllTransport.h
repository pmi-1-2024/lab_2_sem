#ifndef ALLTRANSPORT_H
#define ALLTRANSPORT_H
#include <iostream>
#include <string>
using namespace std;

class AllTransport {
public:
    virtual ~AllTransport() {}

    virtual string getLoad() const = 0;
    virtual string getDestination() const = 0;
    virtual double getPrice() const = 0;
    virtual string getLoadType() const = 0;
    virtual int getDiscount() const = 0;

    virtual void setPrice(double p) = 0;

    virtual double discount(int dis) = 0;

    virtual void read(istream& is) = 0;

    friend istream& operator>>(istream& is, AllTransport& t) {
        t.read(is);
        return is;
    }

    virtual void print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const AllTransport& t) {
        t.print(os);
        return os;
    }

    virtual void saveToFile(ostream& os) const = 0;
};

#endif