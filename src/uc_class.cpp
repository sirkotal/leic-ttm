#include "../headers/uc_class.h"

UCClass::UCClass(string ucID, string classID) {
    this->ucID = ucID;
    this->classID = classID;
}

void UCClass::student_counter(const string& filename) { //altered to store int
    // at member field "cap" to allow alteration of value without the need to read the vector/file again
    // File variables.
    string student_code, student_name, uc_code, class_code;
    int student_counter = 0;

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

            if (uc_code == this->ucID && class_code == this->classID)
            {
                student_counter++;
            }
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }

    cap = student_counter;
}

/*vector<string> UCClass::sort_students_in_class_alphabetically(const string& filename)
{
    vector<string> v_students_in_class;
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

            if (class_code == this->classID)
            {
                v_students_in_class.push_back(student_name);
            }
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }

    sort(v_students_in_class.begin(), v_students_in_class.end());  // not sorting by name??

    return v_students_in_class;
}*/

string UCClass::get_UC_ID() const{
    return ucID;
}
    
string UCClass::get_class_ID() const{
    return classID;
}

int UCClass::get_student_count() const {
    return cap;
}

void UCClass::count_increment() {
    cap += 1;
}

void UCClass::count_decrement() {
    cap -= 1;
}