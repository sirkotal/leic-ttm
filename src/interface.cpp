#include "../headers/ttm.h"
#include "../headers/interface.h"
#define CLEAR "clear"

void Interface::mainMenu() {
    std::cout << " ____________________________________________________________________________________" <<  std::endl;
    std::cout << "|                                        MENU                                       |" <<  std::endl;
    std::cout << "|    0. EXIT                                                                        |" <<  std::endl;
    std::cout << "|    1. LISTINGS                                                                    |" <<  std::endl;
    std::cout << "|    2. REMOVE A STUDENT FROM A CLASS                                               |" <<  std::endl;
    std::cout << "|    3. ADD A STUDENT TO A CLASS                                                    |" <<  std::endl;
    std::cout << "|    4. CHANGE A STUDENT'S CLASS                                                    |" <<  std::endl;
    std::cout << "|    5. CHANGE MULTIPLE STUDENT'S CLASSES                                           |" <<  std::endl;
    std::cout << "|                                                                                   |" <<  std::endl;
    std::cout << "|                                                                                   |" <<  std::endl;
    std::cout << " ------------------------------------------------------------------------------------" <<  std::endl;
}

void Interface::listingsMenu() {
    std::cout << " ____________________________________________________________________________________" <<  std::endl;
    std::cout << "|                                        MENU                                       |" <<  std::endl;
    std::cout << "|    0. BACK                                                                        |" <<  std::endl;
    std::cout << "|    1. STUDENT'S SCHEDULE                                                          |" <<  std::endl;
    std::cout << "|    2. STUDENT'S CLASSES                                                           |" <<  std::endl;
    std::cout << "|    3. STUDENTS IN A CLASS                                                         |" <<  std::endl;
    std::cout << "|    4. CLASS'S SCHEDULE                                                            |" <<  std::endl;
    std::cout << "|    5. CHANGE MULTIPLE STUDENT'S CLASSES                                           |" <<  std::endl;
    std::cout << "|    6. CLASS'S CAPACITY                                                            |" <<  std::endl;
    std::cout << "|                                                                                   |" <<  std::endl;
    std::cout << " ------------------------------------------------------------------------------------" <<  std::endl;
}

/*void Interface::initialize() {

    while(true) {
        int flag = menu();
        if(flag == 0) {
            break;
        }
        else if(flag == 1){
            TYPE = AIRPLANECOMPANY;
        }
        else if(flag ==2){
            TYPE = TIMETABLESPUBLIC;
        }else
            break;
        login();
    }
}*/

bool isNum(const string &str) {            //verifies if the string contains only numbers
    for (int i = 0; i < str.size(); i++){

        if(isdigit(str[i]) == false)
            return false;

    }
    return true;
}

int Interface::menu() {
    // verifies the user input
    bool flag = true;

    int number = 50;

    while (flag) {          //checks the input
        mainMenu(); // displays main menu

        string inp; // input

        std::cin >> inp;

        if (cin.fail() || cin.peek() != '\n' || inp.size() != 1 || !isNum(inp)) {
            system(CLEAR);
            cout << "Invalid input" << endl;

            // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();

            flag = true;

        }
        else {

            stringstream strstream(inp);

            strstream >> number;

            if (number == 0 || number == 1 || number == 2 || number == 3 || number == 4 || number == 5) {
                flag = false;
            }
            else {
                system(CLEAR);
                cout << "Invalid input" << endl;
            }
        }
    }

    return number;
}
