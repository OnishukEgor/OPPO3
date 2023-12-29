#include "date.h"
#include <sstream>
#include <stdexcept>
#include <fstream>
using namespace std;

bool Date::isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12 || day < 1 || day > 31 || year > 2023)
    {
        return false;
    }

    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && (day > 29 || (day > 28 && year % 4 != 0)))
    {
        return false;
    }

    if (((year % 4 != 0 || year % 100 == 0) && year % 400 != 0) && month == 2 && day > 28)
    {
        return false;
    }

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
    {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }

    return true;
}

Date Date::Create(std::istream& in)
{
    Date num;
    string date, day, month, year;
    in >> date;
    stringstream dateStream(date);

    try {
        getline(dateStream, day, '.');
        getline(dateStream, month, '.');
        getline(dateStream, year, '.');

        num.day = stoi(day);
        num.month = stoi(month);
        num.year = stoi(year);
    }
    catch (const std::exception&) {
        throw std::runtime_error("Invalid date format");
    }

    if (!isValidDate(num.day, num.month, num.year)) {
        throw std::runtime_error("Invalid date values");
    }

    return num;
}

void Date::PrintDate(std::ostream& out) const
{
    out << "Дата: " << day << "." << month << "." << year;
}