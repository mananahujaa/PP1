#include "iostream"
#include "string.h"
#include "fstream"
#include "unistd.h"
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

// ------------------------------- Patient Data -------------------------------

CircleList<Patient*> loadPatientData()
{
  CircleList<Patient*> patientData;
  Patient* pat1 = new Patient("united123","Mary","Jane","02/22/1993","mary","testp","mary@marvel.com",982312);
  Patient* pat2 = new Patient("united1123","Gwen","Maxwell","02/21/1993","gwen","testp","gwen@marvel.com",282312);

  patientData.add(pat1);
  patientData.add(pat2);
  return patientData;
}

// ------------------------------- Misc Functions -------------------------------

// Used to stop the console to let users see the messages and output
void sys_pause()
{   
    sleep(3);
}

Patient* createPatient() {
    string insuranceID, fName, lName, dob, username, password, email;
    int phone;
    
    cout << "Enter insurance ID: ";
    cin.ignore();
    getline(cin, insuranceID);

    cout << "Enter first name: ";
    getline(cin, fName);

    cout << "Enter last name: ";
    getline(cin, lName);

    cout << "Enter date of birth: ";
    getline(cin, dob);

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter phone number: ";
    cin >> phone;
    cin.ignore();
    Patient* newPatient = new Patient(insuranceID, fName, lName, dob, username, password, email, phone);
    return newPatient;
}


// ------------------------------- Main -------------------------------

int main()
{  
  CircleList<Employee*> employeeList = loadEmployeeData();
  CircleList<Patient*> patientList = loadPatientData();

  Patient* newPatient = NULL;

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
          cout << " 1. Show Patient WaitList \n 2. Add Patient to Waitlist \n 3. Check-In Patient \n 4. Logout" << endl;
          cout << " Enter the corresponding number of the options from above options(eq : 1) :";
          cin >> employeeMenu;
          
          switch (employeeMenu)
          {
            case 1:
              patientList.printQ();
              sys_pause();
              break;
            case 2:
              newPatient  = createPatient();
              newPatient->setPaymentStatus();
              patientList.add(newPatient);
              cout << "Patient has been sucesfully added into the waitlist!!!!" << endl;
              sys_pause();
              break;
            case 3:
              patientList.remove();
              sys_pause();
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
      else
      {
        cout << "The user doesnt exist or invalid credentials. Please try again!!!" << endl;
        sys_pause();
      }
    }
    else if(menuChoice == 2)
    {
      patientList.printQ();
      sys_pause();
    } 
    else
    {
      menuChoice = 3;
    }
  } while (menuChoice != 3);
    
    
   return 0;
}


