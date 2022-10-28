#include "../headers/student.h"

Student::Student(string name, string id, list<UCClass> classes) {
    this->name = name;
    this->id = id;
    this->classes = classes;
}

string Student::getName() const{
    return name;
}

string Student::getID() const {
    return id;
}
    