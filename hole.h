#ifndef HOLE_H
#define HOLE_H

#include <string>
#include <vector>
#include "GLWidget.h"

class Hole{
private:
    std::string hole_id;
    double hole_dip;
    double hole_depth;
    coordinates hole_coordinate;
public:
    Hole();
    ~Hole();
    void setHoleId(const char*);
    void setHoleDip(double);
    void setHoleDepth(double);
    void setCoordinates(double,double,double);
    double getX();
    double getY();
    double getZ();    
    std::string getHoleId();
    double getHoleDip();
    double getHoleDepth();
    coordinates seam_top_coordinate;
    coordinates seam_bottom_coordinate;
    std::vector< std::string > material_name;
    std::vector< double > material_depth;
    std::vector< std::vector< std::string > > other_material_properties;

};

#endif // HOLE_H
