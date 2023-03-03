#include "User.h"
#include "string"
#include "iostream"


using namespace std;

// Person 

Person::Person(string name, string dob, string user, string pass, string email, int phone)
{
    this->Name = name;
    this->dateOfBirth = dob;
    this->username = user;
    this->password = pass;
    this->email = email;
    this->phone = phone;
    this->access = false;
}

Person::~Person()
{
    cout << "deleted";
}

// Employee

Employee::Employee(string empID, string name, string dob, string user, string pass, string email, int phone) : Person(name, dob, user, pass, email, phone) 
{
    this->empID = empID;
}

Employee::~Employee()
{
    cout << "deleted";
}

int main()
{

    Employee emp("EMP001", "John Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
    return 0;
}