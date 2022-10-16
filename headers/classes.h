#ifndef CLASSES_H
#define CLASSES_H

#include <bits/stdc++.h>
#include "student.h"

using namespace std;

class Classes {
    public:
        void csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type);

    private:
        string id;
        vector<Student> students;
};

#endif