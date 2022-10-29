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

    private:
        string ucID;  // LEIC003
        string classID; //1LEIC14
};

#endif