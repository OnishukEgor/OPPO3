#pragma once
#include <iostream>
using namespace std;

struct Date
{
public:
    int day, month, year;

    void PrintDate(std::ostream&) const;
    static bool isValidDate(int day, int month, int year);
    static Date Create(std::istream& in);
};
