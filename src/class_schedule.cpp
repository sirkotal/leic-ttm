#include "../headers/class_schedule.h"

ClassSchedule::ClassSchedule(string ucID, string classID) {
    this->ucID = ucID;
    this->classID = classID;
}

string ClassSchedule::get_UC_ID() const{
    return ucID;
}

string ClassSchedule::get_class_ID() const{
    return classID;
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
    // cout << fcmp << "," << scmp << "|" << endl;
    return fcmp < scmp;

void ClassSchedule::csv_classes_reader(const string& filename) {
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
                    Slot* time = new Slot(weekday, hour, tempf, ctype);
                    // cout << time->getDay();
                    classSchedule.push_back(*time);
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
        sort(ClassSchedule)
    }

/*void ClassSchedule::print() {
    cout << classSchedule.size() << endl;
}*/