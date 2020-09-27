/*
    Enrollment no.: BT18CSE014
    Name: Suruchi Shrey
*/
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
        char courses[SIZE][SIZE];
    public:
        //Explicit call to the constructor of Person class,initialization list
        Faculty(char*name_, Department dept_,Designation des, char*housenum, char*streetname,char*cityname):Person(name_,dept_,housenum,streetname,cityname),F_ID(getID()+4)
        {
            //cout<<"Faculty constructed->";
            desig=des;
            numCourses=0;
        }
        int getId();
        bool getCourses(char course[SIZE]);
        bool addCourses(char course[SIZE]);
        bool removeCourses(char course[SIZE]);
        virtual void print();                       //function overriding
};

#endif
