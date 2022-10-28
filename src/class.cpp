#include "../headers/class.h"

ClassSchedule::ClassSchedule(string ucID, string classID, list<Slot> classSchedule) {
    this->ucID = ucID;
    this->classID = classID;
    this->classSchedule = ClassSchedule;
}

string ClassSchedule::get_UC_ID() const{
    return ucID;
}

string ClassSchedule::get_class_ID() const{
    return classID;
}
