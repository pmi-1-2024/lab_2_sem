#include "WashingMachine.h"

WashingMachine::WashingMachine() : Electroprilad(), programs(0), volume(0) {}

WashingMachine::WashingMachine(string n, string f, int p, int prog, double vol)
    : Electroprilad(n, f, p), programs(prog), volume(vol) {}

WashingMachine::WashingMachine(const WashingMachine& wm)
    : Electroprilad(wm), programs(wm.programs), volume(wm.volume) {}

void WashingMachine::print(ostream& os) const {
    Electroprilad::print(os);
    os << "Programs: " << programs << ", Volume: " << volume << "L" << endl;
}

void WashingMachine::write(istream& is) {
    is >> name >> firm >> price >> programs >> volume;
}
