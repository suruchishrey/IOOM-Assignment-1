#include<iostream>
#include<string.h>
#include "Person.h"


int Person::count=0;        //definition of static data member 

char* Person::getName()
{
    return name;
}

Department Person::getDepartment()
{
    return dept;
}

void Person::setName(char*name_)
{
    strcpy(name,name_);
}

void Person::setDept(Department d)
{
    dept=d;
}

void Person::changeName(char*name_)
{
    strcpy(name,name_);
}

void Person::changeAddress(char*housenum,char*streetname,char*cityname)
{
    this->address.setAddress(housenum,streetname,cityname);
}

int Person::getMax()
{
    return this->MAX;
}

void Person::print()
{
    cout<<"\nName of person:"<<name;
    cout<<"\nAddress: "<<address.getHouse_num()<<" "<<address.getStreet_name()<<" "<<address.getCity_name();
    cout<<"\nDepartment: "<<dept.name;
}
