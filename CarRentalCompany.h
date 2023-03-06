// CarRentalCompany
#ifndef CarRentalCompany_H_DEFINED
#define CarRentalCompany_H_DEFINED
#include "employee.h"
#include "car.h"

class Employee;
class Car;
class Customer;

class CarRentalCompany{
  private:
  char *name;
  int number_of_employees=0;

  //List of employees
  struct Employees {
  Employee *emp;
  Employees *next;
  };
  Employees *emp_head = nullptr;

  //List of cars
  struct Cars {
  Car *c;
  Cars *next;
  };
  Cars *car_head = nullptr;

  Car* check_car(Car &car); //method that checks if given car is on the list
  bool check_lessee(Customer &customer); //method that is used to do not let customer rent two cars from the same car rental company
  
  public:
  CarRentalCompany(char *name); //constructor
  ~CarRentalCompany(); //deconstructor

  const char* getName() const; //method to get private value


  //Employee methods:
  bool addEmployee(Employee &emp); //It is triggered only when the employee wants to join the company
  void removeEmployee(Employee &emp); //It is triggered only when the employee wants to quit the company // Maybe try changing it to bool?
  void print_employees(); //printing employees

  //Car methods:
  bool add_car(Car &car); //adding car to rental company
  void del_car(Car &car); //deleting car from rental company
  void print_cars(); //printing cars for given company

  //Customer methods:
  bool give_car(Car &car, Customer &customer); //it is triggered when customer wants to rent a car
  
 

};

#endif 