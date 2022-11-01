#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
#include "uc_class.h"
#include "slot.h"
#include "class_schedule.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
    public:
    Student(string name, string id);

    string getName() const;
    string getID() const;
    int getNumberClasses() const;

    void getAllClasses(const string& filename); // generates allClasses, csv_students_classes_reader
    void getSchedule();

    Student searchStudent(set<Student>& students, string s_student, string s_uc_code);
    void print_students_with_more_than_n_ucs(set<Student>& students);
    // void print();

    bool operator< (const Student &next) const;
    
private:
    string name;
    string id;
    list<UCClass> allClasses;
    vector<Slot> schedule;
};

#endif