#include "surface.h"

void Surface::setX(float a,float b){
    this->rightX = b;
    this->leftX = a;
}

void Surface::setY(float a,float b){
    this->bottomY = b;
    this->topY = a;
}

void Surface::setMeshSize(float a){
    this->meshSize = a;
}

float Surface::getRightX(){
    return this->rightX;
}

float Surface::getTopY(){
    return this->topY;
}

float Surface::getBottomY(){
    return this->bottomY;
}

float Surface::getLeftX(){
    return this->leftX;
}

float Surface::getMeshSize(){
    return this->meshSize;
}

void Surface::computeNodes(){
    float width = this->getRightX() - this->getLeftX();
    float height = this->getTopY() - this->getBottomY();
    float nodew = width/30;
    float nodeh = height/30;
    int k = 0;

    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            this->nodes[k].x = this->getLeftX() + (j*nodew);
            this->nodes[k].y = this->getBottomY() + (i*nodeh);
            k++;
            this->computeZ(k);
        }
    }
}

void Surface::computeZ(int k){

}

void Surface::paintGL(){

}

Surface::Surface(std::vector< coordinates > c){
    this->holes_coordinates = c;
}
