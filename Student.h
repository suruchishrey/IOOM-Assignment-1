/*
    Enrollment no.: BT18CSE014
    Name: Suruchi Shrey
*/
#ifndef STUDENT_H //prevent multiple inclusions
#define STUDENT_H
#include "Person.h"
#include<string.h>
using namespace std;

class Student:public Person
{
    private:
        const int STUD_ID;
        int numCourses;
        char courses[SIZE][SIZE];            
        int grade[SIZE];
    public:
        //Explicit call to the constructor of Person class,initialization list
        Student(char name_[SIZE],Department dept_,char housenum[SIZE],char streetname[SIZE],char cityname[SIZE]):Person(name_,dept_,housenum,streetname,cityname),STUD_ID(getID()+14)
        {
            //cout<<"Student constructed->";
            numCourses=0;
        }
        int getId();
        int getNumCourses();
        double getAvgGrade();
        void addCourse(char coursename[SIZE]);
        bool addCoursesGrade(char coursename[SIZE],int grade_);
        bool dropCourse(char coursename[SIZE]);
        void printGrade();
        virtual void print();                   //runtime polymorphism,function overriding
};

#endif
