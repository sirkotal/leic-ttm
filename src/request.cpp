#include "../headers/request.h"

Request::Request(string type, string date) {
    this->type = type;
    this->date = date;
}

bool Request::isDone() const{
    return completed;
}

string Request::getType() const{
    return type;
}

void setDone() {
    this->completed = true;
}