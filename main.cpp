#include "iostream"
#include "string.h"
#include "conio.h"
#include "fstream"
#include "bits/stdc++.h"

#include "./CircleList/CircleList.cpp"
#include "./CircleList/CircleList.h"
#include "./User/User.cpp"
#include "./User/User.h"

using namespace std;

CircleList<Employee*> loadEmployeeData()
{
  CircleList<Employee*> employeeData;
  Employee* emp1 = new Employee("emp1","Otto","Octavius","02/22/1980","drock","test","doc@marvel.com", 8123123);
  employeeData.add(emp1);
  return employeeData;
}

int main()
{  
  CircleList<Employee*> employeeList = loadEmployeeData();
  CircleList<Patient*> patientList;

  int menuChoice = 0;
  do
  {
    system("cls");                                                                              //windows
    system("clear");                                                                            //linux 
    cout << "\t\t\tWelcome to Doc Ock's Office" << endl << endl;
    cout << " 1. Employee Login\n 2. Current Waitlist\n 3. Exit" << endl;
    cout << " Please select one of the options from above(eq : 1) :";
    cin >> menuChoice;

    if (menuChoice == 1)
    {
        string empUsername, empPassword;
        system("clear");
        cout << "\t\t\tLogin" << endl << endl;
        cout << " Username: ";
        cin >> empUsername;
        cout << endl << " Password: ";
        cin >> empPassword;
        bool auth = employeeList.employeeAuth(empUsername,empPassword);

    } 
  } while (menuChoice != 3);
    
    






    Patient* pat = new Patient("230948aksjd", "John", "Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
    Patient* pat1 = new Patient("230948asdaksjd", "mannu", "Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
    CircleList<Patient*> PL;
    PL.add(pat);
    PL.add(pat1);
    PL.printQ();
    PL.remove();
    PL.printQ();
   
   Employee emp("EMP001", "John", "Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
   




   
   return 0;



}


