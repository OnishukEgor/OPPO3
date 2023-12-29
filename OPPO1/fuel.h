#pragma once
#include "date.h"
using namespace std;

struct FuelCost
{
public:
    string type_fuel;
    Date date;
    double price;

    static FuelCost Create(istream& in, string line);
    static bool isValidPrice(double price);
    void Print(ostream&) const;

    void PrintTypeFuel(ostream&) const;
    void PrintPrice(ostream&) const;

};