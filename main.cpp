#include "iostream"
#include "string.h"
#include "CircleList.cpp"
#include "CircleList.h"
#include "User.cpp"
#include "User.h"


    
int main()
{  
    Patient* pat = new Patient("230948aksjd", "John", "Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
    CircleList<Patient*> PL;
    PL.add(pat);
    PL.printQ();
   
   Employee emp("EMP001", "John", "Doe", "01/01/1990", "johndoe", "password123", "johndoe@example.com", 1234567890);
   
   return 0;

}


