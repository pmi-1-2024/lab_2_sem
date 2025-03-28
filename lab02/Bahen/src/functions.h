#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include "phone.h"
#include "r_phone.h"
#include "m_phone.h"

void read(string src, Phone ** list, int &index);
void write(string src, Phone ** list, int index);
void quick_sort(Phone** list, int l, int r);
Phone ** has_auto(Phone** list, int size, int & res_size);
#endif
