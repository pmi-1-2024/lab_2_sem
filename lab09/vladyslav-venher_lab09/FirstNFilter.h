#pragma once

bool isValid(char ch);

class FirstNFilter {
    int limit, count = 0;
public:
    FirstNFilter(int n);
    bool operator()(char ch);
};