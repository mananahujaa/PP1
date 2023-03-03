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
        Person(string name, string dob, string user, string pass, string email, int phone);
        ~Person();

};

class Employee : public Person 
{   private:
        string empID;
    public:
        Employee(string empID, string name, string dob, string user, string pass, string email, int phone);
        ~Employee();
        void AcessSetter();
};

#endif