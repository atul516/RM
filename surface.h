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
    bool show_holes;
    std::vector< coordinates > holes_coordinates;
    std::vector< std::vector< double > >seam_coordinates; //per row, it contains seam base/top coordinates
    std::vector< std::vector< coordinates > > surface_nodes;
    std::vector< std::vector< std::vector< double > > >seam_nodes; //double, considering all holes are vertically straight
    std::vector< double > hole_depths;
public:
    Surface(std::vector< coordinates >,int);
    void setX();
    void setY();
    void setHighLow();
    void setDivisionFactor(int);
    void setSurfaceType(int);
    void setSeamCoordinates(std::vector< std::vector< double > >);
    void setHoleDepths(std::vector< double >);
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
    void drawSeamPatches(int);
    void drawHolesUnderSurface();
protected:
    void paintGL();
};

#endif // SURFACE_H
