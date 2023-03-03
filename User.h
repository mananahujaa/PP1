#include "cstddef"
#include "iostream"
#include "string"

#ifndef User_H
#define User_H

using namespace std;

class Person
{
    private:
        string Name;
        string dateOfBirth;
        string username;
        string password;
        string email;
        bool access;
        int phone;
    public:

        // Conctructor assign data
        Person(string name, string dob, string user, string pass, string email, int phone);

        // Function to set access to TRUE for employees
        void setAccessForEmployee();

        // Destructor
        ~Person();

};

class Employee : public Person 
{   private:
        string empID;
    public:

        // Constructor to assign Employee ID and give access
        Employee(string empID, string name, string dob, string user, string pass, string email, int phone);

        // Destructor
        ~Employee();
};

class Patient : public Person
{
    private:
        bool paymentStatus;
        string insuranceID;
    public:

        // Constructor to assign insuranceID for 
        Patient(string insuranceID, string name, string dob, string user, string pass, string email, int phone);

        // Destructor
        ~Patient();
};

#endif