#include "employee.h"
#include <iostream>
#include <cstring>

using namespace std;

Employee::Employee(char *name, char *surname){
    this->name=new char[strlen(name)+1];
    strcpy(this->name, name);
    this->surname=new char[strlen(surname)+1];
    strcpy(this->surname, surname);
    this->employer=nullptr;
}

Employee::~Employee(){

    if(this->employer){
        this->employer->removeEmployee(*this);
    }
    delete[] this->name;
    delete[] this->surname;
}



const char* Employee::getName() const{
    return this->name;
}

const char* Employee::getSurname() const{
    return this->surname;
}

const CarRentalCompany* Employee::getEmployer() const{
    return this->employer;
}



const char* Employee::getNameEmployer() const{
    if(this->getEmployer() == nullptr){
        return "This employee has no employer";
    }else{
        return this->getEmployer()->getName();
    }
}

void Employee::setEmployer(CarRentalCompany *crc){
    this->employer = crc;
}

bool Employee::join_company(CarRentalCompany &employer){
    bool result = employer.addEmployee(*this);
    if(result){
        this->employer=&employer;
        return true;
    }
    return false;
}

void Employee::leave_company(){
	this->employer->removeEmployee(*this);
	this->employer = nullptr;
}

