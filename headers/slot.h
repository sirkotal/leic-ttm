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
    Slot(WeekDay day, float start, float end, string type);

    float getStart() const;

    float getEnd() const;

    string classType() const;
        
    private:
        WeekDay day;
        float start;
        float end;
        string type;
};

#endif