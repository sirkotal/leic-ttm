#include "../headers/slot.h"

Slot::Slot(string uc, string day, float start, float end, string type) {
    this->uc = uc;
    this->day = day;
    this->start = start;
    this->end = end;
    this->type = type;
}

string Slot::getUC() const{
    return uc;
}

string Slot::getDay() const{
    return day;
}

float Slot::getStart() const{
    return start;
}

float Slot::getEnd() const{
    return end;
}

string Slot::isType() const{
    return type;
}