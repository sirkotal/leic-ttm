#include <bits/stdc++.h>
#include "../headers/student.h"
#define students_classes "../schedule/students_classes.csv"
using namespace std;

void menu ()
{
    int option;

    cout << "Selecione a opcao: " << endl;
    cout << "[1]: Ocupacao de turmas/ano/UC" << endl;
    cout << "[2]: Horario de determinado estudante" << endl;
    cout << "[3]: Estudantes em determinada turma/UC/ano" << endl;
    cout << "[4]: Estudantes com mais de n" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << "Funcao 1";
            break;
        case 2:
            int num;
            cout << "Numero do estudante, etc. :";
            cin >> num;
            cout << "Funcao 2";
            break;
        case 3:
            cout << "Funcao 3";
            break;
        case 4:
            cout << "Funcao 4";
            break;
    }
}

int main() {
    /*
    vector <string> v_student_code;
    vector <string> v_student_name;
    vector <string> v_uc_code;
    vector <string> v_class_code;

    Student::csv_students_classes_reader(students_classes, v_student_code, v_student_name, v_uc_code, v_class_code);

    for (string element : v_student_code)
    {
        cout << element << endl;
    }
     */
    menu();
}