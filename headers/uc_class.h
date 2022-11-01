#ifndef UCCLASS_H
#define UCCLASS_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class UCClass {
    public:
    UCClass(string ucID, string classID);

    string get_UC_ID() const;
    string get_class_ID() const;
    int student_counter(const string& filename, string uc_code_input, string class_code_input); // maxs out at 20?
    vector<string> sort_students_in_class_alphabetically(const string& filename);

    private:
        string ucID;  // LEIC003
        string classID; //1LEIC14
        // int cap;
};

#endif