#include "hole.h"

Hole::Hole(){
}

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

void Hole::setCoordinates(float a, float b, float c){
    this->hole_coordinate.x = a;
    this->hole_coordinate.y = b;
    this->hole_coordinate.z = c;
}

float Hole::getX(){
    return this->hole_coordinate.x;
}

float Hole::getY(){
    return this->hole_coordinate.y;
}

float Hole::getZ(){
    return this->hole_coordinate.z;
}
