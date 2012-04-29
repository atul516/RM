#include "hole.h"
#include <iostream>

Hole::Hole(){
    this->hole_id = "";
}

void Hole::setHoleDip(double d){
    this->hole_dip = d;
}

double Hole::getHoleDip(){
    return this->hole_dip;
}

void Hole::setHoleId(const char* str){
    //this->hole_id.assign(str);
}

std::string Hole::getHoleId(){
    return this->hole_id;
}

void Hole::setHoleDepth(double l){
    this->hole_depth = l;
}

double Hole::getHoleDepth(){
    return this->hole_depth;
}

void Hole::setCoordinates(double a, double b, double c){
    this->hole_coordinate.x = a;
    this->hole_coordinate.y = b;
    this->hole_coordinate.z = c;
}

double Hole::getX(){
    return this->hole_coordinate.x;
}

double Hole::getY(){
    return this->hole_coordinate.y;
}

double Hole::getZ(){
    return this->hole_coordinate.z;
}
Hole::~Hole(){
}
