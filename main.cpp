#include "iostream"
#include "string.h"
#include "fstream"
#include "bits/stdc++.h"

#include "./CircleList/CircleList.cpp"
#include "./CircleList/CircleList.h"
#include "./User/User.cpp"
#include "./User/User.h"

using namespace std;

// ------------------------------- Employee Data -------------------------------

CircleList<Employee*> loadEmployeeData()
{
  CircleList<Employee*> employeeData;
  Employee* emp1 = new Employee("emp1","Otto","Octavius","02/22/1980","drock","test","doc@marvel.com", 8123123);
  Employee* emp2 = new Employee("emp2","Peter","Parker","02/22/1980","spidy","test","spider@marvel.com", 8123234);
  Employee* emp3 = new Employee("emp3","Aunt","may","02/22/1980","may","test","may@marvel.com", 8123234);

  employeeData.add(emp1);
  employeeData.add(emp2);
  employeeData.add(emp3);
  return employeeData;
}

// ------------------------------- Main -------------------------------

// Used to stop the console to let users see the messages and output
void pause()
{   
    string dummy;
    cout << "\n\nEnter any key and press Enter to continue:";
    cin >> dummy;
}

// ------------------------------- Main -------------------------------

int main()
{  
  CircleList<Employee*> employeeList = loadEmployeeData();
  CircleList<Patient*> patientList;

  int menuChoice = 0;
  do
  {
    system("clear");                                                                            //linux 
    cout << "\t\t\tWelcome to Doc Ock's Office" << endl << endl;
    cout << " 1. Employee Login\n 2. Current Waitlist\n 3. Exit" << endl;
    cout << " Enter the corresponding number of the options from above options(eq : 1) :";
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
      Employee* sessionEmp = employeeList.employeeAuth(empUsername,empPassword);
      if(sessionEmp)
      {
        int employeeMenu;
        do
        {
          employeeMenu = 0;
          system("clear");                                                                            //linux 
          cout << "\t\t\tDoc Ock's Office" << endl << endl;
          cout << " Welcome, " << sessionEmp->getName() << endl; 
          cout << " What would you like to do? :)" << endl << endl;
          cout << " 1. Show Patient WaitList \n 2. Add Patient \n 3. Pop Patient \n 4. Logout" << endl;
          cout << " Enter the corresponding number of the options from above options(eq : 1) :";
          cin >> employeeMenu;
          
          switch (employeeMenu)
          {
            case 1:
              patientList.printQ();
              pause();
              break;
            case 2:
              break;
            case 3:
              patientList.remove();
              break;    
            case 4:
              employeeMenu = 4;
              break;
            default:
              cout << "invalid Entry try again" << endl;
              break;
          }
        } while (employeeMenu != 4);
      }
    }
    else if(menuChoice == 2)
    {
      patientList.printQ();
      pause();
    } 
    else
    {
      menuChoice = 3;
    }
  } while (menuChoice != 3);
    
    
   return 0;
}


