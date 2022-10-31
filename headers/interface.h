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

    void showMenu();

    void isNum();

    void menu();

    void loginList();

    void loginChange();
}

#endif