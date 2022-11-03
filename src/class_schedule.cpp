#include "../headers/class_schedule.h"

ClassSchedule::ClassSchedule(string classID) {
    this->classID = classID;
}

/*string ClassSchedule::get_UC_ID() const{
    return ucID;
}*/

string ClassSchedule::get_class_ID() const{
    return classID;
}

bool sort_time(Slot firsts, Slot seconds) {
    float fstart = firsts.getStart();
    float sstart = seconds.getStart();

    return fstart < sstart;
}

bool sort_day(Slot firsts, Slot seconds) {
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
        return sort_time(firsts, seconds);
    }
    // cout << fcmp << "," << scmp << "|" << endl;
    return fcmp < scmp;
}

void ClassSchedule::getFullSchedule(const string& filename) { //csv_classes_reader
        // File variables.
        string class_code, uc_code, weekday, ctype;
        string start_hour, duration;


        // Filename
        ifstream coeff(filename); // Opens the file.

        if (coeff.is_open()) // Checks if the file is open.
        {
            // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
            string line;
            getline(coeff, line);

            // While the end of the file is not reached.
            while (!coeff.eof()) {
                //{class_code, uc_code, weekday, start_hour, duration, type}
                getline(coeff, class_code, ',');

                getline(coeff, uc_code, ',');

                getline(coeff, weekday, ',');
                getline(coeff, start_hour, ',');
                getline(coeff, duration, ',');
                getline(coeff, ctype, '\n');

                float hour = stof(start_hour);
                float temp = stof(duration);
                float tempf = hour + temp;


                if (class_code == this->classID) {
                    Slot time(uc_code, weekday, hour, tempf, ctype); // try with pointer/new if it fails
                    // cout << time->getDay();
                    classSchedule.push_back(time);
                }
                else {
                    continue;
                }
            }

            coeff.close(); // Closing the file.
        } else {
            cout
                    << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
        }
        sort(classSchedule.begin(), classSchedule.end(), sort_day);
    }

/*void ClassSchedule::print() {
    cout << classSchedule.size() << endl;
}*/

void ClassSchedule::getClass(string ucID, vector<Slot>& vct) {
    for (Slot element: classSchedule) {
        if (ucID == element.getUC()) {
            vct.push_back(element);
        }
    }
}