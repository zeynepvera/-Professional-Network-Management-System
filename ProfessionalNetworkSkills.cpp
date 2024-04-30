// ProfessionalNetworkSkills.cpp file

#include "ProfessionalNetworkSkills.hpp"
#include <iostream>
#include <algorithm>
#include "Employee.hpp" 

ProfessionalNetworkSkills::ProfessionalNetworkSkills()
{
}

ProfessionalNetworkSkills::~ProfessionalNetworkSkills()
{
}

void ProfessionalNetworkSkills::startMenu()
{
    int choice;

    do
    {
        std::cout<<"\n\n ---------------- MENU----------------\n"; 
        displayMainMenu();
        std::cout << "\nSeciminizi yapin: ";
        std::cin >> choice;

        processMainMenuChoice(choice);

    } while (choice != 0);
}

void ProfessionalNetworkSkills::displayMainMenu()
{
    std::cout << "\n1. Kisileri Goster\n";
    std::cout << "2. Kisi Ekle\n";
    std::cout << "3. Kisi Sil\n";
    std::cout << "4. Dosyaya Yaz\n";
    std::cout << "5. Dosyadan Oku\n";
    std::cout << "6. Person ID'leri Topla ve Goster\n";  
    std::cout << "7. Kisi Ara ve Goster\n";              
    std::cout << "8. Kisileri ID'ye Gore Sirala\n";      
    std::cout << "9. Yas Ortalamasini Goster\n"; 
        std::cout << "10. Maas Ortalamasini Goster\n"; 
    std::cout << "11. Kisiyi Guncelle ve dosyaida\n"; 


    std::cout << "0. cikis\n";
}

void ProfessionalNetworkSkills::processMainMenuChoice(int choice)
{
    switch (choice)
    {
    case 1:
        displayPersons();
        break;
    case 2:
        addPerson();
        break;
    case 3:
        deletePerson();
        break;
    case 4:
        writeFile();
        break;
    case 5:
        readFile();
        break;
    case 6:
        sumPersonIdsAndDisplayTotal(); 
        break;
    case 7:
        searchPersonById(); 
        break;
    case 8:
        sortPersonsById(); 
        break;
    case 9:
        displayAgeAverages(); 
        break;
    case 10:
        displaySalaryAverages();
        break;
        case 11:
        updatePersonAndFileById();
        break;
    case 0:
        std::cout << "cikis yapiliyor...\n";
        break;
    default:
        std::cout << "Geçersiz seçim. Tekrar deneyin.\n";
    }
}

void ProfessionalNetworkSkills::displayPersons() const
{
    std::cout << "Kisiler:\n";
    for (const auto &person : persons)
    {
        person.displayInfo();
        std::cout << "--------------\n";
    }
}

void ProfessionalNetworkSkills::addPerson()
{
    int id;
    std::string firstName, lastName, username, password;
    int age;
    double salary;

    std::cout << "ID: ";
    std::cin >> id;

    // ID kontrolü
    auto idExists = std::find_if(persons.begin(), persons.end(), [id](const Person &person)
                                 { return person.getId() == id; });

    if (idExists != persons.end())
    {
        std::cout << "Hata: Bu ID'ye sahip bir kisi zaten var. Lutfen farkli bir ID girin.\n";
        return;
    }
    std::cout << "Ad: ";
    std::cin >> firstName;
    std::cout << "Soyad: ";
    std::cin >> lastName;
    std::cout << "Kullanici adi: ";
    std::cin >> username;
    std::cout << "sifre: ";
    std::cin >> password;
    std::cout << "Yas: ";
    std::cin >> age; 
    std::cout << "Maas: ";
    std::cin >> salary; 

    double ageAverage = Calculator::calculateAgeAverage(persons);
    double salaryAverage = Calculator::calculateSalaryAverage(persons);
    std::cout << "Yas Ortalamasi: " << ageAverage << "\n";
    std::cout << "Maas Ortalamasi: " << salaryAverage << "\n";

    Person newPerson(id, firstName, lastName, username, password, age, salary);
    persons.push_back(newPerson);

    Database::addAge(age);
    Database::addSalary(salary);

    std::cout << "Kisi basariyla eklendi.\n";
}

void ProfessionalNetworkSkills::deletePerson()
{
    int idToDelete;
    std::cout << "Silmek istediginiz kisinin ID'sini girin: ";
    std::cin >> idToDelete;

    auto it = std::remove_if(persons.begin(), persons.end(), [idToDelete](const Person &person)
                             { return person.getId() == idToDelete; });

    if (it != persons.end())
    {
        persons.erase(it, persons.end());
        std::cout << "Kisi basariyla silindi.\n";
    }
    else
    {
        std::cout << "Belirtilen ID'ye sahip kisi bulunamadi.\n";
    }
}

void ProfessionalNetworkSkills::writeFile()
{
    std::string fileName;
    std::cout << "Dosya adini girin: ";
    std::cin >> fileName;

    FileManager::writeToFile(persons, fileName);
    std::cout << "Kisiler dosyaya yazildi.\n";
}

