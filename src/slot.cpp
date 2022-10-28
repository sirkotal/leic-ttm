#include "slot.h"

Slot::Slot(WeekDay day, float start, float end, string type) {
        this->day = day;
        this->start = start;
        this->end = end;
        this->type = type;
    }

float Slot::getStart() const{
    return start;
}

float Slot::getEnd() const{
    return end;
}

string Slot::classType() const{
    return type;
}