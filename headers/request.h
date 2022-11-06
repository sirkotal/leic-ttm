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
        Request(int type, string student_name, string student_code, string UC_code, string class_code);

        Request(int type, string student_name, string student_code, string UC_code, string class_code, string target_class);

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

        /*!
         * Compares the name associated to each request.
         * @param next The second request to be compared.
         * @return true if the first request's student name is smaller; otherwise, it returns false.
         */
        bool operator< (const Request &next) const;

        friend class TTM;


    private:
        int type;
        string student_name;
        string student_code;
        string UC_code;
        string class_code;
        string target_UC;
        string target_class;
        bool done = false;
};

#endif