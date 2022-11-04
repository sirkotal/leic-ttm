#ifndef CLASSESCHEDULE_H
#define CLASSESCHEDULE_H

class ClassSchedule;

#include <bits/stdc++.h>
#include "slot.h"
#include "ttm.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class ClassSchedule {
    public:
        ClassSchedule(string classID);

        // string get_UC_ID() const;
        /*!
         * Retrieves the class to whom the schedule belongs.
         * @return The class ID.
         */
        string get_class_ID() const;

        /*!
         * Builds the full schedule of a specific class through all UCs.
         * @param filename The file from where the class's schedule is retrieved.
         */
        void getFullSchedule(const string& filename); //csv_classes_reader

        /*!
         * Adds a specific class (from a specific UC class) to a schedule.
         * @param ucID The class's UC identifier.
         * @param vct The schedule.
         */
        void getClass(string ucID, vector<Slot>& vct);

        // void print();

    private:
        //string ucID #LEIC003
        string classID; //1LEIC14
        vector<Slot> classSchedule;
};

#endif