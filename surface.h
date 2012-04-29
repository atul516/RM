#ifndef SURFACE_H
#define SURFACE_H

#include "GLWidget.h"

class Surface : public GLWidget{
private:
    double rightX;
    double topY;
    double bottomY;
    double leftX;
    double highest;
    double lowest;
    int division_factor;
    int surface_type;
    std::vector< coordinates > holes_coordinates;
    std::vector< std::vector< coordinates > >seam_coordinates; //per row, it contains seam base/top coordinates
    std::vector< std::vector< coordinates > > surface_nodes;
    std::vector<std::vector< std::vector< coordinates > > >seam_nodes;
public:
    Surface(std::vector< coordinates >,int);
    void setX();
    void setY();
    void setHighLow();
    void setDivisionFactor(int);
    void setSurfaceType(int);
    void setSeamCoordinates();
    double getRightX();
    double getTopY();
    double getBottomY();
    double getLeftX();
    int getDivisionFactor();
    int getSurfaceType();
    void computeSurfaceNodes();
    void computeSeamNodes();
    double computeZ(double,double);
    void drawSurface();
    void drawSeam();
protected:
    void paintGL();
};

#endif // SURFACE_H
