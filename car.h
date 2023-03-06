// CAR - header file for car which can be rented from a car rental company
#ifndef CAR_H_DEFINED
#define CAR_H_DEFINED
#include "customer.h"
#include "CarRentalCompany.h"
using namespace std;

class CarRentalCompany;
class Customer;

class Car{
  private:
  char *name;
  int id;
  CarRentalCompany *owner; // company that owns a vehicle
  Customer *lessee; // person who rents a vehicle

  public:
  Car(char *name, int id); //constructor
  ~Car(); //deconstructor

  //methods to get private values
  char* getName();
  const int getId() const;
  const CarRentalCompany* getOwner() const;
  Customer* getLessee();

  const char* getNameOwner() const;
  char* getNameLessee();

  void setOwner(CarRentalCompany *owner); //It is triggered when the car is added to company
  void setLessee(Customer *lessee); //It is triggered when the car is rented by customer

  

};

#endif 