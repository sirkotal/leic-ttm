#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>

using namespace std;

class Student {
    public:
        void csv_students_classes_reader(const string& filename, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code);

    private:
    string name;
    string id;
};

#endif