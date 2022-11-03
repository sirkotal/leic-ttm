#include "../headers/ttm.h"

// Set sorting function
bool student_code_comparison(Student first, Student second) {
    int x = stoi(first.getID());
    int y = stoi(second.getID());
    return x < y;
}

bool student_uc_number_comparison(Student first, Student second) {
    int x = stoi(first.getID());
    int y = stoi(second.getID());
    return x < y;
}

bool TTM::searchStudent(set<Student>& students, string s_student, string s_uc_code)
{
    for (const Student student: students) {
        if (student.getName() == s_student && student.getID() == s_uc_code) {
            return true;
        }
    }
    return false;
}

Student TTM::getStudent(set<Student> &students, std::string s_student, std::string s_uc_code) {
    return *students.find(Student(s_student, s_uc_code));
}

void TTM::print_students_with_more_than_n_ucs(set<Student>& students, int n)
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
            getline(coeff, student_code, ',');
            getline(coeff, student_name, ',');
            getline(coeff, uc_code, ',');
            getline(coeff, class_code, ',');

            Student temporary_student(student_name, student_code);
            UCClass temporary_class(uc_code, class_code);

            temporary_student.buildClass(temporary_class);
            this->students.insert(temporary_student);


        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}


// Request management functions definitions

queue<Request> TTM::get_request()
{
    return this->requests;
}

void TTM::add_request_to_queue(Request request)
{
    get_request();
    requests.push(request);
}
