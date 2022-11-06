#include "../headers/ttm.h"
#define classes "../schedule/students_classes.csv"
#define class_schedule "../schedule/classes.csv"

/*void TTM::vsize() {
    cout << students.size() << endl;
}

bool TTM::searchStudent(string s_student, string s_uc_code)
{
    for (const Student* student: students) {
        if (student->getName() == s_student && student->getID() == s_uc_code) {
            return true;
        }
    }
    return false;
}

UCClass TTM::getClass(string ucID, string classID) {
    for (auto itr = everyClass.begin(); itr != everyClass.end(); itr++) {
        if (itr->get_UC_ID() == ucID && itr->get_class_ID() == classID) {
            return *itr;
        }
    }
}*/

Student* TTM::getStudent(string s_name, string student_code) {
    for (auto itr = students.begin(); itr != students.end(); itr++) {
        if ((*itr)->getName() == s_name && (*itr)->getID() == student_code) {
            return (*itr);
        }
    }
    return nullptr;
}

/*!
 * Performs a Bubble Sort in ascending order, taking into account the student's identification number.
 * @param stvec A vector of students.
 */
void asc_bubbleNum(vector<Student*>& stvec) // ascending bubble sort by number
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getID() > stvec[j + 1]->getID())
                swap(stvec[j], stvec[j + 1]);
}

/*!
 * Performs a Bubble Sort in descending order, taking into account the student's identification number.
 * @param stvec A vector of students.
 */
void down_bubbleNum(vector<Student*>& stvec) // descending bubble sort by number
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getID() < stvec[j + 1]->getID())
                swap(stvec[j], stvec[j + 1]);
}

/*!
 * Performs a Bubble Sort in ascending order, taking into account the student's name.
 * @param stvec A vector of students.
 */
void asc_bubbleName(vector<Student*>& stvec) // ascending bubble sort by name
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getName() > stvec[j + 1]->getName())
                swap(stvec[j], stvec[j + 1]);
}

/*!
 * Performs a Bubble Sort in descending order, taking into account the student's name.
 * @param stvec A vector of students.
 */
void down_bubbleName(vector<Student*>& stvec) // descending bubble sort by name
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getName() < stvec[j + 1]->getName())
                swap(stvec[j], stvec[j + 1]);
}

void TTM::studentsInUC(string uc, string type, char flag) {
    vector<Student*> temp = students;
    if (type == "name") {
        if (flag == '+') {
            asc_bubbleName(temp);
        }
        else if (flag == '-') {
            down_bubbleName(temp);
        }
    }
    else if (type == "num") {
        if (flag == '+') {
            asc_bubbleNum(temp);
        }
        else if (flag == '-') {
            down_bubbleNum(temp);
        }
    }
    for (Student* element : temp) {
        if (element->inCourse(uc)) {
            cout << element->getName() << ", " << element->getID() << endl;
        }
    }
}

void TTM::studentsInClass(string class_ID, string type, char flag) {
    vector<Student*> temp = students;
    if (type == "name") {
        if (flag == '+') {
            asc_bubbleName(temp);
        }
        else if (flag == '-') {
            down_bubbleName(temp);
        }
    }
    else if (type == "num") {
        if (flag == '+') {
            asc_bubbleNum(temp);
        }
        else if (flag == '-') {
            down_bubbleNum(temp);
        }
    }
    for (Student* element : temp) {
        if (element->inClass(class_ID)) {
            cout << element->getName() << ", " << element->getID() << endl;
        }
    }
}

void TTM::studentsInYear(char year, string type, char flag) {
    vector<Student*> temp = students;
    if (type == "name") {
        if (flag == '+') {
            asc_bubbleName(temp);
        }
        else if (flag == '-') {
            down_bubbleName(temp);
        }
    }
    else if (type == "num") {
        if (flag == '+') {
            asc_bubbleNum(temp);
        }
        else if (flag == '-') {
            down_bubbleNum(temp);
        }
    }
    for (Student* element : temp) {
        if (element->inYear(year)) {
            cout << element->getName() << ", " << element->getID() << endl;
        }
    }
}

