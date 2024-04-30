
//Database.hpp file

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>

class Database
{
public:
    static std::vector<int> ages;     
    static std::vector<double> salaries;  
    
    static void addAge(int age);
    static void addSalary(double salary);
};

#endif































/*//Database.hpp file



#ifndef DATABASE_H
#define DATABASE_H

#include <vector>

class Database
{
public:
     static std::vector<int> intArray;
     static std::vector<double> doubleArray;

    static void addInt(int value);
     static void addDouble(double value);
};

#endif*/

