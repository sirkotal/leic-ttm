#include <bits/stdc++.h>
#include "../headers/student.h"
#define students_classes "../schedule/students_classes.csv"
using namespace std;

int main() {
    vector <string> v_student_code;
    vector <string> v_student_name;
    vector <string> v_uc_code;
    vector <string> v_class_code;

    Student::csv_students_classes_reader(students_classes, v_student_code, v_student_name, v_uc_code, v_class_code);

    for (string element : v_student_code)
    {
        cout << element << endl;
    }
}