#ifndef REQUEST_H
#define REQUEST_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Request {
    public:
        // static void csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type);

        Request(string type, string date);

        bool isDone() const;
        string getType() const;
        void setDone();


    private:
        string type;
        string date;
        bool completed;
};

#endif