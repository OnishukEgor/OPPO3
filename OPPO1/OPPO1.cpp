#include "fuel.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    ifstream file("in.txt");
    vector<FuelCost> VectorFuel = ReadDataFromFile(file);
    PrintData(VectorFuel);
    file.close(); 
    return 0;
}