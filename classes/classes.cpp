#include "classes.h"

void Classes::void csv_classes_reader(const string& filename) {

    #include <fstream>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <vector>

    // The following arrays will store the corresponding information from the classes.csv file.
    string class_code[];
    string uc_code[];
    string weekday[];
    string start_hour[];
    string duration[];
    string type[];

    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open(filename, ios::out | ios::app);

    string class_code,uc_code,weekday,start_hour,duration,type;

    // Read the input
    for (i = 0; i < 5; i++) {

        cin >> class_code
            >> uc_code
            >> weekday
            >> start_hour
            >> duration
            >> type
    }
}


