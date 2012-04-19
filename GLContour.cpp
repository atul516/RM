// GLContour.cpp: implementation of the CGLContour class.
//
//////////////////////////////////////////////////////////////////////

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "GLContour.h"

std::vector< coordinates > holes_coordinates;

double computeZ(double x, double y){
    double sum_rl_by_r = 0.0;
    double sum_one_by_r = 0.0;
    for(int i=0;i<holes_coordinates.size();i++){
        if(x == holes_coordinates[i].x && y == holes_coordinates[i].y)
            return holes_coordinates[i].z;
        sum_one_by_r += 1/(pow((x-holes_coordinates[i].x),2)+pow((y-holes_coordinates[i].y),2));
        sum_rl_by_r += (holes_coordinates[i].z)/(pow((x-holes_coordinates[i].x),2)+pow((y-holes_coordinates[i].y),2));
    }
    return (sum_rl_by_r/sum_one_by_r);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGLContour::CGLContour(std::vector< coordinates > holes)
    : CContour(){
    holes_coordinates = holes;
    this->SetFieldFcn(computeZ);
    std::vector< double > vPlanes;
    int np=100;
    vPlanes.resize(np);
    for (int i=0;i<np;i++)
    {
        vPlanes[i]=(i-(double)np/2.0) / ((double)np/2.0) *2.0;
    }
    this->SetPlanes(vPlanes);
    this->setX();
    this->setY();
    double limits[4];
    limits[0] = this->leftX;
    limits[1] = this->rightX;
    limits[2] = this->bottomY;
    limits[3] = this->topY;
    this->SetLimits(limits);
}

CGLContour::~CGLContour(){

}

void CGLContour::setX(){
    double min = holes_coordinates[0].x;
    double max = holes_coordinates[0].x;
    for(int i=1;i<holes_coordinates.size();i++){
        if(holes_coordinates[i].x < min)
            min = holes_coordinates[i].x;
        if(holes_coordinates[i].x > max)
            max = holes_coordinates[i].x;
    }
    this->leftX = min;
    this->rightX = max;
}

void CGLContour::setY(){
    double min = holes_coordinates[0].y;
    double max = holes_coordinates[0].y;
    for(int i=1;i<holes_coordinates.size();i++){
        if(holes_coordinates[i].y < min)
            min = holes_coordinates[i].y;
        if(holes_coordinates[i].y > max)
            max = holes_coordinates[i].y;
    }
    this->bottomY = min;
    this->topY = max;
}

void CGLContour::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    GLfloat lightColor[] = {DISPLAY_WIDTH, DISPLAY_WIDTH, DISPLAY_WIDTH, 1.0f};
    GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glTranslatef(-15.0f, -5.0f, this->depth - 10.0f);
    this->Generate();
}
