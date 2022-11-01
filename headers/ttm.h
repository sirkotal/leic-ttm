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

using namespace std;

class TTM {
    public:
    // Set sorting function
    bool student_code_comparison(Student first, Student second);
    bool student_uc_number_comparison(Student first, Student second);

    // Reader functions declarations
    void csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type);
    void csv_classes_per_uc_reader(const string& filename, vector <string>& v_uc_code, vector <string>& v_class_code);
    void csv_students_classes_reader(const string& filename, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code);

    // Request management functions declarations
    void add_request_to_queue(Request request);
    queue<Request> get_request();
    
    private:
        set<Student> students;
        vector<ClassSchedule> schedule;
        queue<Request> requests;
};

#endif