#ifndef SURFACE_H
#define SURFACE_H

#include "GLWidget.h"

class Surface: public GLWidget{
private:
    float rightX;
    float topY;
    float bottomY;
    float leftX;
    int division_factor;
    std::vector< coordinates > holes_coordinates;
    std::vector< std::vector< coordinates > > nodes;
public:
    Surface(std::vector< coordinates >);
    void setX();
    void setY();
    void setDivisionFactor(int);
    float getRightX();
    float getTopY();
    float getBottomY();
    float getLeftX();
    int getDivisionFactor();
    void computeNodes();
    float computeZ(float,float);
    void drawSurface();
protected:
    void paintGL();
};

#endif // SURFACE_H
