#ifndef TTM_H
#define TTM_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "request.h"
#include "student.h"
#include "class_schedule.h"
#include "slot.h"
#include "uc_class.h"

using namespace std;

class TTM {
    public:
    friend class Student;

    //UCClass getClass(string ucID, string classID);

    /*!
     * Returns a specific student.
     * @param s_name The name of the student.
     * @param student_code The student's identification number.
     * @return A pointer to the target student.
     */
    Student* getStudent(string s_name, string student_code);

    /*!
     * Shows all the students enrolled in a specific UC.
     * @param uc The UC we want to analyse.
     * @param type Sort by number or by name of the student.
     * @param flag Sort in ascending or descending order.
     */
    void studentsInUC(string uc, string type, char flag);

    /*!
     * Shows all the students belonging to a specific class.
     * @param class_ID The class we want to analyse.
     * @param type Sort by number or by name of the student.
     * @param flag Sort in ascending or descending order.
     */
    void studentsInClass(string class_ID, string type, char flag);

    /*!
     * Shows all the students enrolled in a specific year.
     * @param year The year we want to analyse.
     * @param type Sort by number or by name of the student.
     * @param flag Sort in ascending or descending order.
     */
    void studentsInYear(char year, string type, char flag);

    /*!
     * Shows the students enrolled in more than n UC's.
     * @param n The number of UC's.
     * @param type Sort by number or by name of the student.
     * @param flag Sort in ascending or descending order.
     */
    void more_than_n_ucs(int n, string type, char flag);

    // Reader functions declarations
    /*!
     * Builds a vector with all classes.
     * @param filename The file we retrieve the data from.
     */
    void buildUCClasses(const string& filename);

    /*!
     * Builds a vector with all students.
     * @param filename The file we retrieve the data from.
     */
    void buildStudents(const string& filename);

    // Request management functions declarations
    /*!
     * Opens the Main Menu and deals with user input.
     */
    void menu();

    /*!
     * Opens the Listings Menu and deals with user input.
     */
    void listings();

    /*!
     * Shows the user the Main Menu and asks for his input.
     */
    void mainMenu();

    /*!
     * Shows the user the Listings Menu and asks for his input.
     */
    void listingsMenu();

    /*!
     * Processes all the requests made by the user to alter students' classes.
     */
    void process();

    /*!
     * Saves the changes made to the students' classes to a file.
     */
    void saveout();

    /*!
     * Saves the requests that couldn't be fulfilled by the program.
     * @param filename The file where the data will be stored.
     */
    void logout(const string& filename);

    /*!
     * Removes a student from a specific class.
     * @param student The student to be removed.
     * @param uc The class from which we want to remove the student.
     */
    void removeClass(Student& student, UCClass& uc);

    /*!
     * Adds a student to a specific class.
     * @param student The student to be removed.
     * @param uc The class from which we want to remove the student.
     */
    void addClass(Student& student, UCClass& uc);
    void changeClass(Student& student, UCClass& current, UCClass& target);

    private:
        vector<Student*> students;
        vector<UCClass> everyClass;
        queue<Request> requests;
        set<Request> log;

        /*!
         * Checks if the classes in a UC are unbalanced.
         * @param course The UC the classes belong to.
         * @param classID The class being modified.
         * @param flag true if we are removing a student; false if we are adding a student.
         * @return true if the classes are unbalanced; otherwise, returns false.
         */
        bool unbalanced(string course, string classID, bool flag); // flag true for removal, false for add only

        /*!
         * Checks if a student's schedule has overlapping classes.
         * @param student The student we are analysing.
         * @param course The UC the class belongs to.
         * @param classID The class we want to add.
         * @param flag true if we are also removing a class from the schedule; false otherwise.
         * @return true if there are overlapping classes; otherwise, it returns false.
         */
        bool overlap(Student& student, string course, string classID, bool flag); // flag true for removal, false for add only
};

#endif