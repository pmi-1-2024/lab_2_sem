#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <conio.h>
#include "phone.h"
#include "r_phone.h"
#include "m_phone.h"
#include "c_phone.h"

void read(string src, Phone ** list, int &index);
void write(string src, Phone ** list, int index);
Phone ** has_auto(Phone** list, int size, int & res_size);
void search(Phone ** list, int size);
#endif
