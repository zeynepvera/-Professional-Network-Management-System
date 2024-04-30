// FileManager.cpp file

#include "FileManager.hpp"
#include <iostream>
#include <vector>
#include <fstream>

void FileManager::writeToFile(const std::vector<Person> &persons, const std::string &fileName)
{
    std::ofstream outFile(fileName);

    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open the file for writing: " << fileName << "\n";
        return;
    }
    for (const auto &person : persons)
    {
        outFile << person.getId() << ","
                << person.getFirstName() << ","
                << person.getLastName() << ","
                << person.getUsername() << ","
                << person.getPassword() << "\n";
    }

    outFile.close();
}


std::vector<Person> FileManager::readFromFile(const std::string &fileName)
{
    std::vector<Person> persons;

    std::ifstream inFile(fileName);

    if (!inFile.is_open())
    {
        std::cerr << "Error: Could not open the file for reading: " << fileName << "\n";
        return persons;
    }

    int id, age;   
    double salary; 

    std::string firstName, lastName, username, password;

    while (inFile >> id >> firstName >> lastName >> username >> password >> age >> salary)
    {
        persons.push_back(Person(id, firstName, lastName, username, password, age, salary));
    }

    inFile.close();

    return persons;
}



void FileManager::updatePersonAndFileById(std::vector<Person> &persons, int id, const std::string &newFirstName,
                                   const std::string &newLastName, const std::string &newUsername,
                                   const std::string &newPassword, int newAge, double newSalary)
{
    for (auto &person : persons)
    {
        if (person.getId() == id)
        {
            person.setFirstName(newFirstName);
            person.setLastName(newLastName);
            person.setUsername(newUsername);
            person.setPassword(newPassword);
            person.setAge(newAge);
            person.setSalary(newSalary);
            break;
        }
    }

    // Dosyada güncelleme yapma
    std::ofstream outFile("kisiler.txt");

    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open the file for writing: kisiler.txt\n";
        return;
    }

    for (const auto &person : persons)
    {
        outFile << person.getId() << ","
                << person.getFirstName() << ","
                << person.getLastName() << ","
                << person.getUsername() << ","
                << person.getPassword() << ","
                << person.getAge() << ","
                << person.getSalary() << "\n";
    }

    outFile.close();
}