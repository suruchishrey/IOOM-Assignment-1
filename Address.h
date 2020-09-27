#ifndef ADDRESS_H    //prevent multiple inclusions
#define ADDRESS_H
#define SIZE 50                             //size of arrays used
using namespace std;

class Address{
    private:
        char house_num[SIZE];
        char street_name[SIZE];
        char city_name[SIZE];
    public:
        //Constructor overloading
        //default constructor
        Address();
        //parameterized constructor
        Address(char house_num[SIZE],char street_name[SIZE],char city_name[SIZE]); 
        //declarations of member functions
        char* getHouse_num();
        char* getStreet_name();
        char* getCity_name();
        void setAddress(char housenum[SIZE],char streetname[SIZE],char cityname[SIZE]);
        void setHouse_num(char housenum[SIZE]);
        void setStreet_name(char streetname[SIZE]);
        void setCity_name(char cityname[SIZE]);
};

#endif
