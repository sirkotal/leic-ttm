#include "../headers/uc_class.h"

UCClass::UCClass(string ucID, string classID) {
    this->ucID = ucID;
    this->classID = classID;
}

string UCClass:get_UC_ID() const{
    return ucID;
}
    
string UCClass::get_class_ID() const{
    return classID;
}