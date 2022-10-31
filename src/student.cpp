#include "../headers/student.h"
#include <string>
#include <vector>

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

/*void Student::getSchedule() {
    for (UCClass element : allClasses) {
        ClassSchedule tmp(element.get_class_ID());
        vector<Slot> store = tmp.getClass(element.get_UC_ID());
        schedule.assign(store.begin(), store.begin()+2);
    }
}*/