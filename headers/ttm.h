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
#include "ttm.h"
#include "slot.h"
#include "uc_class.h"

using namespace std;

class TTM {
    public:
    friend class Student;

    // Set sorting function
    bool student_code_comparison(Student first, Student second);
    bool student_uc_number_comparison(Student first, Student second);
    void print_students_with_more_than_n_ucs(int n);
    bool searchStudent(string s_student, string s_uc_code);
    Student getStudent(string s_name, string student_code);
    void studentsInUC(string uc);
    void studentsInClass(string class_ID);

    // Reader functions declarations
    // void csv_classes_reader(const string& filename); -> ClassSchedule has something for this, not required overall
    void csv_classes_per_uc_reader(const string& filename);
    void csv_students_classes_reader(const string& filename);

    // Request management functions declarations

    // void add_request_to_queue(Request request);
    //Request get_request();
    void process();
    bool removeClass(Student* student, UCClass& uc);



    //void vsize();
    private:
        vector<Student> students; // Sorted by student code.
        vector<UCClass> everyClass;
        // vector<ClassSchedule> schedule;
        queue<Request> requests;
};

#endif