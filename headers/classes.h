#ifndef CLASSES_H
#define CLASSES_H

#include <bits/stdc++.h>

using namespace std;

class Classes {
    public:
        void csv_classes_reader(const string& filename);

    private:
        string id;
        vector<Student> students;
}