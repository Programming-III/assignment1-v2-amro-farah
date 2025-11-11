#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;
public:
    Person(string name, int id);
    void display();

    virtual void setName(string name);
    virtual void setId(int id);

    virtual string getName();
    virtual int getId();

    ~Person();
};

#endif
