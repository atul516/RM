#ifndef DRILLHOLE_H
#define DRILLHOLE_H

#include <sstream>
#include "imageloader.h"
class DrillHole : public GLWidget{
private:
    GLuint textureId[6]; //The OpenGL id of the texture
    std::vector< std::vector<std::string> > spcf;
    ImageLoader image;
    QString str;
    QFont f;
    QString hole_id;
    QString hole_location;
    QString hole_direction;
    float temp[6];
    float texture_depth[6];
    std::string name[10];
    float UCS[10];
    float RQD[10];
    std::string UCS_str[10];
    std::string RQD_str[10];
public:
    int single;
    DrillHole(const char *);
    int Lithology();
    int Property();
    int Caption();
    int drawHole();
protected:
    void paintGL();
};

#endif // DRILLHOLE_H
