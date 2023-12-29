#pragma once
#include "date.h"
#include "fuel.h"
#include <vector>

vector<FuelCost> ReadDataFromFile(std::istream& fileName);
void PrintData(const vector<FuelCost>& data);