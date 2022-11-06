#ifndef STUDENT_H
#define STUDENT_H
class Student;
#include <bits/stdc++.h>
#include "class_schedule.h"
#include "slot.h"
#include "uc_class.h"
#include "ttm.h"
#include "request.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
    public:
    Student(string name, string id);

    /*!
     * Retrieves a student's name.
     * @return The student's name.
     */
    string getName() const;

    /*!
     * Retrieves a student's identification number.
     * @return The student's identification number.
     */
    string getID() const;

    /*!
     * Checks in how many classes a student is enrolled.
     * @return The number of classes the student is attending.
     */
    int getNumberClasses() const;

    /*!
     * Shows all the classes a student is enrolled in.
     */
    void showAllClasses();

    /*!
     * Shows a student's schedule.
     */
    void showSchedule() const;

    /*!
     * Checks if a student is enrolled in a specific course (UC).
     * @param uc The UC we want to check.
     * @return true if the student is enrolled in it; otherwise, it returns false.
     */
    bool inCourse(string uc);

    /*!
     * Checks if a student belongs to a specific class.
     * @param class_ID The class we want to check.
     * @return true if the student belongs to it; otherwise, it returns false.
     */
    bool inClass(string class_ID);

    /*!
     * Checks if a student belongs to a specific year.
     * @param year The year we want to check.
     * @return true if the student belongs to it; otherwise, it returns false.
     */
    bool inYear(char year);

    /*!
     * Retrieves all the classes a student belongs to.
     * @param filename The file in which students and their respective classes are stored.
     */
    void getAllClasses(const string& filename);

    /*!
     * Retrieves a student's schedule.
     */
    void getSchedule();

    bool isScheduleEmpty() const;

    // void print();

    // bool Student::operator< (const Student &next) const;

    friend class TTM;

private:
    string name;
    string id;
    list<UCClass> allClasses;
    vector<Slot> schedule;

    void buildClass(UCClass& x);
};

#endif