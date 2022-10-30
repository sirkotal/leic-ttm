#ifndef CLASSESCHEDULE_H
#define CLASSESCHEDULE_H

#include <bits/stdc++.h>
#include "slot.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class ClassSchedule {
    public:
        ClassSchedule(string classID);

        string get_UC_ID() const;
        string get_class_ID() const;

        void csv_classes_reader(const string& filename);

        // void print();

    private:
        //string ucID #LEIC003
        string classID; //1LEIC14
        vector<Slot> classSchedule;
};

#endif