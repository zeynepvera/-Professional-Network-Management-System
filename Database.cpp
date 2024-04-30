// Database.cpp file

#include "Database.hpp"
#include <iostream>

std::vector<int> Database::ages;
std::vector<double> Database::salaries;

void Database::addAge(int age)
{
    ages.push_back(age);
}

void Database::addSalary(double salary)
{
    salaries.push_back(salary);
}

