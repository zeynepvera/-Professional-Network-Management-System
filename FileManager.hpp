// FileManager.hpp file

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <vector>
#include <fstream>
#include "Person.hpp"

class FileManager
{
public:
    static void writeToFile(const std::vector<Person> &persons, const std::string &fileName);
    static std::vector<Person> readFromFile(const std::string &fileName);
    static void updatePersonAndFileById(std::vector<Person> &persons, int id, const std::string &newFirstName, const std::string &newLastName, const std::string &newUsername, const std::string &newPassword, int newAge, double newSalary);
};

#endif
