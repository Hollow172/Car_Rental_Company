// CUSTOMER - header file for a customer in car rental company
#ifndef CUSTOMER_H_DEFINED
#define CUSTOMER_H_DEFINED
#include "car.h"

class CarRentalCompany;
class Car;

class Customer{
  private:
  char *name;
  char *surname;

  struct Cars {
  Car *c;
  Cars *next;
  };
  Cars *head=nullptr;

  public:
  Customer(char *name, char *surname);
  ~Customer();

  //methods to get private values
  const char* getName() const;
  const char* getSurname() const;

  //method to rent a car
  bool rent_car(CarRentalCompany &company, Car &car);

  //method to return a car
  void return_car(Car &car); 

  //method to print cars that are rented by customer
  void print_rented_cars();


};

#endif 