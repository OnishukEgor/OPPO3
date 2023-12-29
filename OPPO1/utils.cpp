#include "utils.h"
#include <fstream>
#include <sstream>

void PrintData(const vector<FuelCost>& data)
{
    for (const auto& entry : data)
    {
        entry.Print(cout);
        cout << "\n";
    }
}

vector<FuelCost> ReadDataFromFile(std::istream& fileName)
{
    vector<FuelCost> VectorFuel;

    if (!fileName)
    {
        cout << "Opening file error\n";
        return VectorFuel;
    }

    string line;
    while (getline(fileName, line))
    {
        FuelCost fuel = FuelCost::Create(fileName, line);
        VectorFuel.push_back(fuel);
    }

    return VectorFuel;
}