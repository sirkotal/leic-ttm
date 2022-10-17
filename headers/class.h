#ifndef CLASSES_H
#define CLASSES_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "student.h"

using namespace std;

class Class {
    public:
        static void csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type);

    private:
        string id;
        vector<Student> students;
};

#endif