void ProfessionalNetworkSkills::readFile()
{
    std::string fileName;
    std::cout << "Dosya ad girin: ";
    std::cin >> fileName;

    persons = FileManager::readFromFile(fileName);
    std::cout << "Kişiler dosyadan okundu.\n";
}

void ProfessionalNetworkSkills::searchPersonById() const
{
    int idToSearch;
    std::cout << "Aranacak kisinin ID'sini girin: ";
    std::cin >> idToSearch;

    auto it = std::find_if(persons.begin(), persons.end(), [idToSearch](const Person &person)
                           { return person.getId() == idToSearch; });

    if (it != persons.end())
    {
        std::cout << "Aranan Kisi:\n";
        it->displayInfo();
    }
    else
    {
        std::cout << "Belirtilen ID'ye sahip kisi bulunamadi.\n";
    }
}

void ProfessionalNetworkSkills::sumPersonIdsAndDisplayTotal() const {
    int totalPersonIds = Calculator::sumPersonIds(persons);
    std::cout << "Toplam Person ID'leri: " << totalPersonIds << "\n";
}
void ProfessionalNetworkSkills::sortPersonsById()
{
    std::sort(persons.begin(), persons.end(), [](const Person &a, const Person &b)
              { return a.getId() < b.getId(); });
    std::cout << "Kisiler ID'ye gore siralandi.\n";
}

void ProfessionalNetworkSkills::displayAgeAverages() const
{
    // Kişilerin yaşlarını içeren bir vektör oluşturun
    std::vector<Person> personsWithAges;
    for (const auto &person : persons)
    {
        personsWithAges.push_back(person);
    }

    // Calculator sınıfından yaş ortalamasını hesaplayın
    double ageAverage = Calculator::calculateAgeAverage(personsWithAges);

    std::cout << "Yas Ortalamasi: " << ageAverage << "\n";
}

void ProfessionalNetworkSkills::displaySalaryAverages() const
{
    // Kişilerin maaşlarını içeren bir vektör oluşturma
    std::vector<Person> personsWithSalaries;
    for (const auto &person : persons)
    {
        personsWithSalaries.push_back(person);
    }

    // Calculator sınıfından maaş ortalamasını hesaplama
    double salaryAverage = Calculator::calculateSalaryAverage(personsWithSalaries);

    std::cout << "Maas Ortalamasi: " << salaryAverage << "\n";
}

void ProfessionalNetworkSkills::addEmployee()
{
    int id;
    std::string firstName, lastName, username, password;
    int age;
    double salary;


    std::cout << "Pozisyon: ";
    std::string position;
    std::cin >> position; 

    // Calculator sınıfına ait yaş ve maaş ortalama hesaplama fonksiyonlarını çağırma 
    double ageAverage = Calculator::calculateAgeAverage(persons);
    double salaryAverage = Calculator::calculateSalaryAverage(persons);
    std::cout << "Yas Ortalamasi: " << ageAverage << "\n";
    std::cout << "Maas Ortalamasi: " << salaryAverage << "\n";

    Employee newEmployee(id, firstName, lastName, username, password, age, salary, position);
    persons.push_back(newEmployee);

    // Database sınıfına yaş ve maaşı ekle
    Database::addAge(age);
    Database::addSalary(salary);

    std::cout << "Calisan basariyla eklendi.\n";
}

void ProfessionalNetworkSkills::updatePersonAndFileById()
{
    int idToUpdate;
    std::cout << "Guncellenecek kisinin ID'sini girin: ";
    std::cin >> idToUpdate;

    auto it = std::find_if(persons.begin(), persons.end(), [idToUpdate](const Person &person)
                           { return person.getId() == idToUpdate; });

    if (it != persons.end())
    {
        std::string newFirstName, newLastName, newUsername, newPassword;
        int newAge;
        double newSalary;

        std::cout << "Yeni Ad: ";
        std::cin >> newFirstName;
        std::cout << "Yeni Soyad: ";
        std::cin >> newLastName;
        std::cout << "Yeni Kullanici Adi: ";
        std::cin >> newUsername;
        std::cout << "Yeni Sifre: ";
        std::cin >> newPassword;
        std::cout << "Yeni Yas: ";
        std::cin >> newAge;
        std::cout << "Yeni Maas: ";
        std::cin >> newSalary;

        it->setFirstName(newFirstName);
        it->setLastName(newLastName);
        it->setUsername(newUsername);
        it->setPassword(newPassword);
        it->setAge(newAge);
        it->setSalary(newSalary);

        FileManager::writeToFile(persons, "kisiler.txt");

        std::cout << "Kisi basariyla guncellendi ve dosyaya yazildi.\n";
    }
    else
    {
        std::cout << "Belirtilen ID'ye sahip kisi bulunamadi.\n";
    }
}
