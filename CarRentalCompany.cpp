#include "CarRentalCompany.h"
#include <iostream>
#include <cstring>

using namespace std;

CarRentalCompany::CarRentalCompany(char *name){
    this->name=new char[strlen(name)+1];
    strcpy(this->name, name);
}

const char* CarRentalCompany::getName() const{
    return this->name;
}

CarRentalCompany::~CarRentalCompany(){

    CarRentalCompany::Cars *pointer_car = CarRentalCompany::car_head;
    while(pointer_car){
        pointer_car = pointer_car->next;
        if(CarRentalCompany::car_head->c->getLessee()!=nullptr){
            CarRentalCompany::car_head->c->getLessee()->return_car(*CarRentalCompany::car_head->c);
        } 
        CarRentalCompany::car_head->c->setOwner(nullptr);
        delete CarRentalCompany::car_head;
        CarRentalCompany::car_head = pointer_car;
    }
    CarRentalCompany::car_head=nullptr;

    CarRentalCompany::Employees *pointer_emp = CarRentalCompany::emp_head;
    while(pointer_emp){
        pointer_emp = pointer_emp->next;
        CarRentalCompany::emp_head->emp->setEmployer(nullptr);
        delete CarRentalCompany::emp_head;
        CarRentalCompany::emp_head = pointer_emp;
    }
    CarRentalCompany::emp_head=nullptr;

    delete[] this->name;
}


//EMPLOYEES:

bool CarRentalCompany::addEmployee(Employee &emp){
    if(emp.getEmployer()!=nullptr){
        return false;
    }
    CarRentalCompany::Employees *newEmployee = new CarRentalCompany::Employees;
    newEmployee->emp = &emp;
    newEmployee->next = CarRentalCompany::emp_head;
    CarRentalCompany::emp_head = newEmployee;

    this->number_of_employees++;

    return true;
}

void CarRentalCompany::removeEmployee(Employee &emp){
    if(!CarRentalCompany::emp_head) return;
    CarRentalCompany::Employees *pointer = CarRentalCompany::emp_head;
    CarRentalCompany::Employees *previous = nullptr;

    while(pointer!=nullptr){
        if(pointer->emp->getName()==emp.getName() && pointer->emp->getSurname()==emp.getSurname()){
            if(previous!=nullptr){
                previous->next = pointer->next;
            }else{
                CarRentalCompany::emp_head = pointer->next;
            }
            delete pointer;
            this->number_of_employees--;
            emp.setEmployer(nullptr);
            break;
        }
    previous = pointer;
    pointer = pointer->next;
    }
    

}

void CarRentalCompany::print_employees(){
    CarRentalCompany::Employees *pointer = CarRentalCompany::emp_head;

    cout<<"List of employees of "<<this->getName()<<": "<<endl;
    if(pointer == nullptr){
        cout <<"This company has no employees"<< endl;
    } 
    int i=1;
    while(pointer!=nullptr){
        cout<<i <<". " << pointer->emp->getName(); 
        cout<<" ";
        cout<<pointer->emp->getSurname() << endl;
        pointer = pointer->next;
        i++;
    }

}

//CARS:

bool CarRentalCompany::add_car(Car &car){
    if(car.getOwner()!=nullptr){
        return false;
    }
    CarRentalCompany::Cars *newCar = new CarRentalCompany::Cars;
    newCar->c = &car;
    newCar->next = CarRentalCompany::car_head;
    CarRentalCompany::car_head = newCar;
    car.setOwner(this);
    return true;
}

void CarRentalCompany::del_car(Car &car){
    if(!CarRentalCompany::car_head) return;
    CarRentalCompany::Cars *pointer = CarRentalCompany::car_head;
    CarRentalCompany::Cars *previous = nullptr;

    while(pointer!=nullptr){
        if(pointer->c->getId()==car.getId()){
            if(previous!=nullptr){
                previous->next = pointer->next;
            }else{
                CarRentalCompany::car_head = pointer->next;
            }
            delete pointer;
            car.setOwner(nullptr);
            break;
        }
    previous = pointer;
    pointer = pointer->next;
    }

}

void CarRentalCompany::print_cars(){
    CarRentalCompany::Cars *pointer = CarRentalCompany::car_head;

    cout<<"List of cars of "<<this->getName()<<": "<<endl;
    if(pointer == nullptr){
        cout <<"This company has no cars"<< endl;
    } 
    int i=1;
    while(pointer!=nullptr){
        cout<<i <<". " << pointer->c->getName(); 
        cout<<" ";
        cout<<pointer->c->getId() << endl;
        pointer = pointer->next;
        i++;
    }

}

 Car* CarRentalCompany::check_car(Car &car){
     Cars *pointer = car_head;
     while(pointer!=nullptr){
         if(pointer->c->getId() == car.getId()){
             return pointer->c;
         }
         pointer = pointer->next;
     }
     return nullptr;
 }

bool CarRentalCompany::check_lessee(Customer &customer){
    bool can_rent = true;
    Cars *pointer = car_head;
    while(pointer!=nullptr){
        if(pointer->c->getNameLessee() == customer.getName()){
            can_rent = false;
        }
        pointer = pointer->next;
    }
    return can_rent;
 }


//CUSTOMER:

bool CarRentalCompany::give_car(Car &car, Customer &customer){
    if(this->number_of_employees <=0) return false;
    Car* result = check_car(car);
    bool result_lessee = check_lessee(customer);
    if(result==nullptr) return false;
    if(result_lessee==false) return false;
    if(result->getLessee()!=nullptr) return false;
    result->setLessee(&customer);
    return true;
}

