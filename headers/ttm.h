#ifndef TTM_H
#define TTM_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class TTM {
    public:
    void add(Request request);
    
    private:
        set<Student> students;
        vector<ClassSchedule> schedule;
        queue<Request> requests;
};

#endif