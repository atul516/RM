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
    bool show_seam;
    std::vector< coordinates > holes_coordinates;
    std::vector< std::vector< double > >seam_coordinates; //per row, it contains seam base/top coordinates
    std::vector< std::vector< coordinates > > surface_nodes;
    std::vector< std::vector< coordinates > > seam_top_nodes; //double, considering all holes are vertically straight and there is a single seam
    std::vector< std::vector< coordinates > > seam_bottom_nodes;
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
    void setShowSeam(bool);
    void setShowHoles(bool);
    double getRightX();
    double getTopY();
    double getBottomY();
    double getLeftX();
    int getDivisionFactor();
    int getSurfaceType();
    void computeSurfaceNodes();
    void computeSeamNodes();
    double computeSurfaceZ(double,double);
    double computeSeamZ(double,double,int);
    void drawSurface();
    void drawSeam();
    void drawSeamPatches(int);
    void drawHolesUnderSurface();
protected:
    void paintGL();
};

#endif // SURFACE_H
