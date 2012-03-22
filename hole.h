#ifndef HOLE_H
#define HOLE_H
#include <string>
#include <vector>
class Hole{
private:
    std::string hole_id;
    float hole_dip;
    std::vector< std::string > material_name;
    std::vector< float > material_depth;
    std::vector< std::vector< std::string > > other_material_properties;
public:
    void setHoleId(std::string);
    void setHoleDip(std::string);

};

#endif // HOLE_H
