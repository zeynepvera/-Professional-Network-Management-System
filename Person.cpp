

// Person.cpp file

#include <iostream> 
#include <string>

Person::Person() : id(0), firstName(""), lastName(""), username(""), password(""), age(0), salary(0.0) {}

Person::Person(int id, const std::string &firstName, const std::string &lastName, const std::string &username, const std::string &password, int age, double salary)
    : id(id), firstName(firstName), lastName(lastName), username(username), password(password), age(age), salary(salary) {}

int Person::getId() const
{
    return id;
}

void Person::displayInfo() const
{
    std::cout << "ID: " << id << "\n";
    std::cout << "Name: " << firstName << " " << lastName << "\n";
    std::cout << "Username: " << username << "\n";
    std::cout << "Password: " << password << "\n";
    std::cout << "Age: " << age << "\n";       
    std::cout << "Salary: " << salary << "\n"; 
}

std::string Person::getFirstName() const
{
    return firstName;
}

std::string Person::getLastName() const
{
    return lastName;
}

std::string Person::getUsername() const
{
    return username;
}

std::string Person::getPassword() const
{
    return password;
}

void Person::setId(int newId)
{
    id = newId;
}

void Person::setFirstName(const std::string &newFirstName)
{
    firstName = newFirstName;
}

void Person::setLastName(const std::string &newLastName)
{
    lastName = newLastName;
}

void Person::setUsername(const std::string &newUsername)
{
    username = newUsername;
}

void Person::setPassword(const std::string &newPassword)
{
    password = newPassword;
}
int Person::getAge() const
{
    return age;
}

double Person::getSalary() const
{
    return salary;
}

void Person::setAge(int newAge)
{
    age = newAge;
}

void Person::setSalary(double newSalary)
{
    salary = newSalary;
}



bool Person::operator==(const Person &other) const
{
    return id == other.id &&
           firstName == other.firstName &&
           lastName == other.lastName &&
           username == other.username &&
           password == other.password &&
           age == other.age &&
           salary == other.salary;
}

