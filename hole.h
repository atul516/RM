#ifndef HOLE_H
#define HOLE_H
#include <string>
#include <vector>
class Hole{
private:
    std::string hole_id;
    float hole_dip;
    float hole_length;
public:
    void setHoleId(const char*);
    void setHoleDip(const char*);
    void setHoleLength(float);
    std::vector< std::string > material_name;
    std::vector< float > material_depth;
    std::vector< std::vector< std::string > > other_material_properties;

};

#endif // HOLE_H