void TTM::more_than_n_ucs(int n, string type, char flag) {
    vector<Student*> temp = students;
    if (type == "name") {
        if (flag == '+') {
            asc_bubbleName(temp);
        }
        else if (flag == '-') {
            down_bubbleName(temp);
        }
    }
    else if (type == "num") {
        if (flag == '+') {
            asc_bubbleNum(temp);
        }
        else if (flag == '-') {
            down_bubbleNum(temp);
        }
    }
    for (auto itr = temp.begin(); itr != temp.end(); itr++) {
        if ((*itr)->getNumberClasses() > n) {
            cout << (*itr)->getName() << ", " << (*itr)->getID() << endl;
        }
    }
}

void TTM::buildUCClasses(const string& filename) {
    string uc_code, class_code;

    ifstream thefile(filename);

    if (thefile.is_open())
    {
        string line;
        getline(thefile, line);

        while (!thefile.eof()) {
            getline(thefile, uc_code, ',');
            getline(thefile, class_code, '\n');

            UCClass temp(uc_code, class_code);
            temp.student_counter(classes);
            everyClass.push_back(temp);
        }

        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}

void TTM::buildStudents(const string& filename) { // reads student_classes.csv
    string student_code, student_name, uc_code, class_code;
    string repeat = "0"; // flag

    ifstream thefile(filename);

    if (thefile.is_open())
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(thefile, line);

        // While the end of the file is not reached.
        while (!thefile.eof())
        {
            getline(thefile, student_code, ',');
            getline(thefile, student_name, ',');
            getline(thefile, uc_code, ',');
            getline(thefile, class_code, '\n');

            if (student_code != repeat) {
                Student* temporary_student = new Student(student_name, student_code);

                temporary_student->getAllClasses(filename);
                //temporary_student->getSchedule();
                this->students.push_back(temporary_student);

                repeat = student_code;
            }

        }

        thefile.close(); // Closing the file.
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}

void TTM::removeClass(Student& student, UCClass& uc) {
    bool removed = false;
    for (auto itr = student.allClasses.begin(); itr != student.allClasses.end(); itr++) {
        if (itr->get_class_ID() == uc.get_class_ID() && itr->get_UC_ID() == uc.get_UC_ID()) {
            itr = student.allClasses.erase(itr);
            removed = true;
        }
    }
    if (removed == true) {
        for (auto itr = student.schedule.begin(); itr != student.schedule.end(); itr++) {
            if (itr->getUC() == uc.get_UC_ID()) {
                itr = student.schedule.erase(itr);
                itr--;
            }
        }
        uc.count_decrement();
        requests.front().setDone();
        return;
    }
    else {
        return;
    }

    // uc.count_decrement();    same as with addClass
}

bool TTM::unbalanced(string course, string classID, bool flag) {
    int result = 0;
    int operation = 0;
    vector<UCClass> courseClasses;
    for (auto itr = everyClass.begin(); itr != everyClass.end(); itr++) {
        if (itr->get_UC_ID() == course) {
            courseClasses.push_back(*itr);
        }
    }
    for (unsigned int i = 0; i < courseClasses.size() - 2; i++) {
        result = max(result, courseClasses[i+1].get_student_count() - courseClasses[i].get_student_count());
        if (courseClasses[i+1].get_class_ID() == classID) {
            if (flag == true) {
                operation = max(result, (courseClasses[i+1].get_student_count() - 1) - courseClasses[i].get_student_count());
            }
            else {
                operation = max(result, (courseClasses[i+1].get_student_count() + 1) - courseClasses[i].get_student_count());
            }
        }
        else if (courseClasses[i].get_class_ID() == classID) {
            if (flag == true) {
                operation = max(result, courseClasses[i+1].get_student_count() - (courseClasses[i].get_student_count() - 1));
            }
            else {
                operation = max(result, courseClasses[i+1].get_student_count() - (courseClasses[i].get_student_count() + 1));
            }
        }
        operation = max(result, operation);
    }
    return operation > result;
}

/*!
 * Sorts two Slots (classes) by start time.
 * @param firsts The first Slot to compare.
 * @param seconds The second Slot to compare.
 * @return true if the first Slot starts before the second; otherwise, it returns false.
 */
bool ttm_sorttime(Slot firsts, Slot seconds) {
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
bool ttm_sortday(Slot firsts, Slot seconds) {
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
        return ttm_sorttime(firsts, seconds);
    }
    // cout << fcmp << "," << scmp << "|" << endl;
    return fcmp < scmp;
}

bool TTM::overlap(Student& student, string course, string classID, bool flag) {
    vector<Slot> tmp = student.schedule;
    ClassSchedule carbon(classID);
    if (flag == true) {
        for (auto itr = tmp.begin(); itr != tmp.end(); itr++) {
            if (course == itr->getUC()) {
                itr = tmp.erase(itr);
                itr--;
            }
        }
    }
    carbon.getFullSchedule(class_schedule);
    carbon.getClass(course, tmp);
    sort(tmp.begin(), tmp.end(), ttm_sortday);
    for (unsigned int i = 0; i < tmp.size()-1; i++) {
        if (tmp[i].getDay() == tmp[i+1].getDay()) {
            if (tmp[i].getEnd() > tmp[i+1].getStart()) {
                if (tmp[i].isType() == "PL" || tmp[i].isType() == "TP" || tmp[i+1].isType() == "PL" || tmp[i+1].isType() == "TP") {
                    return true;
                }
            }
        }
    }
    return false;
}

/*!
 * Searches for a specific class (UCClass) in a vector of classes.
 * @param everyclass A vector of classes.
 * @param uc The UC we're searching for.
 * @return true if the class is found, false otherwise.
 */
bool searchClass(vector<UCClass>& everyclass, UCClass& uc) {
    for (auto itr = everyclass.begin(); itr != everyclass.end(); itr++) {
        if (itr->get_UC_ID() == uc.get_UC_ID()) {
            if (itr->get_class_ID() == uc.get_class_ID()) {
                return true;
            }
        }
    }
    return false;
}

void TTM::addClass(Student& student, UCClass& uc) {
    if (student.schedule.size() == 0) { // failsafe, not actually important
        student.getSchedule();
    }

    /*if (uc.get_student_count() >= 20) {
        return;
    }*/

    for (UCClass element: student.allClasses) {
        if (element.get_UC_ID() == uc.get_UC_ID()) {
            return;
        }
    }

    if (!(searchClass(everyClass, uc))) {
        return;
    }

    if (unbalanced(uc.get_UC_ID(), uc.get_class_ID(), false) || overlap(student, uc.get_UC_ID(), uc.get_class_ID(), false)) {
        return;
    }
    else {
        ClassSchedule carbon(uc.get_class_ID());
        carbon.getFullSchedule(class_schedule);
        carbon.getClass(uc.get_UC_ID(), student.schedule);
        sort(student.schedule.begin(), student.schedule.end(), ttm_sortday);
        student.allClasses.push_back(uc);
        uc.count_increment();
        requests.front().setDone();
    }
}

/*!
 * Searches for a specific class (UCClass) in a student's list of classes.
 * @param allClasses A (student's) list of classes.
 * @param uc The UC we're searching for.
 * @return true if the class is found, false otherwise.
 */
bool findClass(list<UCClass>& allClasses, UCClass& uc) {
    for (auto itr = allClasses.begin(); itr != allClasses.end(); itr++) {
        if (itr->get_UC_ID() == uc.get_UC_ID()) {
            if (itr->get_class_ID() == uc.get_class_ID()) {
                return true;
            }
        }
    }
    return false;
}

void TTM::changeClass(Student& student, UCClass& current, UCClass& target) {
    /*if (current.get_student_count() >= 20 || target.get_student_count() >= 20) {
        return;
    }*/

    if (current.get_UC_ID() != target.get_UC_ID()) {
        return;
    }

    if (current.get_class_ID() == target.get_class_ID()) {
        return;
    }

    for (UCClass element: student.allClasses) {
        if (element.get_class_ID() == target.get_class_ID() && element.get_UC_ID() == target.get_UC_ID()) {
            return;
        }
    }

    if (!(findClass(student.allClasses, current))) {
        return;
    }

    if (searchClass(everyClass, current) == false) {
        return;
    }

    if (searchClass(everyClass, target) == false) {
        return;
    }

    if (unbalanced(current.get_UC_ID(), current.get_class_ID(), true) ||
    unbalanced(target.get_UC_ID(), target.get_class_ID(), false) ||
    overlap(student, target.get_UC_ID(), target.get_class_ID(), true)) {
        return;
    }
    else {
        removeClass(student, current);
        addClass(student, target);
        requests.front().setDone();
    }

}

void TTM::process() {
    do {
        int op = requests.front().getType();

        switch (op) {
            case 2: {
                Student *tmp = getStudent(requests.front().student_name, requests.front().student_code);
                if (tmp == nullptr) {
                    log.insert(requests.front());
                    requests.pop();
                    break;
                }
                if (tmp->isScheduleEmpty()) {
                    tmp->getSchedule();
                }
                UCClass ctmp(requests.front().UC_code, requests.front().class_code);
                removeClass(*tmp, ctmp);
                if (!(requests.front().isDone())) {
                    log.insert(requests.front());
                }
                requests.pop();
                break;
            }
            case 3: {
                Student *tmp = getStudent(requests.front().student_name, requests.front().student_code);
                if (tmp == nullptr) {
                    log.insert(requests.front());
                    requests.pop();
                    break;
                }
                if (tmp->isScheduleEmpty()) {
                    tmp->getSchedule();
                }
                UCClass ctmp(requests.front().UC_code, requests.front().class_code);
                addClass(*tmp, ctmp);
                if (!(requests.front().isDone())) {
                    log.insert(requests.front());
                }
                requests.pop();
                break;
            }
            case 4: {
                Student *tmp = getStudent(requests.front().student_name, requests.front().student_code);
                if (tmp == nullptr) {
                    log.insert(requests.front());
                    requests.pop();
                    break;
                }
                if (tmp->isScheduleEmpty()) {
                    tmp->getSchedule();
                }
                UCClass ctmp(requests.front().UC_code, requests.front().class_code);
                UCClass ttmp(requests.front().UC_code, requests.front().target_class);
                changeClass(*tmp, ctmp, ttmp);
                if (!(requests.front().isDone())) {
                    log.insert(requests.front());
                }
                requests.pop();
                break;
            }
        }
    } while(requests.size() != 0);
}

int choice1 = -1;
int choice2 = -1;

void TTM::mainMenu() {
    cout << " ____________________________________________________________________________________" <<  endl;
    cout << "|                                        MENU                                       |" <<  endl;
    cout << "|    0. EXIT                                                                        |" <<  endl;
    cout << "|    1. LISTINGS                                                                    |" <<  endl;
    cout << "|    2. REMOVE A STUDENT FROM A CLASS                                               |" <<  endl;
    cout << "|    3. ADD A STUDENT TO A CLASS                                                    |" <<  endl;
    cout << "|    4. CHANGE A STUDENT'S CLASS                                                    |" <<  endl;
    cout << "|                                                                                   |" <<  endl;
    cout << " ------------------------------------------------------------------------------------" <<  endl;
    cout << endl << "Please choose an option: ";
    cin >> choice1;
}

void TTM::listingsMenu() {
    cout << " ____________________________________________________________________________________" <<  std::endl;
    cout << "|                                    LISTINGS                                       |" <<  std::endl;
    cout << "|    0. BACK                                                                        |" <<  std::endl;
    cout << "|    1. STUDENT'S SCHEDULE                                                          |" <<  std::endl;
    cout << "|    2. STUDENT'S CLASSES                                                           |" <<  std::endl;
    cout << "|    3. STUDENTS IN A CLASS                                                         |" <<  std::endl;
    cout << "|    4. STUDENTS IN A UC                                                            |" <<  std::endl;
    cout << "|    5. STUDENTS IN A YEAR                                                          |" <<  std::endl;
    cout << "|    6. STUDENTS ENROLLED IN MORE THAN N UC'S                                       |" <<  std::endl;
    cout << "|                                                                                   |" <<  std::endl;
    cout << " ------------------------------------------------------------------------------------" <<  std::endl;
    cout << endl << "Please choose an option: ";
    cin >> choice2;
}

void TTM::menu() {
    do {
        choice2 = -1;
        mainMenu();

        switch(choice1) {

            case 1: {
                listings();
                break;
            }

            case 2: {
                string student_name, student_code, UC_code, class_code;
                cout << "Student's name: ";
                cin >> student_name;
                cout << "Student's code: ";
                cin >> student_code;
                cout << "UC's code: ";
                cin >> UC_code;
                cout << "Class's code: ";
                cin >> class_code;

                Request tmpR(2, student_name, student_code, UC_code, class_code);
                requests.push(tmpR);
                break;
            }

            case 3: {
                string student_name, student_code, UC_code, class_code;
                cout << "Student's name: ";
                cin >> student_name;
                cout << "Student's code: ";
                cin >> student_code;
                cout << "UC's code: ";
                cin >> UC_code;
                cout << "Class's code: ";
                cin >> class_code;

                Request tmpR(3, student_name, student_code, UC_code, class_code);
                requests.push(tmpR);
                break;
            }

            case 4: {
                string student_name, student_code, UC_code, class_code, target_class;
                cout << "Student's name: ";
                cin >> student_name;
                cout << "Student's code: ";
                cin >> student_code;
                cout << "UC's code: ";
                cin >> UC_code;
                cout << "Current class's code: ";
                cin >> class_code;
                cout << "Target class's code: ";
                cin >> target_class;

                Request tmpR(4, student_name, student_code, UC_code, class_code, target_class);
                requests.push(tmpR);
                break;
            }
        }

    } while(choice1 != 0);
}

void TTM::listings() {
    do {
        listingsMenu();

        switch(choice2){

            case 1: {
                string student_name, student_num;
                cout << "Student's name: ";
                cin >> student_name;
                cout << "Student's code: ";
                cin >> student_num;
                cout << "\n";
                Student* tmp = getStudent(student_name, student_num);
                if (tmp == nullptr) {
                    break;
                }
                if (tmp->isScheduleEmpty()) {
                    tmp->getSchedule();
                }
                tmp->showSchedule();
                break;
            }
            case 2: {
                string student_name, student_num;
                cout << "Student's name: ";
                cin >> student_name;
                cout << "Student's code: ";
                cin >> student_num;
                cout << "\n";
                Student *tmp = getStudent(student_name, student_num);
                if (tmp == nullptr) {
                    break;
                }
                tmp->showAllClasses();
                break;
            }
            case 3: {
                string class_name, sort_param;
                char order;
                cout << "Class's name: ";
                cin >> class_name;
                cout << "Choose the sorting parameter (name or num): ";
                cin >> sort_param;
                cout << "Choose the sorting order (+ or -): ";
                cin >> order;
                cout << "\n";
                studentsInClass(class_name, sort_param, order);
                break;
            }
            case 4: {
                string uc_name, uc_sort_param;
                char uc_order;
                cout << "Class's name: ";
                cin >> uc_name;
                cout << "Choose the sorting parameter (name or num): ";
                cin >> uc_sort_param;
                cout << "Choose the sorting order (+ or -): ";
                cin >> uc_order;
                cout << "\n";
                studentsInUC(uc_name, uc_sort_param, uc_order);
                break;
            }
            case 5: {
                string y_sort_param;
                char student_year, y_order;
                cout << "Year: ";
                cin >> student_year;
                cout << "Choose the sorting parameter (name or num): ";
                cin >> y_sort_param;
                cout << "Choose the sorting order (+ or -): ";
                cin >> y_order;
                cout << "\n";
                studentsInYear(student_year, y_sort_param, y_order);
                break;
            }
            case 6: {
                int num_of_ucs;
                string num_sort_param;
                char num_order;
                cout << "Number of UC's: ";
                cin >> num_of_ucs;
                cout << "Choose the sorting parameter (name or num): ";
                cin >> num_sort_param;
                cout << "Choose the sorting order (+ or -): ";
                cin >> num_order;
                cout << "\n";
                more_than_n_ucs(num_of_ucs, num_sort_param, num_order);
                break;
            }
        }

    } while(choice2 != 0);
}

void TTM::saveout() {
    ofstream myfile("../schedule/new_students.csv");
    myfile << "\n";
    for (auto itr = students.begin(); itr != students.end(); itr++) {
        (*itr)->allClasses.sort();
        for (UCClass element : (*itr)->allClasses) {
            myfile << (*itr)->getID();
            myfile << ",";
            myfile << (*itr)->getName();
            myfile << ",";
            myfile << element.get_UC_ID();
            myfile << ",";
            myfile << element.get_class_ID();
            myfile << "\n";
        }
    }
    myfile.close();
    remove("../schedule/students_classes.csv");
    rename("../schedule/new_students.csv", "../schedule/students_classes.csv");
}

void TTM::logout(const std::string &filename) {
    ofstream myfile;
    myfile.open (filename);
    for (auto itr = log.begin(); itr != log.end(); itr++) {
        myfile << "Request type: ";
        myfile << itr->getType();
        myfile << ", ";
        myfile << itr->student_name;
        myfile << ", ";
        myfile << itr->student_code;
        myfile << "\n";
    }
    myfile.close();
}
