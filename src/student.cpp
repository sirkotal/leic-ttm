#include "../headers/student.h"
#include <string>
#include <vector>
#define classes "../schedule/classes.csv"

using namespace std;

Student::Student(string name, string id) {
    this->name = name;
    this->id = id;
}

string Student::getName() const{
    return name;
}

string Student::getID() const {
    return id;
}

/*
void Student::getAllClasses(const string& filename) { // csv_students_classes_reader
    // File variables.
    string student_code, student_name, uc_code, class_code;

    // Filename
    ifstream coeff(filename); // Opens the file.

    if (coeff.is_open()) { // Checks if the file is open.
        // Skip the first line 
        string line;
        getline(coeff, line);

        // While the end of the file is not reached.
        while (!coeff.eof()) {
            getline(coeff, student_code, ',');

            getline(coeff, student_name, ',');

            getline(coeff, uc_code, ',');

            getline(coeff, class_code, '\n');

            if (student_code == this->id) {
                UCClass insc(uc_code, class_code);
                allClasses.push_back(insc);
            }
            else {
                continue;
            }
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}
*/

bool sortday(Slot firsts, Slot seconds) {
    string first = firsts.getDay();
    string second = seconds.getDay();
    unsigned int fcmp;
    unsigned int scmp;
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (unsigned int i = 0; i < days.size(); i++) {
        if (first == days[i]) {
            fcmp = i;
        }
        if (second == days[i]) {
            scmp = i;
        }
    }

    if (fcmp == scmp) {
        return sorttime(firsts, seconds);
    }
    // cout << fcmp << "," << scmp << "|" << endl;
    return fcmp < scmp;
}

void Student::getSchedule() {
    for (auto itr = allClasses.begin(); itr != allClasses.end(); itr++) {
        ClassSchedule tmp(itr->get_class_ID());
        tmp.getFullSchedule(classes);
        tmp.getClass(itr->get_UC_ID(), schedule);
    }
    sort(schedule.begin(), schedule.end(), sortday);
}






/*
void Student::print() {
    for (Slot element: schedule) {
        cout << element.getUC() << "|" << element.getStart() << "|" << element.isType() << " ";
    }
}*/