#ifndef PERSON_H    //prevent multiple inclusions
#define PERSON_H
#include "Address.h"
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
        Person(char*name_,Department dept_,char*housenum,char*streetname,char*cityname):address(housenum,streetname,cityname),MAX(6)
        {
            strcpy(this->name,name_);
            this->dept=dept_;
            count++;
        }
        char*getName();
        static int getID(){
            return count;
        }
        Department getDepartment();
        void setName(char*name);
        void setDept(Department d);
        void changeName(char*name);
        void changeAddress(char*housenum,char*streetname,char*cityname);
        int getMax();
        virtual void print();
};

#endif