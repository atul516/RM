#ifndef DRAWHOLE_H
#define DRAWHOLE_H

#include <sstream>
#include "hole.h"

class DrawHole : public GLWidget{
private:
    std::vector< std::vector< std::string > > spcf;
    std::vector< std::vector< std::string > > hole_info;
    std::vector< Hole > holes;
    std::map< std::string, GLuint > textures;
    ImageLoader *imageloader;
    int which_hole;
    std::stringstream label;
    int single;
    QFont f;
    std::string property_name[10];
    std::string property_type[10];
    std::string property_unit[10];
    int no_of_holes;
    int no_of_properties;
    std::vector<double> temp;
    float display_width;
public:
    DrawHole(const char *, const char *);
    int Lithology();
    int Property();
    int Caption();
    int drawHole();
    std::vector< coordinates > getHoleCoordinates();
    std::vector< std::vector< double > > getSeamCoordinates();
    std::vector< double > getHoleDepths();
    void setDisplayType(int);
    void setHoleParams();
    void setTextures();
    void setHole(int);
    bool isSingle();
    int getHoleCount();
    void displayError(const char*);
protected:
    void paintGL();
};

#endif // DRAWHOLE_H
