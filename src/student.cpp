#define classes "../schedule/classes.csv"
#include "../headers/student.h"

Student::Student(string name, string id) {
    this->name = name;
    this->id = id;
}

/*bool Student::operator< (const Student &next) const
{
    return id < next.id;
}*/

string Student::getName() const{
    return name;
}

string Student::getID() const {
    return id;
}

int Student::getNumberClasses() const{ // class = turma
    return allClasses.size();
}

void Student::showAllClasses() const {
    for (auto itr = allClasses.begin(); itr != allClasses.end(); itr++) {
        cout << "|" << itr->get_UC_ID() << " -> " << itr->get_class_ID() << "|" << endl;
        cout << "|------------------|" << endl;
    }
}

void Student::showSchedule() const {
    for (Slot element: schedule) {
        cout << element.getUC() << "-> " << element.getDay() << ": " << element.getStart() << "->" << element.getEnd() << ", " << element.isType() << endl;
        cout << "|-------------------------------|" << endl;
    }
}

void Student::buildClass(UCClass& x) {
    allClasses.push_back(x);
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


bool sorttime(Slot firsts, Slot seconds) {
    float fstart = firsts.getStart();
    float sstart = seconds.getStart();

    return fstart < sstart;
}

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

bool student_uc_number_comparison(Student first, Student second) {
    int x = stoi(first.getID());
    int y = stoi(second.getID());
    return x < y;
}

/*!
 * Sorts a vector of UCClasses by capacity/student count.
 * @param first The first class
 * @param second The second class
 * @return true or false, depending on the capacity of each class
 */
bool cap_sort(UCClass first, UCClass second) {
    return first.get_student_count() < second.get_student_count();
}

void Student::removeClass(UCClass& uc) {
    bool removed = false;
    for (auto itr = allClasses.begin(); itr != allClasses.end(); itr++) {
        if (itr->get_class_ID() == uc.get_class_ID() && itr->get_UC_ID() == uc.get_UC_ID()) {
            itr = allClasses.erase(itr);
            removed = true;
        }
    }
    if (removed == true) {
        cout << "Class successfully removed" << endl;
        return;
    }
    else {
        cout << "Unable to remove class" << endl;
        return;
    }

    // uc.count_decrement();    same as with addClass
}

void Student::addClass(UCClass& uc, vector<UCClass>& every_class) {
    if (uc.get_student_count() >= 20) { // tem de se dar fix a esta função (student_counter) para ir aos vectors, não ao ficheiro então
        // throw uc.student_counter() maybe?
        cout << "The student can't be added to this class" << endl;
        return;
    }

    for (UCClass element: allClasses) {
        if (element.get_UC_ID() == uc.get_UC_ID()) {
            cout << "Student already enrolled in this course" << endl;
            return;
        }
    }

    vector<UCClass> courseClasses;
    for (UCClass element: every_class) {
        if (element.get_UC_ID() == uc.get_UC_ID()) {
            element.student_counter(classes); // classes is a placeholder
            courseClasses.push_back(element);
        }
    }

    sort(courseClasses.begin(), courseClasses.end(), cap_sort);

    int first_balance = courseClasses.back().get_student_count() - courseClasses.front().get_student_count();

    UCClass test(uc.get_UC_ID(), uc.get_class_ID());
    test.student_counter(classes);
    test.count_increment();
    for (auto itr = courseClasses.begin(); itr != courseClasses.end(); itr++) {
        if (itr->get_class_ID() == uc.get_class_ID() && itr->get_UC_ID() == uc.get_UC_ID()) {
            itr = courseClasses.erase(itr);
        }
    }
    courseClasses.push_back(test);
    sort(courseClasses.begin(), courseClasses.end(), cap_sort);
    int second_balance = courseClasses.back().get_student_count() - courseClasses.front().get_student_count();

    if (second_balance < 4 || second_balance <= first_balance) {
        allClasses.push_back(uc);
        uc.count_increment();
        cout << "Student successfully added to " << uc.get_class_ID() << "for " << uc.get_UC_ID() << endl;
    }
    else {
        cout << "The classes would be unbalanced" << endl;
        return;
    }

    /* uc.count_increment();   depending on if alterations are made to the vector/file right after the function ends
    or only after exit() is called on the program, we might need this statement to control UCClass student count;
    might need to change capacity, but it will require vector counting function for students with a specific UCClass*/

}

void Student::changeClass(UCClass& current, UCClass& target) {
    if (target.get_student_count() >= 20) {
        cout << "The student can't be added to this class" << endl;
        return;
    }

    if (current.get_UC_ID() != target.get_UC_ID()) {
        cout << "Both classes need to belong to the same UC" << endl;
        return;
    }
}

/*
void Student::print() {
    for (Slot element: schedule) {
        cout << element.getUC() << "|" << element.getStart() << "|" << element.isType() << " ";
    }
}*/