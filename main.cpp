#include "Person.cpp"
#include "Address.cpp"
#include "Student.cpp"
#include "Faculty.cpp"
#include<stdio.h>
using namespace std;
#define DSIZE 3                     //3 designations and 3 departments(e.g.)

void print_all(Person *p_ptr)
{
    p_ptr->print();
}

int main()
{
    const Department departments[DSIZE]={{"CSE"},{"ECE"},{"CME"}};                  //sample data assuming only 3 depts are there
    const Designation designations[DSIZE]={{"HOD"},{"Professor"},{"Assistant Professor"}};
    char coursesAvailable[DSIZE][SIZE]={"IOOM","OS","NFT"};
    char name[SIZE],hnum[SIZE],street[SIZE],city[SIZE],courseEntered[SIZE];
    int ch,ch2,ch3;
    Department d;
    Designation des;
    char choice;
    //---------------------------Part for user interface---------------------------
    do
    {
        cout<<"Enter \n1.Student's data \n2.Faculty's data\n:";
        cin>>ch2;
        if(ch2==2){
            cout<<"Faculty:";
            cout<<"\nName:";
            cin.getline(name,SIZE);
            cout<<"\nAddress:\nhouse no:";
            cin.getline(hnum,SIZE);
            cout<<"\nStreet name:";
            cin.getline(street,SIZE);
            cout<<"\nCity name:";
            cin.getline(city,SIZE);
            cout<<"\nEnter department code:\n0 for CSE\n1 for ECE\n2 for CME";
            cin>>ch;
            d=departments[ch];                          
            cout<<"\nEnter designation code:\n0 for HOD\n1 for Professor\n2 for Assistant Professor";
            cin>>ch;
            des=designations[ch];
            Faculty newfaculty(name,d,des,hnum,street,city);
            cout<<"\nEnter 1 course(its code) to add:";
            cout<<"\n0 for IOOM\n1 for OS\n2 for NFT\n";
            cin>>ch;
            newfaculty.addCourses(coursesAvailable[ch]);
            cout<<"\nEntered credentials are as follows:";
            newfaculty.print();
        }
        else{
            cout<<"Student:";
            cout<<"\nName:";
            cin.getline(name,SIZE);
            cout<<"\nAddress:\nhouse no:";
            cin.getline(hnum,SIZE);
            cout<<"\nStreet name:";
            cin.getline(street,SIZE);
            cout<<"\nCity name:";
            cin.getline(city,SIZE);
            cout<<"\nEnter department code:\n0 for CSE\n1 for ECE\n2 for CME";
            cin>>ch;
            d=departments[ch];  
            Student newstudent(name,d,hnum,street,city);
            cout<<"\nEnter 1 course(its code) to add:";
            cout<<"\n0 for IOOM\n1 for OS\n2 for NFT\n";
            cin>>ch;
            newstudent.addCourse(coursesAvailable[ch]);
            cout<<"\nEnter its grade(1-100):\n";
            cin>>ch3;
            newstudent.addCoursesGrade(coursesAvailable[ch],ch3);
            cout<<"\nEntered credentials are as follows:";
            newstudent.print();
        }
            cout<<"\nWant to enter more?(y for yes , n for no):";
            cin>>choice;
    } while (choice=='y');
    //-----------------------------user interface ends here--------------------------

    //--------------------Runtime Polymorphism---------------------------------------
    cout<<"\n\nNow dummy entries showcasing run time polymorphism:\n";
    Student s("Student",departments[0],"student house","student street","student city");
    s.addCourse("Demo");
    Faculty f("Faculty",departments[0],designations[0],"faculty house","faculty Colony","faculty city");
    f.addCourses("CPL");
    Person p("Person",departments[0],"person house","person Street","person city");
    Person*ptrs[3];
    ptrs[0]=&p;
    ptrs[1]=&f;
    ptrs[2]=&s;
    for(int i=0;i<3;++i)
    {
        cout<<"\n\nShowing data of ptr "<<i+1;
        print_all(ptrs[i]);
    }
    return 0;
}
