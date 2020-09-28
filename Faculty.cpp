#include<iostream>
#include "Faculty.h"

int Faculty::getId()
{
    return F_ID;
}

bool Faculty::getCourses(char course[SIZE])
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

bool Faculty::addCourses(char course[SIZE])
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
bool Faculty::removeCourses(char course[SIZE])
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

void Faculty::print()                       //function overriding
{
    Person::print();
    cout<<"\nFaculty ID= "<<getId();
    cout<<"\nNo of courses taken= "<<numCourses;
    if(numCourses>0)
    {
        cout<<"\nCourses are:\n";
        for(int i=0;i<numCourses;++i)
        {
            cout<<courses[i]<<"\n";
        }
    }
}
