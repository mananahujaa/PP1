#include "cstddef"
#include "iostream"
#include "string"

#ifndef User_H
#define User_H

using namespace std;

class Person
{
    private:
        string fName;           //First name
        string lName;           //Last name
        string dateOfBirth;
        string username;
        string password;
        string email;
        bool access;
        int phone;

    public:

        // Conctructor assign data
        Person(string fname, string lname, string dob, string user, string pass, string email, int phone);

        // Function to set access to TRUE for employees
        void setAccessForEmployee();

        string getName();

        string getUsername();

        string getPassword();

};

class Employee : public Person 
{   
    private:
        string empID;

    public:

        // Constructor to assign Employee ID and give access (FYI the setAccessForEmployee() get called here)
        Employee(string empID, string fname, string lname, string dob, string user, string pass, string email, int phone);

};

class Patient : public Person
{
    private:
        bool paymentStatus;
        string insuranceID;

    public:

        // Constructor to assign insuranceID for 
        Patient(string insuranceID, string fname, string lname, string dob, string user, string pass, string email, int phone);

        // Get payment status
        bool getPaymentStatus();

        // Set payment status to true
        void setPaymentStatus();

};

#endif
