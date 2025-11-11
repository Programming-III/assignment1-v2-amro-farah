#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"

using namespace std;

/* Constructors and Destructors */

Person::Person(string name, int id) {
    this->name = name;
    this->id=id;
}

Student::Student(string name, int id, int yearLevel, string major) : Person(name, id) {
    this->yearLevel=yearLevel;
    this->major=major;
}

Instructor::Instructor(string name, int id, int experienceYears, string department) : Person(name, id) {
    this->department=department;
    this->experienceYears=experienceYears;
}

Course::Course(string courseCode, string courseName, int maxStudents) {
    this->courseCode=courseCode;
    this->courseName=courseName;
    this->maxStudents=maxStudents;

    currentStudents=0;
    students=nullptr;
}

Person::~Person() {};
Student::~Student() {};
Instructor::~Instructor() {};

Course::~Course() {
    delete[] students;
}

/* Getters and Setters */

string Person::getName() {
    return name;
}

int Person::getId() {
    return id;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setId(int id) {
    this->id=id;
}

/* Display Methods */

void Person::display() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}

void Student::display() {
    cout << "Student Info: " << endl;
    Person::display();
    cout << "Year level: " << yearLevel << endl;
    cout << "Major: " << major << endl;
}

void Instructor::display() {
    cout << "Instructor Info: " << endl;
    Person::display();
    cout << "Experience Years: " << experienceYears << endl;
    cout << "Department: " << department << endl;
}

/* Course Methods */

void Course::displayCourseInfo() {
    cout << "Course: " << courseCode << " - " << courseName << endl;
    cout << "Max Students: " << maxStudents << endl;
    cout << "Currently Enrolled: " << currentStudents << endl;

    cout << "Currently Enrolled: ";
    for (int i = 0; i < currentStudents; i++)
        cout << students[i].getName() << " (ID: " << students[i].getId() << ")" << " ";
    cout << endl;
}

void Course::addStudent(const Student& s) {
    Student* temp = (Student*)malloc(sizeof(Student)*(currentStudents+1));
    for (int i = 0; i < currentStudents; i++)
        temp[i] = students[i];
    temp[currentStudents] = s;
    currentStudents++;
}

int main() {
    Course* course = new Course("CS101", "Introduction to Programming", 3);

    Student* student = new Student("Omar Nabil", 2202, 2, "Informatics");
    Instructor* instructor = new Instructor("Dr. Lina Khalid", 102, 5, "Computer Science");

    const Student& s = *student;
    course->addStudent(s);

    course->displayCourseInfo();
    instructor->display();
    student->display();

    delete course;
    delete student;
    delete instructor;

    return 0;
}
