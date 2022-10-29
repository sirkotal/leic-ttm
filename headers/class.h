#ifndef CLASSESCHEDULE_H
#define CLASSESCHEDULE_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class ClassSchedule {
    public:
        ClassSchedule(string ucID, string classID, list<Slot> classSchedule);

        string get_UC_ID() const;
        string get_class_ID() const;

    private:
        string ucID;
        string classID;
        list<Slot> classSchedule;
};

#endif