#ifndef PERSON_H    //prevent multiple inclusions
#define PERSON_H
#include "Address.h"
#include<string.h>
using namespace std;

struct Department{
    char name[SIZE];
};

class Person{
    private:
        char name[SIZE];
        Address address;
        static int count;           //declaration of static data member within the class
        const int MAX;
        Department dept;
    public:
        //Implicit call to the constructor of address(object of Address class),initialization list
        Person(char name_[SIZE],Department dept_,char housenum[SIZE],char streetname[SIZE],char cityname[SIZE]):address(housenum,streetname,cityname),MAX(6)
        {
            //cout<<"Person constructed->";
            strcpy(name,name_);
            dept=dept_;
            count++;
        }
        char*getName();
        static int getID(){
            return count;
        }
        Department getDepartment();
        void setName(char name[SIZE]);
        void setDept(Department d);
        void changeName(char name[SIZE]);
        void changeAddress(char housenum[SIZE],char streetname[SIZE],char cityname[SIZE]);
        int getMax();
        virtual void print();               //For runtime polymorphism,function overriding
};

#endif
