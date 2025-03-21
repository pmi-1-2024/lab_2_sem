#ifndef BLENDER_H
#define BLENDER_H

#include "Electroprilad.h"

class Blender : public Electroprilad {
private:
    int power;  
    int functions;  

public:
    Blender();
    Blender(string n, string f, int p, int pw, int func);
    Blender(const Blender& bl);
    ~Blender() {}

    void print(ostream& os) const override;
    void write(istream& is) override;
};

#endif

