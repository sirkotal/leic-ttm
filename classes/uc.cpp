#include "../headers/uc.h"

void UC::csv_classes_per_uc_reader(const string& filename, vector <string>& v_uc_code, vector <string>& v_class_code)
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
            //{uc_code,class_code}
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