#ifndef DRILLHOLE_H
#define DRILLHOLE_H

#include <sstream>
#include "imageloader.h"
#include "hole.h"
class DrillHole : public GLWidget{
private:
    GLuint *textureId[6]; //The OpenGL id of the texture
    std::vector< std::vector<std::string> > spcf;
    std::vector< std::vector<std::string> > hole_info;
    std::vector< Hole > holes;
    ImageLoader *image;
    QString str;
    int single;
    QFont f;
    std::string property_name[10];
    std::string property_type[10];
    std::string property_unit[10];
    int no_of_holes;
    int no_of_properties;
    QString hole_location;
    QString hole_direction;
    std::vector<float> temp;
    float UCS[10];
    float RQD[10];
    std::string UCS_str[10];
    std::string RQD_str[10];
public:
    DrillHole(const char *, const char *, int);
    int Lithology();
    int Property();
    int Caption();
    int drawHole();
    void setDisplayType(int);
    void setParams();
    bool isSingle();
    void displayError();
protected:
    void paintGL();
};

#endif // DRILLHOLE_H
