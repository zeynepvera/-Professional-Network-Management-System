

// Employee.cpp
#include "Employee.hpp"

Employee::Employee() : Person(), position("Undefined") {}

Employee::Employee(int id, const std::string &firstName, const std::string &lastName, const std::string &username, const std::string &password, int age, double salary, const std::string &position)
    : Person(id, firstName, lastName, username, password, age, salary), position(position)
{
}

std::string Employee::getPosition() const
{
    return position;
}

void Employee::setPosition(const std::string &newPosition)
{
    position = newPosition;
}

void Employee::displayInfo() const
{
    Person::displayInfo();

    std::cout << "Position: " << position << "\n";
}
