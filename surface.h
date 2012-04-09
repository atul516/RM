#ifndef SURFACE_H
#define SURFACE_H

#include "GLWidget.h"

class Surface : public GLWidget{
private:
    float rightX;
    float topY;
    float bottomY;
    float leftX;
    float meshSize;
    std::vector< coordinates > holes_coordinates;
    coordinates nodes[];
public:
    Surface(std::vector< coordinates >);
    void setX(float,float);
    void setY(float,float);
    void setMeshSize(float);
    float getRightX();
    float getTopY();
    float getBottomY();
    float getLeftX();
    float getMeshSize();
    void computeNodes();
    void computeZ(int);
protected:
    void paintGL();
};

#endif // SURFACE_H
