#include "../headers/student.h"
#include <string>
#include <vector>
#define classes "../schedule/classes.csv"
#include "../headers/ttm.h"

using namespace std;

Student::Student(string name, string id) {
    this->name = name;
    this->id = id;
}

bool Student::operator< (const Student &next) const
{
    return stoi(id) < stoi(next.getID());
}

string Student::getName() const{
    return name;
}

string Student::getID() const {
    return id;
}

int Student::getNumberClasses() const{
    // Number of UCs = Number of classes/2 (?)
    // Each UC has a T and a TP?
    return allClasses.size();
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

Student Student::searchStudent(set<Student>& students, string s_student, string s_uc_code)
{
    return *students.find(Student(s_student, s_uc_code));
}

bool student_uc_number_comparison(Student first, Student second) {
    int x = stoi(first.getID());
    int y = stoi(second.getID());
    return x < y;
}

void print_students_with_more_than_n_ucs(set<Student>& students, int n)
{
    set<Student> students_organized_by_uc_number(students.begin(), students.end());

    set<Student>::iterator itr;

    // Displaying students with more than n ucs
    for (itr = students_organized_by_uc_number.begin();
         itr != students_organized_by_uc_number.end(); itr++)
    {
        Student temp_student = (Student &&) *itr;
        if (temp_student.getNumberClasses() > n)
        cout << temp_student.getName() << " " << temp_student.getName();
    }
}
void Student::removeClass(UCClass uc) {
    bool removed = false;
    for (auto itr = allClasses.begin(); itr != allClasses.end(); itr++) {
        if (itr->get_class_ID() == uc.get_class_ID() && itr->get_UC_ID() == uc.get_UC_ID()) {
            itr = allClasses.erase(itr);
            removed = true;
        }
    }
    if (removed == true) {
        cout << "Class successfully removed" << endl;
    }
    else {
        cout << "Unable to remove class" << endl;
    }
}

void Student::addClass(UCClass uc) {
    int min = INT_MAX;
    int max = 0;
    list<UCClass> tmp = allClasses;
    if (uc.student_counter() >= 20) { // tem de se dar fix a esta função para ir aos vectors, não ao ficheiro então
        // throw uc.student_counter();
        cout << "The student can't be added to this class" << endl;
    }
    for (UCClass element : allClasses) {
        int num_of_students = element.student_counter();
        if (num_of_students > max) {
            max = num_of_students;
        }
        if (num_of_students < min) {
            min = num_of_students;
        }
    }

    for (UCClass element: allClasses) {
        if (element.get_UC_ID() == uc.get_UC_ID() && element.get_class_ID() == uc.get_class_ID()) {
            cout << "Student already enrolled in this class" << endl;
        }
    }

    if (max - min >= 4) {
        cout << "The classes would be unbalanced" << endl;
    }
}

/*
void Student::print() {
    for (Slot element: schedule) {
        cout << element.getUC() << "|" << element.getStart() << "|" << element.isType() << " ";
    }
}*/