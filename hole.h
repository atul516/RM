#ifndef HOLE_H
#define HOLE_H

#include <string>
#include <vector>

struct coordinates{
    float x;
    float y;
    float z;
};

class Hole{
private:
    std::string hole_id;
    float hole_dip;
    float hole_length;
    coordinates hole_coordinate;
public:
    Hole();
    void setHoleId(const char*);
    void setHoleDip(float);
    void setHoleLength(float);
    void setCoordinates(float,float,float);
    float getX();
    float getY();
    float getZ();
    std::string getHoleId();
    float getHoleDip();
    float getHoleLength();
    std::vector< std::string > material_name;
    std::vector< float > material_depth;
    std::vector< std::vector< std::string > > other_material_properties;

};

#endif // HOLE_H
