
// Calculator.cpp file

#include "Calculator.hpp"
#include <vector>
#include "Person.hpp"



double Calculator::calculateAgeAverage(const std::vector<Person> &persons)
{
    if (persons.empty())
    {
        return 0.0;
    }

    double sum = 0;
    for (const Person &person : persons)
    {
        sum += person.getAge();
    }

    return sum / persons.size();
}

double Calculator::calculateSalaryAverage(const std::vector<Person> &persons)
{
    if (persons.empty())
    {
        return 0.0;
    }

    double sum = 0;
    for (const Person &person : persons)
    {
        sum += person.getSalary();
    }

    return sum / persons.size();
}

int Calculator::sumPersonIds(const std::vector<Person> &persons)
{
    int result = 0;
    for (const Person &person : persons)
    {
        result += person.getId();
    }
    return result;
}











/*int Calculator::sumIntegers(const std::vector<int> &numbers)
{
    int result = 0;
    for (int num : numbers)
    {
        result += num;
    }
    return result;
}*/
