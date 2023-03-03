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

void Person::setAccessForEmployee()
{
    this->access = true;
}

Person::~Person()
{
    cout << "Person deleted";
}

// Employee

Employee::Employee(string empID, string name, string dob, string user, string pass, string email, int phone) : Person(name, dob, user, pass, email, phone) 
{
    this->empID = empID;
    this->setAccessForEmployee();
}

Employee::~Employee()
{
    cout << "Employee deleted";
}

// Patients 

Patient::Patient(string insuranceID, string name, string dob, string user, string pass, string email, int phone) : Person(name, dob, user, pass, email, phone) 
{
    this->paymentStatus = false;
    this->insuranceID = insuranceID;
}

Patient::~Patient()
{
    cout << "Patient deleted" << endl;
}

int main()
{

    Employee emp("EMP001", "John Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
    Patient pat("230948aksjd", "John Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
    return 0;
}