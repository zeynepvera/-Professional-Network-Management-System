// Person.h file

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class Person
{
private:
  int id;
  std::string firstName;
  std::string lastName;
  std::string username;
  std::string password;
  int age;
  double salary;

public:
  Person();
  Person(int id, const std::string &firstName, const std::string &lastName, const std::string &username, const std::string &password, int age, double salary);

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getUsername() const;
  std::string getPassword() const;
  int getId() const;
  int getAge() const;
  double getSalary() const;

  void setAge(int newAge);
  void setSalary(double newSalary);
  void setId(int newId);
  void setFirstName(const std::string &newFirstName);
  void setLastName(const std::string &newLastName);
  void setUsername(const std::string &newUsername);
  void setPassword(const std::string &newPassword);

  virtual void displayInfo() const;           
  bool operator==(const Person &other) const; 

};

#endif