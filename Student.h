#ifndef STUDENT_H //prevent multiple inclusions
#define STUDENT_H
#include "Person.h"

using namespace std;

class Student: public Person
{
    private:
        const int STUD_ID;
        int numCourses;
        char*courses[SIZE];            
        int grade[SIZE];
    public:
        //Explicit call to the constructor of Person class,initialization list
        Student(char*name_,Department dept_,char*housenum,char*streetname,char*cityname):Person(name_,dept_,housenum,streetname,cityname),STUD_ID(getID()+14)
        {
            numCourses=0;
        }
        int getId();
        int getNumCourses();
        double getAvgGrade();
        void addCourse(char*coursename);
        bool addCoursesGrade(char*coursename,int grade_);
        bool dropCourse(char*coursename);
        void printGrade();
        virtual void print();
};

#endif