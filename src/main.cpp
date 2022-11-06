#include <bits/stdc++.h>
#include "../headers/student.h"
#include "../headers/ttm.h"
#include "../headers/slot.h"
#include "../headers/uc_class.h"
#include "../headers/class_schedule.h"

#define students_classes "../schedule/students_classes.csv"
#define classes "../schedule/classes.csv"
#define classes_per_uc "../schedule/classes_per_uc.csv"
#define logfile "../archive/log.txt"
using namespace std;

int main() {
    TTM manage;
    manage.buildStudents(students_classes);
    manage.buildUCClasses(classes_per_uc);
    manage.menu();
    manage.process();
    manage.saveout();
    manage.logout(logfile);
}