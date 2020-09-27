#ifndef FACUTLY_H  //prevent multiple inclusions
#define FACULTY_H

using namespace std;

struct Designation
{
    /* data */
    char nameOfPost[SIZE];
};

class Faculty:public Person
{
    private:
        const int F_ID;
        Designation desig;
        int numCourses;
        char*courses[SIZE];
    public:
        //Explicit call to the constructor of Person class,initialization list
        Faculty(char*name_, Department dept_,Designation des, char*housenum, char*streetname,char*cityname):Person(name_,dept_,housenum,streetname,cityname),F_ID(getID()+4)
        {
            desig=des;
            numCourses=0;
        }
        int getId();
        bool getCourses(char*course);
        bool addCourses(char*course);
        bool removeCourses(char*course);
        virtual void print();
};

#endif