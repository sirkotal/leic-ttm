#include "classes.h"

void Classes::csv_classes_reader(const string& filename, vector <string>& v_class_code, vector <string>& v_uc_code, vector <string>& v_weekday, vector <string>& v_start_hour, vector <string>& v_duration, vector <string> v_type)
{

    //#include <fstream>
    //#include <sstream>
    #include <iostream>
    //#include <iomanip>
    #include <vector>

    // File variables.
    string class_code, uc_code, weekday, start_hour, duration, type;

    /*
    // The following vectors will store the corresponding information from the classes.csv file.
    vector <string> v_class_code[];
    vector <string> v_uc_code[];
    vector <string> v_weekday[];
    vector <string> v_start_hour[];
    vector <string> v_duration[];
    vector <string> v_type[];
     */

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
