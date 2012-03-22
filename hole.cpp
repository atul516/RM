#include "hole.h"

void Hole::setHoleDip(float d){
    this->hole_dip = d;
}

float Hole::getHoleDip(){
    return this->hole_dip;
}

void Hole::setHoleId(const char* i){
    this->hole_id = i;
}

std::string Hole::getHoleId(){
    return this->hole_id;
}

void Hole::setHoleLength(float l){
    this->hole_length = l;
}

float Hole::getHoleLength(){
    return this->hole_length;
}
