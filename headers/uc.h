#ifndef UC_H
#define UC_H

#include <bits/stdc++.h>
#include "classes.h"

using namespace std;

class UC {
    public:
        void csv_classes_per_uc_reader(const string& filename, vector <string>& v_uc_code, vector <string>& v_class_code);

    private:
    string id;
    vector<Classes> classes;
};

#endif