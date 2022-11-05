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

    // Set sorting function
    bool student_code_comparison(Student first, Student second);
    bool student_uc_number_comparison(Student first, Student second);

    /*!
     * Shows the students that are enrolled in more than a specific number of courses (UCs).
     * @param n The number of UCs.
     */
    void print_students_with_more_than_n_ucs(int n);
    bool searchStudent(string s_student, string s_uc_code);

    /*!
     * Returns a specific student.
     * @param s_name The name of the student.
     * @param student_code The student's identification number.
     * @return A pointer to the target student.
     */
    Student* getStudent(string s_name, string student_code);
    UCClass getClass(string ucID, string classID);
    void studentsInUC(string uc, string type, char flag);
    void studentsInClass(string class_ID, string type, char flag);
    void studentsInYear(char year, string type, char flag);

    // Reader functions declarations
    // void csv_classes_reader(const string& filename); -> ClassSchedule has something for this, not required overall
    void csv_classes_per_uc_reader(const string& filename);
    void buildStudents(const string& filename);

    // Request management functions declarations
    void mainMenu();
    void listingsMenu();
    void process();
    void removeClass(Student& student, UCClass& uc);
    void addClass(Student& student, UCClass& uc);
    void changeClass(Student& student, UCClass& current, UCClass& target);



    void vsize();
    private:
        vector<Student*> students; // Sorted by student code.
        vector<UCClass> everyClass;
        // vector<ClassSchedule> schedule;
        queue<Request> requests;
        set<Request> log;
        bool unbalanced(string course, string classID, bool flag); // flag true for removal, false for add only
        bool overlap(Student& student, string course, string classID, bool flag); // flag true for removal, false for add only
};

#endif