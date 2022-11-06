#include "../headers/uc_class.h"

UCClass::UCClass(string ucID, string classID) {
    this->ucID = ucID;
    this->classID = classID;
}

void UCClass::student_counter(const string& filename) { //altered to store int
    // at member field "cap" to allow alteration of value without the need to read the vector/file again
    string student_code, student_name, uc_code, class_code;
    int student_counter = 0;

    // Filename
    ifstream thefile(filename);

    if (thefile.is_open()) {
        string line;
        getline(thefile, line);

        while (!thefile.eof()) {
            getline(thefile, student_code, ',');

            getline(thefile, student_name, ',');

            getline(thefile, uc_code, ',');

            getline(thefile, class_code, '\n');

            if (uc_code == this->ucID && class_code == this->classID)
            {
                student_counter++;
            }
        }

        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }

    cap = student_counter;
}

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

bool UCClass::operator<(const UCClass &next) const {
    return ucID < next.ucID;
}