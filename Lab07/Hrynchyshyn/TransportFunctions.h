#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Transport.h"
#include "SpecialTransport.h"
#include "TransportException.h"
using namespace std;

template <typename T>
int findMostExpensive(Transport<T>** transports, int size) {
    if (size <= 0) return -1;
    if (!transports) {
        throw TransportDataException("Transports array cannot be null when size > 0.");
    }

    int maxIndex = -1;
    double maxCost = -1.0;

    for (int i = 0; i < size; ++i) {
        if (!transports[i]) {
            continue;
        }
        if (transports[i]->getCost() > maxCost) {
            maxCost = transports[i]->getCost();
            maxIndex = i;
        }
    }
    if (maxIndex == -1 && size > 0) {
        for (int i = 0; i < size; ++i) {
            if (transports[i] && transports[i]->getCost() >= 0) {
                if (maxCost <= 0) {
                    maxIndex = i;
                    break;
                }
            }
        }
    }
    return maxIndex;
}

template <typename T>
void applyDiscount(Transport<T>& transport) {
    double originalCost = transport.getCost();
    double discountAmount = transport.calculateDiscount();
    double newCost = originalCost - discountAmount;

    if (newCost < 0) {
        throw TransportCostException("Applying discount results in a negative cost (" + to_string(newCost) + "). Operation aborted.");
    }
    transport.setCost(newCost);
}
template <typename T>
int filterByCargo(Transport<T>** transports, int size, const T& cargoToFilterBy, Transport<T>** filteredArray, int& filteredSize) {
    if (size < 0) {
        throw invalid_argument("Size cannot be negative for filterByCargo.");
    }
    if (!transports && size > 0) {
        throw invalid_argument("Transports array cannot be null for filterByCargo if size > 0.");
    }
    if (!filteredArray && size > 0) {
        throw invalid_argument("FilteredArray cannot be null for filterByCargo if size > 0.");
    }

    filteredSize = 0;
    for (int i = 0; i < size; ++i) {
        if (!transports[i]) continue;
        if (transports[i]->getCargo() == cargoToFilterBy) {
            filteredArray[filteredSize++] = transports[i];
        }
    }
    return filteredSize;
}

template <typename T>
double calculateTotalCost(Transport<T>** transports, int size) {
    if (size < 0) {
        throw invalid_argument("Size cannot be negative for calculateTotalCost.");
    }
    if (!transports && size > 0) {
        throw invalid_argument("Transports array cannot be null for calculateTotalCost if size > 0.");
    }

    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        if (!transports[i]) continue;
        total += transports[i]->getCost();
    }
    return total;
}

template <typename T>
void saveDataToFile(Transport<T>** transports, int size, const char* filename) {
    if (!filename || filename[0] == '\0') {
        throw TransportFileException("Filename cannot be null or empty for saveDataToFile.");
    }
    ofstream file(filename);
    file.exceptions(ios_base::failbit | ios_base::badbit);

    try {
        if (!file.is_open()) {
            throw TransportFileException("Unable to open file for writing: " + string(filename));
        }

        file << size << "\n";

        if (!transports && size > 0) {
            throw TransportDataException("Transports array is null but size > 0, cannot save.");
        }

        for (int i = 0; i < size; ++i) {
            if (!transports[i]) {
                throw TransportDataException("Cannot save: found null transport object at index " + to_string(i));
            }
            transports[i]->save(file);
        }
        if (file.is_open()) file.close();
    }
    catch (const TransportFileException& e) {
        throw TransportFileException("Error saving data to file '" + string(filename) + "': " + e.what());
    }
   
}

template <typename T>
Transport<T>** loadDataFromFile(const char* filename, int& size) {
    size = 0;
    if (!filename || filename[0] == '\0') {
        throw invalid_argument("Filename cannot be null or empty for loadDataFromFile.");
    }

    ifstream file(filename);
    if (!file.is_open()) {
        return nullptr; 
    }
    file.exceptions(ios_base::failbit | ios_base::badbit);

    Transport<T>** transports = nullptr;
    int capacity_from_file = 0;

    try {
        file >> capacity_from_file;
        if (capacity_from_file < 0) {
            throw TransportException("Invalid capacity (negative: " + to_string(capacity_from_file) + ") in file: " + string(filename));
        }
        file.ignore();

        if (capacity_from_file == 0) {
            return nullptr;
        }

        transports = new Transport<T>*[capacity_from_file]; 

        for (int i = 0; i < capacity_from_file; ++i) {
            if (file.peek() == EOF && !file.eof()) { 
            }
            if (file.eof()) { 
                throw TransportException("Unexpected end of file in '" + string(filename) + "'. Expected "
                    + to_string(capacity_from_file) + " objects, but file ended after " + to_string(size) + ".");
            }
            int isSpecial = 0;
            file >> isSpecial;
            file.ignore();

            Transport<T>* obj = nullptr;
            if constexpr (is_same<T, Cargo>::value) {
                if (isSpecial == 1) {
                    obj = new SpecialTransport();
                }
                else if (isSpecial == 0) {
                    obj = new Transport<T>(); 
                }
                else {
                    throw TransportException("Invalid type flag (" + to_string(isSpecial) + ") for Cargo object in file.");
                }
            }
            else { 
                if (isSpecial == 1) {
                    throw TransportException("Data corruption: SpecialTransport flag (1) found for non-Cargo type (Person) in file.");
                }
                else if (isSpecial == 0) {
                    obj = new Transport<T>();
                }
                else {
                    throw TransportException("Invalid type flag (" + to_string(isSpecial) + ") for Person object in file.");
                }
            }
            obj->load(file);
            transports[size++] = obj;
        }
        return transports;

    }
    catch (const bad_alloc& e) {
        if (transports) {
            for (int i = 0; i < size; ++i) delete transports[i]; 
            delete[] transports;
        }
        size = 0;
        throw; 
    }
    catch (const ios_base::failure& e) {
        if (transports) {
            for (int i = 0; i < size; ++i) delete transports[i];
            delete[] transports;
        }
        size = 0;
        throw ios_base::failure("I/O error loading data from '" + string(filename) + "': " + e.what());
    }
    catch (const TransportException& e) { 
        if (transports) {
            for (int i = 0; i < size; ++i) delete transports[i];
            delete[] transports;
        }
        size = 0;
        throw TransportException("Application error loading data from '" + string(filename) + "': " + e.what());
    }
}

