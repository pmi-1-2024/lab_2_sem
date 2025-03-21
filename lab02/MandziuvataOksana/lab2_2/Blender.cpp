#include "Blender.h"

Blender::Blender() : Electroprilad(), power(0), functions(0) {}

Blender::Blender(string n, string f, int p, int pw, int func)
    : Electroprilad(n, f, p), power(pw), functions(func) {}

Blender::Blender(const Blender& bl)
    : Electroprilad(bl), power(bl.power), functions(bl.functions) {}

void Blender::print(ostream& os) const {
    Electroprilad::print(os);
    os << "Power: " << power << "W, Functions: " << functions << endl;
}

void Blender::write(istream& is) {
    is >> name >> firm >> price >> power >> functions;
}
