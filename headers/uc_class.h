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

    /*!
     * Retrieves a class's associated UC.
     * @return The UC's identifier.
     */
    string get_UC_ID() const;

    /*!
     * Retrieves a class's own identifier.
     * @return The class's identifier.
     */
    string get_class_ID() const;

    /*!
     * Gets the number of students in a specific class.
     * @return The number of students in the class.
     */
    int get_student_count() const;

    /*!
     * Increases a class's student count by 1.
     */
    void count_increment();

    /*!
     * Decreases a class's student count by 1.
     */
    void count_decrement();

    /*!
     * Counts the number of students that are part of a specific class.
     * @param filename The file in which students and their respective classes are stored.
     */
    void student_counter(const string& filename); // maxs out at 20?

    //vector<string> sort_students_in_class_alphabetically(const string& filename);

    private:
        string ucID;  // LEIC003
        string classID; //1LEIC14
        int cap;
};

#endif