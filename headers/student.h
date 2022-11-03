#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
#include "uc_class.h"
#include "slot.h"
#include "class_schedule.h"
#include "ttm.h"
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
    void showAllClasses() const;
    void showSchedule() const;

    // void getAllClasses(const string& filename);  #generates allClasses, csv_students_classes_reader
    void getSchedule();

    void removeClass(UCClass& uc);
    addClass(UCClass& uc, vector<UCClass>& every_class);
    void changeClass(UCClass& current, UCClass& target);
    // void print();

    bool operator< (const Student &next) const;

    friend class TTM;

private:
    string name;
    string id;
    list<UCClass> allClasses;
    vector<Slot> schedule;

    void buildClass(UCClass& x);
};

#endif