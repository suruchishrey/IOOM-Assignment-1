#include <iostream>
#include<string.h>
#define SIZE 40                             //size of arrays used
using namespace std;

class Address{
    private:
        char house_num[SIZE];
        char street_name[SIZE];
        char city_name[SIZE];
    public:
        //Constructor overloading
        //default constructor
        Address(){}
        //parameterized constructor
        Address(char house_num[SIZE],char street_name[SIZE],
        char city_name[SIZE]); 
        //declarations of member functions
        char* getHouse_num();
        char* getStreet_name();
        char* getCity_name();
        void setAddress(char housenum[SIZE],char streetname[SIZE],char cityname[SIZE]);
        void setHouse_num(char* housenum);
        void setStreet_name(char*streetname);
        void setCity_name(char* cityname);
};

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
void Address::setHouse_num(char*housenum)
{
    strcpy(house_num,housenum);
}
void Address::setStreet_name(char*streetname)
{
    strcpy(street_name,streetname);
}
void Address::setCity_name(char*cityname)
{
    strcpy(city_name,cityname);
}

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
            strcpy(name,name_);
            dept=dept_;
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
        virtual void print();
        int getMax();
};
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
    address.setAddress(housenum,streetname,cityname);
}

void Person::print()
{
    cout<<"\nName of person:"<<name;
    cout<<"\nAddress: "<<address.getHouse_num()<<" "<<address.getStreet_name()<<" "<<address.getCity_name();
    cout<<"\nDepartment: "<<dept.name;
}

int Person::getMax()
{
    return this->MAX;
}

class Student: public Person
{
    private:
        const int STUD_ID;
        int numCourses;
        char*courses[SIZE];
        int grade[SIZE];
    public:
        //Explicit call to the constructor of Person class,initialization list
        Student(char*name_,Department dept_,char*housenum,char*streetname,char*cityname):Person(name_,dept_,housenum,streetname,cityname),STUD_ID((getID()+numCourses)+14)
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
        void print();
};

int Student::getId()
{
    return STUD_ID;
}

int Student::getNumCourses()
{
    return numCourses;
}

double Student::getAvgGrade()               //returns the avg of all the grades available
{
    int i;
    double avg=0.0;
    for(i=0;i<numCourses;++i)
    {
        avg+=grade[i];
    }
    avg/=numCourses;
    return avg;
}

//first check if in that particular course the student has enrooled or not,if NOT,then add that course
void Student::addCourse(char*coursename)
{
    bool hasEnrolled=false;
    if(numCourses<SIZE)                             
    {
        for(int i=0;i<numCourses;++i)
        {
            if(strcmp(coursename,courses[i])==0)
            {
                hasEnrolled=true;
            }
        }
        if(!hasEnrolled)
        {
            strcpy(courses[numCourses++],coursename);
        }
    }
}

//if a student has enrolled in that particular course then add its grade to his data,if not then enroll him and add its grade to his data
bool Student::addCoursesGrade(char*coursename,int grade_)
{
    addCourse(coursename);
    bool hasEnrolled=false,retval=false;
    for(int i=0;i<numCourses;++i)
        {
            if(strcmp(coursename,courses[i])==0)
            {
                hasEnrolled=true; 
                grade[i]=grade_;
            }
        }
    
    return retval;
}

/*If that course is present then delete it ,i.e.,shift all the courses in courses array one left and make the last element null*/
bool Student::dropCourse(char*coursename)
{
    bool retval=false;
    int i;
    for(i=0;i<numCourses;++i)
    {
        if(strcmp(coursename,courses[i])==0)
        {
            while(i<numCourses-1)
            {
                strcpy(courses[i],courses[i+1]);
                i++;
            }
            if(i==numCourses-1)
            {
                strcpy(courses[i],"");
            }
            retval=true;
        }
    }
    return retval;
}

void Student::printGrade()
{
    double avg_grade=getAvgGrade();
    cout<<"\nGrade= "<<avg_grade;
}

void Student::print()
{
    cout<<"\nName of the Student= "<<getName();
    cout<<"\nStudent ID= "<<getId();
    cout<<"\nNo of courses enrolled= "<<numCourses;
}

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
        Faculty(char*name_, Department dept_,Designation des, char*housenum, char*streetname,char*cityname):Person(name_,dept_,housenum,streetname,cityname),F_ID(getID()+numCourses+4)
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

int Faculty::getId()
{
    return F_ID;
}

bool Faculty::getCourses(char*course)
{
    int i;
    bool retval=false;
    for(i=0;i<numCourses;++i)
    {
        if(strcmp(course,courses[i])==0)
        {
            retval=true;                       //if course is present
        }
    }
    return retval;
}

bool Faculty::addCourses(char*course)
{
    bool retval=false;
    if(numCourses<getMax())
    {
        strcpy(courses[numCourses++],course);
        retval=true;
    }
    return retval;
}

/*If that course is present then delete it ,i.e.,shift all the courses in courses array one left and make the last element null*/
bool Faculty::removeCourses(char*course)
{
    bool retval=false;
    int i;
    for(i=0;i<numCourses;++i)
    {
        if(strcmp(course,courses[i])==0)
        {
            while(i<numCourses-1)
            {
                strcpy(courses[i],courses[i+1]);
                i++;
            }
            if(i==numCourses-1)
            {
                strcpy(courses[i],"");
            }
            retval=true;
        }
    }
    return retval;
}

void Faculty::print()
{
    cout<<"\nName of the Faculty= "<<getName();
    cout<<"\nFaculty ID= "<<getId();
    cout<<"\nNo of courses taken= "<<numCourses;
}

int main(void){
    // Your code here!
    Address A;
    cout<<A.getHouse_num();
    return 0;
}