#include "car.h"
#include <iostream>
#include <cstring>

using namespace std;

Car::Car(char *name, int id){
    this->name=new char[strlen(name)+1];
    strcpy(this->name, name);
    this->id=id;
    this->owner=nullptr;
    this->lessee=nullptr;
}

Car::~Car(){
    if(this->owner){
        this->owner->del_car(*this);
    }
    if(this->lessee){
        this->lessee->return_car(*this);
    }
    delete[] this->name;
}



char* Car::getName(){
    return this->name;
}

const int Car::getId() const{
    return this->id;
}

const CarRentalCompany* Car::getOwner() const{
    return this->owner;
}

Customer* Car::getLessee(){
    return this->lessee;
}



const char* Car::getNameOwner() const{
    if(this->getOwner() == nullptr){
        return "This car has no owner";
    }else{
        return this->getOwner()->getName();
    }
}

char* Car::getNameLessee(){
    if(this->getLessee() == nullptr){
        return (char*)"This car has no lessee";
    }else{
        return (char*)this->getLessee()->getName();
    }
}

void Car::setOwner(CarRentalCompany *owner){
    this->owner = owner;
}

void Car::setLessee(Customer *lessee){
    this->lessee = lessee;
}

