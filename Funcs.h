#ifndef FUNCS_H
#define FUNCS_H

#include "TripBase.h"
#include "Cargo.h"
#include "Trip.h"
#include "SpecialTrip.h"

void loadTrips(TripBase** arr, int& n);
void printAll(TripBase** arr, int n);
void filterTrips(TripBase** arr, int n, string t);
void maxTrip(TripBase** arr, int n);
void changeTrip(TripBase** arr, int n);
void saleTrip(TripBase** arr, int n);
void total(TripBase** arr, int n);

#endif
