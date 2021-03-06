/*
    Enrollment no.: BT18CSE014
    Name: Suruchi Shrey
*/

#include <iostream>
#include<string.h>
#include "Address.h"

Address::Address(){} 

Address::Address(char housenum[SIZE],char streetname[SIZE],char cityname[SIZE])
{
    strcpy(house_num,housenum);
    strcpy(street_name,streetname);
    strcpy(city_name,cityname);
}

//definitions of member functions
char* Address::getHouse_num()
{
    return house_num;
}
char* Address::getStreet_name()
{
    return street_name;
}
char* Address::getCity_name()
{
    return city_name;
}
void Address::setAddress(char housenum[SIZE],char streetname[SIZE],char cityname[SIZE])
{
    strcpy(house_num,housenum);
    strcpy(street_name,streetname);
    strcpy(city_name,cityname);
}
void Address::setHouse_num(char housenum[SIZE])
{
    strcpy(house_num,housenum);
}
void Address::setStreet_name(char streetname[SIZE])
{
    strcpy(street_name,streetname);
}
void Address::setCity_name(char cityname[SIZE])
{
    strcpy(city_name,cityname);
}
