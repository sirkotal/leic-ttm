#include "../headers/uc_class.h"

UCClass::UCClass(string ucID, string classID) {
    this->ucID = ucID;
    this->classID = classID;
}

void students_counter(const string& filename, string uc_code_input, string class_code_input) {
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

            if (uc_code == uc_code_input && class_code == class_code_input)
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
}


string UCClass::get_UC_ID() const{
    return ucID;
}
    
string UCClass::get_class_ID() const{
    return classID;
}