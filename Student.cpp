#include<iostream>
#include<string.h>
#include "Student.h"

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
    if(numCourses!=0)
    {
        avg/=numCourses;
    }
    return avg;
}

//first check if in that particular course the student has enrooled or not,if NOT,then add that course
void Student::addCourse(char coursename[SIZE])
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
bool Student::addCoursesGrade(char coursename[SIZE],int grade_)
{
    addCourse(coursename);
    bool hasEnrolled=false,retval=false;
    for(int i=0;i<numCourses;++i)
        {
            if(strcmp(coursename,courses[i])==0)
            {
                hasEnrolled=true; 
                grade[i]=grade_;
                retval=true;
            }
        }
    
    return retval;
}

/*If that course is present then delete it ,i.e.,shift all the courses in courses array one left and make the last element null*/
bool Student::dropCourse(char coursename[SIZE])
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
    if(numCourses>0)
    {
        cout<<"Grades with courses:\n";
        for(int i=0;i<numCourses;++i)
        {
            cout<<grade[i]<<" "<<courses[i]<<"\n";
        }
    }
    
    cout<<"\nAverage Grade= "<<avg_grade;
}

void Student::print()                           //function overiding
{
    Person::print();
    cout<<"\nStudent ID= "<<getId();
    cout<<"\nNo of courses enrolled= "<<numCourses;
    if(numCourses>0)
    {
        cout<<"\nCourses are:\n";
        for(int i=0;i<numCourses;++i)
        {
            cout<<courses[i]<<"\n";
        }
        printGrade();
    }
}
