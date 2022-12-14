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

void Student::showAllClasses() {
    allClasses.sort();
    for (auto itr = allClasses.begin(); itr != allClasses.end(); itr++) {
        cout << "|" << itr->get_UC_ID() << " -> " << itr->get_class_ID() << "|" << endl;
        cout << "|-------------------|" << endl;
    }
}

/*!
 * Converts a float representing time into standard time format.
 * @param time The time represented as a float.
 * @return A string representing time in the standard time format.
 */
string toTime(float time) {
    int totalseconds = time * 3600.0;
    int hours = totalseconds/3600;
    int minutes = (totalseconds/60) % 60;
    string first = to_string(hours);
    string second = to_string(minutes);
    if (second == "0") {
        second = second + "0";
    }
    string final = first + ":" + second;

    return final;

}
void Student::showSchedule() const {
    cout << "|-------------------------------------|" << endl;
    for (Slot element: schedule) {
        cout << " " << element.getUC() << "-> " << element.getDay() << ": " << toTime(element.getStart()) << "-" << toTime(element.getEnd()) << ", " << element.isType() << endl;
        cout << "|-------------------------------------|" << endl;
    }
}

/*void Student::buildClass(UCClass& x) {
    allClasses.push_back(x);
}*/

bool Student::inCourse(string uc) {
    for (UCClass element : allClasses) {
        if (element.get_UC_ID() == uc) {
            return true;
        }
    }
    return false;
}

bool Student::inClass(string class_ID) {
    for (UCClass element : allClasses) {
        if (element.get_class_ID() == class_ID) {
            return true;
        }
    }
    return false;
}

bool Student::inYear(char year) {
    for (UCClass element : allClasses) {
        if (element.get_class_ID()[0] == year) {
            return true;
        }
    }
    return false;
}

void Student::getAllClasses(const string& filename) {
    string student_code, student_name, uc_code, class_code;

    ifstream thefile(filename);

    if (thefile.is_open()) {
        string line;
        getline(thefile, line);

        // While the end of the file is not reached.
        while (!thefile.eof()) {
            getline(thefile, student_code, ',');

            getline(thefile, student_name, ',');

            getline(thefile, uc_code, ',');

            getline(thefile, class_code, '\n');

            if (student_code == this->id) {
                UCClass insc(uc_code, class_code);
                allClasses.push_back(insc);
            }
            else {
                continue;
            }
        }

        thefile.close(); // Closing the file.
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}

/*!
 * Sorts two Slots (classes) by start time.
 * @param firsts The first Slot to compare.
 * @param seconds The second Slot to compare.
 * @return true if the first Slot starts before the second; otherwise, it returns false.
 */
bool sorttime(Slot firsts, Slot seconds) {
    float fstart = firsts.getStart();
    float sstart = seconds.getStart();

    return fstart < sstart;
}

/*!
 * Sorts two Slots (classes) by day of the week.
 * @param firsts The first Slot to compare.
 * @param seconds The second Slot to compare.
 * @return true if the first Slot occurs before the second; otherwise, it returns false.
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

bool Student::isScheduleEmpty() const {
    if (schedule.size() == 0) {
        return true;
    }
    return false;
}