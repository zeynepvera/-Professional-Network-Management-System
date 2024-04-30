// Employee.hpp
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Person.hpp"

class Employee : public Person
{

private:

    std::string position;

public:

    Employee();
    Employee(int id, const std::string &firstName, const std::string &lastName, const std::string &username, const std::string &password, int age, double salary, const std::string &position);

    std::string getPosition() const;
    void setPosition(const std::string &newPosition);

    void displayInfo() const override; 
};

#endif
