#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
    public:
    Student(string name, string id, list<UCClass> classes);

    string getName() const;
    string getID() const;
    
private:
    string name;
    string id;
    list<UCClass> allClasses;
};

#endif