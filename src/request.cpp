#include "../headers/request.h"

Request::Request(int type, string student_name, string student_code, string UC_code, string class_code) {
    this->type = type;
    this->student_name = student_name;
    this->student_code = student_code;
    this->UC_code = UC_code;
    this->class_code = class_code;
}

Request::Request(int type, string student_name, string student_code, string UC_code, string class_code, string target_UC,
                 string target_class) {
    this->type = type;
    this->student_name = student_name;
    this->student_code = student_code;
    this->UC_code = UC_code;
    this->class_code = class_code;
    this->target_UC = target_UC;
    this->target_class = target_class;
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

bool Request::operator<(const Request &next) const {
    return student_code < next.student_name;
}