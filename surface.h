#ifndef SURFACE_H
#define SURFACE_H

#include "GLWidget.h"

class Surface : public GLWidget{
private:
    double rightX;
    double topY;
    double bottomY;
    double leftX;
    int division_factor;
    int surface_type;
    std::vector< coordinates > holes_coordinates;
    std::vector< std::vector< coordinates > > nodes;
public:
    Surface(std::vector< coordinates >,int);
    void setX();
    void setY();
    void setDivisionFactor(int);
    void setSurfaceType(int);
    double getRightX();
    double getTopY();
    double getBottomY();
    double getLeftX();
    int getDivisionFactor();
    int getSurfaceType();
    void computeNodes();
    double computeZ(double,double);
    void drawSurface();
protected:
    void paintGL();
};

#endif // SURFACE_H
