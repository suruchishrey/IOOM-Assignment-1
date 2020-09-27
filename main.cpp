#include "Person.cpp"
#include "Address.cpp"
#include "Student.cpp"
#include "Faculty.cpp"

#define DSIZE 3                     //3 designations and 3 departments(e.g.)

void print_all(Person *p_ptr)
{
    p_ptr->print();
}

int main()
{
    const Department departments[DSIZE]={{"CSE"},{"ECE"},{"CME"}};
    const Designation designations[DSIZE]={{"HOD"},{"Professor"},{"Assistant Professor"}};

    Faculty f("Suruchi",departments[0],designations[0],"LIG 10","Housing Board Colony","Kanker");
    f.addCourses("CPL");
    Student s("Lily",departments[0],"10","albelapara","Kanker");
    s.addCourse("IOOM");
    Person p("Moti",departments[0],"5","Thelkabod","Kanker");
    
    return 0;
}