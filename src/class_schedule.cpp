#include "../headers/class_schedule.h"

ClassSchedule::ClassSchedule(string classID) {
    this->classID = classID;
}

string ClassSchedule::get_class_ID() const{
    return classID;
}

/*!
 * Sorts two Slots (classes) by start time.
 * @param firsts The first Slot to compare.
 * @param seconds The second Slot to compare.
 * @return true if the first Slot starts before the second; otherwise, it returns false.
 */
bool sort_time(Slot firsts, Slot seconds) {
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
    return fcmp < scmp;
}

void ClassSchedule::getFullSchedule(const string& filename) {
        string class_code, uc_code, weekday, ctype;
        string start_hour, duration;

        ifstream thefile(filename);

        if (thefile.is_open())
        {
            string line;
            getline(thefile, line);

            while (!thefile.eof()) {
                getline(thefile, class_code, ',');

                getline(thefile, uc_code, ',');

                getline(thefile, weekday, ',');
                getline(thefile, start_hour, ',');
                getline(thefile, duration, ',');
                getline(thefile, ctype, '\n');

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

            thefile.close();
        }
        else {
            cout << "Error: The program was unable to open the file.";
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