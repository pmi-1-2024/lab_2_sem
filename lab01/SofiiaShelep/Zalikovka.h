#pragma once
#include "Subject.h"
#include <iostream>

using namespace std;

class Zalikovka
{
private:
    int number;
    int subjectCount;
    Subject* subjects;

public:
    Zalikovka() : number(0), subjectCount(0), subjects(nullptr) {}

    Zalikovka(int num, int count) : number(num), subjectCount(count)
    {
        subjects = (subjectCount > 0) ? new Subject[subjectCount] : nullptr;
    }

    Zalikovka(const Zalikovka& other) : number(other.number), subjectCount(other.subjectCount)
    {
        subjects = (subjectCount > 0) ? new Subject[subjectCount] : nullptr;
        for (int i = 0; i < subjectCount; i++)
        {
            subjects[i] = other.subjects[i];
        }
    }

    Zalikovka& operator=(const Zalikovka& other)
    {
        if (this != &other)
        {
            delete[] subjects;

            number = other.number;
            subjectCount = other.subjectCount;
            subjects = (subjectCount > 0) ? new Subject[subjectCount] : nullptr;

            for (int i = 0; i < subjectCount; i++)
            {
                subjects[i] = other.subjects[i];
            }
        }
        return *this;
    }

    ~Zalikovka()
    {
        delete[] subjects;
    }

    void addSubject(const Subject& subject)
    {
        Subject* temp = new Subject[subjectCount + 1];
        for (int i = 0; i < subjectCount; i++)
        {
            temp[i] = subjects[i];
        }
        temp[subjectCount] = subject;

        delete[] subjects;
        subjects = temp;
        subjectCount++;
    }

    void removeSubject(const string& subjectName)
    {
        int index = -1;
        for (int i = 0; i < subjectCount; i++)
        {
            if (subjects[i].getName() == subjectName)
            {
                index = i;
                break;
            }
        }

        if (index == -1) return;

        Subject* temp = new Subject[subjectCount - 1];
        for (int i = 0, j = 0; i < subjectCount; i++)
        {
            if (i != index)
            {
                temp[j++] = subjects[i];
            }
        }

        delete[] subjects;
        subjects = temp;
        subjectCount--;
    }

    Subject& operator[](int index)
    {
        return subjects[index];
    }

    friend ostream& operator<<(ostream& os, const Zalikovka& zalikovka)
    {
        os << "Number: " << zalikovka.number << "\n";
        os << "Subjects Count: " << zalikovka.subjectCount << "\n";

        for (int i = 0; i < zalikovka.subjectCount; i++)
        {
            os << zalikovka.subjects[i] << "\n";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Zalikovka& zalikovka)
    {
        is >> zalikovka.number >> zalikovka.subjectCount;

        delete[] zalikovka.subjects;
        zalikovka.subjects = new Subject[zalikovka.subjectCount];

        for (int i = 0; i < zalikovka.subjectCount; i++)
        {
            is >> zalikovka.subjects[i];
        }
        return is;
    }
};
