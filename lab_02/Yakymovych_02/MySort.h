#pragma once
#include "Phone.h"

void mySort (Phone** phones, int size ) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (phones[i]->getPrice() > phones[j]->getPrice()) {
                
                Phone* temp = phones[i];
                phones[i] = phones[j];
                phones[j] = temp;
            }
        }
    }
}
