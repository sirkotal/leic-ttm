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
    Slot(string uc, string day, float start, float end, string type);

    /*!
     * Retrieves the UC associated to the Slot.
     * @return The UC's code.
     */
    string getUC() const;

    /*!
     * Retrieves the day in which the class occurs.
     * @return The day of the week.
     */
    string getDay() const;

    /*!
     * Retrieves the starting time of a class.
     * @return Time at which the class begins.
     */
    float getStart() const;

    /*!
     * Retrieves the time at which a class ends.
     * @return Time at which the class ends.
     */
    float getEnd() const;

    /*!
     * Checks what is the type of the class.
     * @return The type of the class (T, TP or PL).
     */
    string isType() const;
        
    private:
        string uc;
        string day;
        float start;
        float end;
        string type;
};

#endif