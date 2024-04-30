
// Calculator.hpp file
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include "Person.hpp"

class Calculator
{
public:

  static double calculateAgeAverage(const std::vector<Person> &persons);
  static double calculateSalaryAverage(const std::vector<Person> &persons);
  static int sumPersonIds(const std::vector<Person> &persons);



  //static int sumIntegers(const std::vector<int> &numbers);

};

#endif
