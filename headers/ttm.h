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
    void add_request_to_queue(Request request);
    queue<Request> get_request();
    
    private:
        set<Student> students;
        vector<ClassSchedule> schedule;
        queue<Request> requests;
};

#endif