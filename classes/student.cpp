#include "../headers/student.h"

void Student::csv_students_classes_reader(const string& filename, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{
    // File variables.
    string student_code, student_name, uc_code, class_code;

    // Filename
    ifstream coeff(filename); // Opens the file.

    int number_students = 0;

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
            v_student_name.push_back(student_name);

            getline(coeff, uc_code, ',');
            v_uc_code.push_back(uc_code);

            getline(coeff, class_code, '\n');
            v_class_code.push_back(class_code);

            number_students++;
        }

        coeff.close(); // Closing the file.
    }
    else
    {
        cout << "Error: Unable to open file."; // In case the program fails to open the file, this error message appears.
    }
}

void Student::sort_student(const string student_name, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{
    //Binary Trees
    //If we organize data in separate vectors we'll need to sort them all, so as to put corresponding information on the same indexes
}

void Student::remove_student_from_class(const string student_name, const int student_number, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{

}

void Student::add_student_to_class(const string student_name, const int student_number, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{
    /*
    a) Só é possível se a turma possui vaga. Considerar a capacidade de uma turma
    igual a um valor máximo Cap.
    b) Só é possível se não provoca desequilíbrio nas turmas dessa UC. Considerar
    que existe desequilíbrio nas turmas de uma UC se a diferença entre o nº de
    estudantes em duas quaisquer turmas dessa UC é >=4.
     */
}

void Student::change_student_class(const string student_name, const int student_number, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{
    //use remove and add function (?)
    /*
    a) Só é possível se a turma possui vaga. Considerar a capacidade de uma turma
    igual a um valor máximo Cap.
    b) Só é possível se não provoca desequilíbrio nas turmas dessa UC. Considerar
    que existe desequilíbrio nas turmas de uma UC se a diferença entre o nº de
    estudantes em duas quaisquer turmas dessa UC é >=4.
     */
}

void Student::change_student_ucs(const string student_name, const int student_number, vector <string>& v_student_code, vector <string>& v_student_name, vector <string>& v_uc_code, vector <string>& v_class_code)
{
    /*
    Alterar um conjunto de turmas/UCs de um estudante. Considerar as alternativas a) e
    b) do caso ii.
    */
}