#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
#include "uc_class.h"
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
    void csv_students_classes_reader(const string& filename);
    void sort_students_in_class_alphabetically(string class_code_input);
    
private:
    string name;
    string id;
    list<UCClass> allClasses;
};

#endif