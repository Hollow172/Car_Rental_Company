#include <iostream>
#include "CarRentalCompany.h"
#include "customer.h"
#include "employee.h"
#include "car.h"
using namespace std;

//g++ -o main main.cpp employee.cpp customer.cpp CarRentalCompany.cpp car.cpp && main.exe

int main(){

cout<< "TESTING" <<endl; 

//Creating Employee and CarRentalCompany objects to check if they function properly
Employee e1((char*)"Employee", (char*)"One");
Employee e2((char*)"Employee", (char*)"Two");
CarRentalCompany crc1((char*)"Car Rental Company 1");
CarRentalCompany crc2((char*)"Car Rental Company 2");

cout<<e1.getName()<<" "<<e1.getSurname()<<endl;
cout<<e2.getName()<<" "<<e2.getSurname()<<endl;
cout<<crc1.getName()<<endl<<endl;

//Joining company and getting names of employer for person who is employed and for person who is unemployed
e1.join_company(crc1);
cout<<e1.getNameEmployer()<<endl;
cout<<e2.getNameEmployer()<<endl<<endl;
crc1.print_employees(); //Also printing employees for company
e2.join_company(crc1);
crc1.print_employees(); //Priting again after e2 joins company to see if everything is fine
cout<<endl;

//Leaving company and checking what changed
e1.leave_company(); 
crc1.print_employees();
cout<<e1.getNameEmployer()<<endl;
e2.leave_company();
crc1.print_employees();
cout<<e2.getNameEmployer()<<endl<<endl;

//Creating cars to check functionality
Car car1((char*)"Carname1", 1);
Car car2((char*)"Carname2", 2);
cout<<car1.getName()<<", ID = "<<car1.getId()<<endl;
cout<<car1.getNameOwner()<<endl;
cout<<car2.getName()<<", ID = "<<car2.getId()<<endl;
cout<<car2.getNameOwner()<<endl<<endl;

//Adding cars to company
crc1.add_car(car1);
crc1.add_car(car2);
crc1.print_cars();
cout<<car1.getNameOwner()<<endl;
cout<<car2.getNameOwner()<<endl;
crc1.del_car(car1);
crc1.del_car(car2);
crc1.print_cars();
cout<<car1.getNameOwner()<<endl;
cout<<car2.getNameOwner()<<endl<<endl;

//Testing functionality of car renting but to test that we need employees in company otherwise renting cars won't work
Customer customer1((char*)"Customer1", (char*)"One");
Customer customer2((char*)"Customer2", (char*)"Two");
cout<<customer1.getName()<<" "<<customer1.getSurname()<<endl;
cout<<customer2.getName()<<" "<<customer2.getSurname()<<endl<<endl;

e1.join_company(crc1);
e2.join_company(crc2);
crc1.print_employees();
crc2.print_employees();
crc1.add_car(car1);
crc2.add_car(car2);
crc1.print_cars();
crc2.print_cars();
cout<<car1.getNameLessee()<<endl;
cout<<car2.getNameLessee()<<endl;
customer1.rent_car(crc1, car1);
customer1.rent_car(crc2, car2);
cout<<car1.getNameLessee()<<endl;
cout<<car2.getNameLessee()<<endl;
customer1.print_rented_cars();
customer1.return_car(car1);
customer1.print_rented_cars();
customer1.return_car(car2);
customer1.print_rented_cars();
cout<<car1.getNameLessee()<<endl;
cout<<car2.getNameLessee()<<endl;

cout<<endl<<endl;

//TESTING DESTRUCTORS:

cout<< "TESTING DESTRUCTORS"<<endl;

Employee e5((char*)"Employee", (char*)"Five");
CarRentalCompany crc5((char*)"Car Rental Company 5");
Car car5((char*)"Carname5", 5);
Customer customer5((char*)"Customer5", (char*)"Five");

e5.join_company(crc5);
crc5.add_car(car5);

//DESTRUCTOR FOR EMPLOYEE:
{
    Employee dele1((char*)"Destructor", (char*)"Employee");
    dele1.join_company(crc5);
    crc5.print_employees();
}
  crc5.print_employees();
  cout<<endl;

//DESTRUCTOR FOR CAR:
{
    Car delcar1((char*)"Destructor_car", 10);
    crc5.add_car(delcar1);
    crc5.print_cars();
    customer5.rent_car(crc5, delcar1);
    customer5.print_rented_cars();
}
  crc5.print_cars();
  customer5.print_rented_cars();
  cout<<endl;

//DESTRUCTOR FOR CUSTOMER:
{
    Customer delcustomer5((char*)"Destructor", (char*)"Customer");
    delcustomer5.rent_car(crc5, car5);
    cout<<car5.getNameLessee()<<endl;
}
    cout<<car5.getNameLessee()<<endl;
    cout<<endl;

//DESTRUCTOR FOR CAR RENTAL COMPANY:
    e5.leave_company();
    crc5.del_car(car5);
{
    CarRentalCompany delcrc5((char*)"Destructor Car Rental Company 5");
    e5.join_company(delcrc5);
    delcrc5.add_car(car5);
    cout<<car5.getNameOwner()<<endl;
    customer5.rent_car(delcrc5, car5);
    cout<<car5.getNameLessee()<<endl;
    customer5.print_rented_cars();
    
}
    cout<<car5.getNameOwner()<<endl;
    cout<<car5.getNameLessee()<<endl;
    customer5.print_rented_cars();


cout<<endl<<endl;


cout<<"Testing edge cases: "<<endl;
Employee te1((char*)"TEST_EMPLOYEE", (char*)"One");
CarRentalCompany tcrc1((char*)"TEST_Car Rental Company 1");
Car tcar1((char*)"TEST_Carname1", 110);
Car tcar2((char*)"TEST_Carname2", 120);
Customer tcustomer1((char*)"TEST_Customer1", (char*)"One");

//Renting car without any employees (car rental company cannot allow customers to rent a car without any employees)
tcrc1.add_car(tcar1);
tcrc1.add_car(tcar2);
tcrc1.print_employees();
tcrc1.print_cars();
tcustomer1.rent_car(tcrc1, tcar1);
tcustomer1.print_rented_cars();
cout<<tcar1.getNameLessee()<<endl;

cout<<endl;

//Renting two cars from one company (it is not allowed)
te1.join_company(tcrc1);
tcustomer1.rent_car(tcrc1, tcar1);
tcustomer1.print_rented_cars();
cout<<tcar1.getNameLessee()<<endl;
tcustomer1.rent_car(tcrc1, tcar2);
tcustomer1.print_rented_cars();
cout<<tcar2.getNameLessee()<<endl;

cout<<endl;

//Employee wants to join a company while being employed to another one (not allowed)
CarRentalCompany tcrc2((char*)"TEST_Car Rental Company 2");
cout<<te1.getNameEmployer()<<endl;
te1.join_company(tcrc2);
cout<<te1.getNameEmployer()<<endl;
tcrc2.print_employees();

cout<<endl;

//Trying to rent a car that doesn't belong to company (not allowed)
Car tcar3((char*)"TEST_Carname3", 130);
Customer tcustomer2((char*)"TEST_Customer2", (char*)"Two");
tcustomer2.rent_car(tcrc1, tcar3);
cout<<tcar3.getNameLessee()<<endl;
tcustomer2.print_rented_cars();

cout<<endl;

//Trying to rent a car that is already rented by someone else (not allowed)
Car tcar4((char*)"TEST_Carname4", 140);
Customer tcustomer3((char*)"TEST_Customer3", (char*)"Three");
Customer tcustomer4((char*)"TEST_Customer4", (char*)"Four");
tcrc1.add_car(tcar4);
tcustomer3.rent_car(tcrc1, tcar4);
cout<<tcar4.getNameLessee()<<endl;
tcustomer3.print_rented_cars();
tcustomer4.rent_car(tcrc1, tcar4);
cout<<tcar4.getNameLessee()<<endl;
tcustomer4.print_rented_cars();


}