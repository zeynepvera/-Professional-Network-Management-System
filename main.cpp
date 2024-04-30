
//main.cpp file 


#include "ProfessionalNetworkSkills.cpp"
#include "FileManager.cpp"
#include "Person.cpp"
#include "Database.cpp"
#include "Calculator.cpp"
#include "Employee.cpp"
#include <iostream>




 
int main()
{
    ProfessionalNetworkSkills networkSkills;
    networkSkills.startMenu();



    // Dosyadan okuma işlemi
    std::vector<Person> personsFromFile = FileManager::readFromFile("kisiler.txt");

    // Okunan kişileri ekrana yazdırma
    std::cout << "Dosyadan Okunan Kisiler:\n";
    for (const auto &person : personsFromFile)
    {
        person.displayInfo();
        std::cout << "--------------\n";
    }
       

    return 0;
    
}
