#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#using namespace std;
//#write student class here

class Student : public Person {
private:
    int yearLevel;
    string major;
public:
    Student(string name, int id, int yearLevel, string major);
    void display();

    ~Student();
};

#endif
