// EMPLOYEE - header file for person working in a car rental company
#ifndef EMPLOYEE_H_DEFINED
#define EMPLOYEE_H_DEFINED
#include "CarRentalCompany.h"

class CarRentalCompany;

class Employee{
  private:
  char *name;
  char *surname;
  CarRentalCompany *employer;

  public:
  Employee(char *name, char *surname); //constructor
  ~Employee(); //deconstructor

  //methods to get private values
  const char* getName() const;
  const char* getSurname() const;
  const CarRentalCompany* getEmployer() const;

  //method that returns "No employer" if employee is not employed or otherwise it returns name of employer
  const char* getNameEmployer() const;

  //method to set employer of employee
  void setEmployer(CarRentalCompany *crc); 

  //method that lets employee join company
  bool join_company(CarRentalCompany &employer);

  //method that lets employee leave the company
  void leave_company();

};

#endif 