#ifndef REQUEST_H
#define REQUEST_H
class Request;
#include <bits/stdc++.h>
#include "student.h"
#include "uc_class.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Request {
    public:
        // static void csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type);

        Request(int type, string student_code, string class_code);

        /*!
         * Checks if a specific request has been completed
         * @return true if request has been completed, false otherwise.
         */
        bool isDone() const;

        /*!
         * Retrieves the type of operation the request demands.
         * @return An int representing the operation's type.
         */
        int getType() const;

        /*!
         * Sets the request status to completed (true).
         */
        void setDone();


    private:
        int type;
        string student_code;
        string class_code;
        bool done = false;
};

#endif