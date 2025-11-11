#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
using namespace std;
//#write Instructor class here

class Instructor : public Person {
private:
    int experienceYears;
    string department;
public:
    Instructor(string name, int id, int experienceYears, string department);
    void display();

    ~Instructor();
};

#endif
