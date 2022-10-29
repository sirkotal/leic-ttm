#ifndef SLOT_H
#define SLOT_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Slot {
    public:
    Slot(string day, float start, float end, string type);

    string getDay() const;

    float getStart() const;

    float getEnd() const;

    string type() const;
        
    private:
        string day;
        float start;
        float end;
        string type;
};

#endif