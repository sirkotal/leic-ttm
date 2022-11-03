#ifndef INTERFACE_H
#define INTERFACE_H

#include <bits/stdc++.h>

using namespace std;

class Interface {
    public:
    void initialize();

    private:
    enum operations {};
    operations type;

    void mainMenu();
    void listingsMenu();

    int menu();

    void loginList();

    void loginChange();
};

#endif