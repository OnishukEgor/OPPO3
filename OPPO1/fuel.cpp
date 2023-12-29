#include "fuel.h"
#include "date.h"
#include <sstream>
#include <stdexcept>

bool FuelCost::isValidPrice(double price)
{
    return price > 0;
}

void FuelCost::PrintTypeFuel(std::ostream& out) const
{
    out << "Тип топлива: " << type_fuel << " ";
}

void FuelCost::PrintPrice(std::ostream& out) const
{
    out << "Цена топлива: " << price << " ";
}

void FuelCost::Print(ostream& out) const
{
    PrintTypeFuel(out);
    PrintPrice(out);
    date.PrintDate(out);
}

FuelCost FuelCost::Create(istream& in, string line)
{
    FuelCost fuel;

    istringstream Stream(line);

    Stream >> fuel.type_fuel;
    if (fuel.type_fuel.empty()) {
        throw std::runtime_error("Invalid or empty fuel type");
    }

    fuel.date = Date::Create(Stream);
    Stream >> fuel.price;
    if (!isValidPrice(fuel.price)) {
        throw std::runtime_error("Invalid price values");
    }

    return fuel;
}
