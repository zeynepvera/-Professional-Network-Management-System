
// ProfessionalNetworkSkills.hpp file
#ifndef PROFESSIONALNETWORKSKILLS_H
#define PROFESSIONALNETWORKSKILLS_H
#pragma once

#include <iostream>
#include <vector>
#include "Person.hpp"
#include "FileManager.hpp"
#include "Calculator.hpp"
#include "Database.hpp"

class ProfessionalNetworkSkills
{
private:
    std::vector<Person> persons;
    FileManager fileManager;

public:
    ProfessionalNetworkSkills();
    ~ProfessionalNetworkSkills();

    void startMenu();
    void displayMainMenu();
    void processMainMenuChoice(int choice);

    void displayPersons() const;
    void addPerson();
    void deletePerson();
    void writeFile();
    void readFile();
    void searchPersonById() const;
    void sortPersonsById();
    void sumPersonIdsAndDisplayTotal() const;
    void displayAgeAverages() const;
    void displaySalaryAverages() const;
    void addEmployee();
    void updatePersonAndFileById();
};

#endif
