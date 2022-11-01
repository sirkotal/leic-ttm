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

// Reader functions definitions

void TTM::csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type)
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
}

void TTM::csv_classes_per_uc_reader(const string& filename, vector <string>& v_uc_code, vector <string>& v_class_code)
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
            //{class_code, uc_code, weekday, start_hour, duration, type}
            getline(coeff, uc_code, ',');
            v_uc_code.push_back(uc_code);

            getline(coeff, class_code, '\n');
            v_class_code.push_back(class_code);
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}

void TTM::csv_students_classes_reader(const string& filename, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
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
            v_student_code.push_back(student_code);

            getline(coeff, student_name, ',');
            /*
            set<int> s;

            s.insert(1);
             */

            Student temporary_student(student_name, student_code);
            this->students.insert(temporary_student);

            getline(coeff, uc_code, ',');
            v_uc_code.push_back(uc_code);

            getline(coeff, class_code, ',');
            v_class_code.push_back(class_code);
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
