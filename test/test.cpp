#include "pch.h"
#include "CppUnitTest.h"
#include "..\\OPPO1\\date.h"
#include "..\\OPPO1\\date.cpp"
#include "..\\OPPO1\\fuel.cpp"
#include "..\\OPPO1\\utils.cpp"
#include "..\\OPPO1\\OPPO1.cpp"
#include "..\\OPPO1\\fuel.h"
#include "..\\OPPO1\\utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
    TEST_CLASS(test)
    {
    public:

        TEST_METHOD(TestReadDate1)
        {
            auto sin = std::istringstream{ "25.13.2006" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate2)
        {
            auto sin = std::istringstream{ "35.07.2006" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate3)
        {
            auto sin = std::istringstream{ "13.11.2025" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate4)
        {
            auto sin = std::istringstream{ "13.07" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate5)
        {
            auto sin = std::istringstream{ "11,11,2006" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate6)
        {
            auto sin = std::istringstream{ "29.02.2001" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate7)
        {
            auto sin = std::istringstream{ "-3.12.2006" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadDate8)
        {
            auto sin = std::istringstream{ "25.-11.2006" };
            try {
                Date date = Date::Create(sin);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadFuelPriceNegative)
        {
            auto sin = std::istringstream{ "petrol92 29.2.2000 -50" };
            FuelCost fuel;
            try {
                std::string line;
                std::getline(sin, line);  // Читаем строку из потока
                fuel = FuelCost::Create(sin, line);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }


        TEST_METHOD(TestReadFuelPriceZero)
        {
            auto sin = std::istringstream{ "petrol92 29.2.2000 0" };
            FuelCost fuel;
            try {
                std::string line;
                std::getline(sin, line);  // Читаем строку из потока
                fuel = FuelCost::Create(sin, line);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }

        TEST_METHOD(TestReadFuelTypeEmpty)
        {
            auto sin = std::istringstream{ " 29.2.2000 50" };
            FuelCost fuel;
            try {
                std::string line;
                std::getline(sin, line);  // Читаем строку из потока
                fuel = FuelCost::Create(sin, line);
            }
            catch (std::runtime_error& err) {
                Assert::Fail();
            };
        }
    };
}