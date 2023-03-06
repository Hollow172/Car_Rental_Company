#include "customer.h"
#include <iostream>
#include <cstring>

using namespace std;

Customer::Customer(char *name, char *surname){
    this->name=new char[strlen(name)+1];
    strcpy(this->name, name);
    this->surname=new char[strlen(surname)+1];
    strcpy(this->surname, surname);
}

Customer::~Customer(){
    Customer::Cars *pointer = Customer::head;
    while(pointer){
        pointer = pointer->next;
        Customer::head->c->setLessee(nullptr);
        delete Customer::head;
        Customer::head = pointer;
    }
    Customer::head=nullptr;

    delete[] this->name;
    delete[] this->surname;
    
}



const char* Customer::getName() const{
    return this->name;
}

const char* Customer::getSurname() const{
    return this->surname;
}



bool Customer::rent_car(CarRentalCompany &company, Car &car){
    bool result = company.give_car(car, *this);
    if(result){
        Customer::Cars *newCar = new Customer::Cars;
        newCar->c = &car;
        newCar->next = Customer::head;
        Customer::head = newCar;
        car.setLessee(this);
        return true;
    }
    return false;
}

void Customer::return_car(Car &car){
    if(!Customer::head) return;
    Customer::Cars *pointer = Customer::head;
    Customer::Cars *previous = nullptr;

    while(pointer!=nullptr){
        if(pointer->c->getId()==car.getId()){
            if(previous!=nullptr){
                previous->next = pointer->next;
            }else{
                Customer::head = pointer->next;
            }
            delete pointer;
            car.setLessee(nullptr);
            break;
        }
    previous = pointer;
    pointer = pointer->next;
    }

}

void Customer::print_rented_cars(){
    Customer::Cars *pointer = Customer::head;

    cout<<"List of rented cars of "<<this->getName()<<" "<<this->getSurname()<<": "<<endl;
    if(pointer == nullptr){
        cout <<"This person has no rented cars"<< endl;
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