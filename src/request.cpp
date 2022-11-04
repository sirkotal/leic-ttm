#include "../headers/request.h"

Request::Request(int type, string student_code, string class_code) {
    this->type = type;
    this->student_code = student_code;
    this->class_code = class_code;
}

bool Request::isDone() const{
    return done;
}

int Request::getType() const {
    return type;
}

void Request::setDone() {
    this->done = true;
}