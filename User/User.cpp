#include "User.h"
#include "string"
#include "iostream"


using namespace std;

// ------------------------- Person -------------------------

Person::Person(string fname, string lname, string dob, string user, string pass, string email, int phone)
{
    this->fName = fname;
    this->lName = lname;
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

string Person::getName()
{
    string name = this->fName + " " + this->lName;
    return name;
}

string Person::getUsername()
{
    return this->username;
}

string Person::getPassword()
{
    return this->password;
}

// ------------------------- Employee -------------------------

Employee::Employee(string empID, string fname, string lname, string dob, string user, string pass, string email, int phone) : Person(fname, lname, dob, user, pass, email, phone) 
{
    this->empID = empID;
    this->setAccessForEmployee();
}

// ------------------------- Patients -------------------------

Patient::Patient(string insuranceID, string fname, string lname, string dob, string user, string pass, string email, int phone) : Person(fname, lname, dob, user, pass, email, phone) 
{
    this->paymentStatus = false;
    this->insuranceID = insuranceID;
}

bool Patient::getPaymentStatus()
{
    return this->paymentStatus;
}

void Patient::setPaymentStatus()
{
    this->paymentStatus = true;
}

