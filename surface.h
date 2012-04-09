#ifndef SURFACE_H
#define SURFACE_H

#include "GLWidget.h"

struct coordinates{
    float x;
    float y;
    float z;
};

class Surface {
private:
    float rightX;
    float topY;
    float bottomY;
    float leftX;
    float meshSize;
    coordinates nodes[];
public:
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
};

#endif // SURFACE_H
