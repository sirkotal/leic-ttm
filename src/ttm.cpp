#include "../headers/ttm.h"
#define classes "../schedule/students_classes.csv"

// Set sorting function
/*bool TTM::student_code_comparison(Student first, Student second) {
    int x = stoi(first.getID());
    int y = stoi(second.getID());
    return x < y;
}

bool TTM::student_uc_number_comparison(Student first, Student second) {
    int x = stoi(first.getID());
    int y = stoi(second.getID());
    return x < y;
}

void TTM::vsize() {
    cout << everyClass.size() << endl;
}*/

bool TTM::searchStudent(string s_student, string s_uc_code)
{
    for (const Student* student: students) {
        if (student->getName() == s_student && student->getID() == s_uc_code) {
            return true;
        }
    }
    return false;
}

Student TTM::getStudent(string s_name, string student_code) {
    for (auto itr = students.begin(); itr != students.end(); itr++) {
        if ((*itr)->getName() == s_name && (*itr)->getID() == student_code) {
            return *(*itr);
        }
    }
}

UCClass TTM::getClass(string ucID, string classID) {
    for (auto itr = everyClass.begin(); itr != everyClass.end(); itr++) {
        if (itr->get_UC_ID() == ucID && itr->get_class_ID() == classID) {
            return *itr;
        }
    }
}

void asc_bubbleNum(vector<Student*>& stvec) // ascending bubble sort by number
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getID() > stvec[j + 1]->getID())
                swap(stvec[j], stvec[j + 1]);
}

void down_bubbleNum(vector<Student*>& stvec) // descending bubble sort by number
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getID() < stvec[j + 1]->getID())
                swap(stvec[j], stvec[j + 1]);
}

void asc_bubbleName(vector<Student*>& stvec) // ascending bubble sort by name
{
    unsigned int i, j;
    for (i = 0; i < stvec.size()-1; i++)
        for (j = 0; j < stvec.size() - i - 1; j++)
            if (stvec[j]->getName() > stvec[j + 1]->getName())
                swap(stvec[j], stvec[j + 1]);
}

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

void TTM::print_students_with_more_than_n_ucs(int n)
{
    for (auto itr = students.begin(); itr != students.end(); itr++) {
        if ((*itr)->getNumberClasses() > n) {
            cout << (*itr)->getName() << ", " << (*itr)->getID() << endl;
        }
    }
}

// Reader functions definitions

/* void TTM::csv_classes_reader(const string& filename)
{
    // File variables.
    string class_code, uc_code, weekday, start_hour, duration, type;


    // Filename
    ifstream coeff(filename); // Opens the file.

    if (coeff.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(coeff, line);

        // While the end of the file is not reached.
        while (!coeff.eof())
        {
            //{class_code, uc_code, weekday, start_hour, duration, type}
            getline(coeff, class_code, ',');
            v_class_code.push_back(class_code);

            getline(coeff, uc_code, ',');
            v_uc_code.push_back(uc_code);

            getline(coeff, weekday, ',');
            v_weekday.push_back(weekday);

            getline(coeff, start_hour, ',');
            v_start_hour.push_back(start_hour);

            getline(coeff, duration, ',');
            v_duration.push_back(duration);

            getline(coeff, type, '\n');
            v_type.push_back(type);
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}*/

/*!
 * Function that retrieves every UCClass we can work with
 * @param filename The .csv file to use for information retrieval
 */
void TTM::csv_classes_per_uc_reader(const string& filename)
{
    // File variables.
    string uc_code, class_code;

    // Filename
    ifstream coeff(filename); // Opens the file.

    if (coeff.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(coeff, line);

        // While the end of the file is not reached.
        while (!coeff.eof())
        {
            //{class_code, uc_code}

            getline(coeff, uc_code, ',');
            getline(coeff, class_code, '\n');

            UCClass temp(uc_code, class_code);
            temp.student_counter(classes);
            everyClass.push_back(temp);
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}

void TTM::csv_students_classes_reader(const string& filename)
{
    // File variables.
    string student_code, student_name, uc_code, class_code;
    string repeat = "0"; // flag

    // Filename
    ifstream coeff(filename); // Opens the file.

    if (coeff.is_open()) // Checks if the file is open.
    {
        // Skip the first line (ClassCode,UcCode,Weekday,StartHour,Duration,Type).
        string line;
        getline(coeff, line);

        // While the end of the file is not reached.
        while (!coeff.eof())
        {
            getline(coeff, student_code, ',');
            getline(coeff, student_name, ',');
            getline(coeff, uc_code, ',');
            getline(coeff, class_code, '\n');

            if (student_code != repeat) {
                Student* temporary_student = new Student (student_name, student_code);

                temporary_student->getAllClasses(filename);
                this->students.push_back(temporary_student);

                repeat = student_code;
            }

        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


// Request management functions definitions

/*Request TTM::get_request()
{
    return this->requests.front();
}

void TTM::add_request_to_queue(Request request)
{
    requests.push(request);
}*/

bool TTM::removeClass(Student& student, UCClass& uc) {
    bool removed = false;
    for (auto itr = student.allClasses.begin(); itr != student.allClasses.end(); itr++) {
        if (itr->get_class_ID() == uc.get_class_ID() && itr->get_UC_ID() == uc.get_UC_ID()) {
            itr = student.allClasses.erase(itr);
            removed = true;
        }
    }
    if (removed == true) {
        return true;
    }
    else {
        return false;
    }

    // uc.count_decrement();    same as with addClass
}

bool TTM::unbalanced(string course, string classID, bool flag) {
    int result = 0;
    int operation = 0;
    vector<UCClass> courseClasses;
    for (UCClass element: everyClass) {
        if (element.get_UC_ID() == course) {
            courseClasses.push_back(element);
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

/*bool TTM::overlap(Student& student, string course, string classID, bool flag) {
    vector<Slot> tmp = student.schedule;
    ClassSchedule carbon(string classID);
    if (flag == true) {
        for (auto itr = tmp.begin(); itr != tmp.end(); itr++) {
            if (course == itr->getUC()) {
                tmp.erase(itr);
                itr--;
            }
        }
    }
    carbon.getFullSchedule

}*/

bool TTM::addClass(Student& student, UCClass& uc) {
    if (student.schedule.size() == 0) {
        student.getSchedule();
    }

    if (uc.get_student_count() >= 20) {
        return false;
    }

    for (UCClass element: student.allClasses) {
        if (element.get_UC_ID() == uc.get_UC_ID()) {
            return false;
        }
    }

    if(unbalanced(uc.get_UC_ID(), uc.get_class_ID(), false)) {

    }

}

void TTM::process() {
    do {
        int op = requests.front().getType();

        switch (op) {
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    } while(requests.size() != 0);
}
