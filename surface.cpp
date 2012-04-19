#include "surface.h"
#include <iostream>
void Surface::setX(){
    double min = this->holes_coordinates[0].x;
    double max = this->holes_coordinates[0].x;
    for(int i=1;i<this->holes_coordinates.size();i++){
        if(this->holes_coordinates[i].x < min)
            min = this->holes_coordinates[i].x;
        if(this->holes_coordinates[i].x > max)
            max = this->holes_coordinates[i].x;
    }
    this->leftX = min;
    this->rightX = max;
}

void Surface::setY(){
    double min = this->holes_coordinates[0].y;
    double max = this->holes_coordinates[0].y;
    for(int i=1;i<this->holes_coordinates.size();i++){
        if(this->holes_coordinates[i].y < min)
            min = this->holes_coordinates[i].y;
        if(this->holes_coordinates[i].y > max)
            max = this->holes_coordinates[i].y;
    }
    this->bottomY = min;
    this->topY = max;
}

void Surface::setDivisionFactor(int a){
    this->division_factor = a;
}

void Surface::setSurfaceType(int s){
    this->surface_type = s;
}

double Surface::getRightX(){
    return this->rightX;
}

double Surface::getTopY(){
    return this->topY;
}

double Surface::getBottomY(){
    return this->bottomY;
}

double Surface::getLeftX(){
    return this->leftX;
}

int Surface::getDivisionFactor(){
    return this->division_factor;
}

int Surface::getSurfaceType(){
    return this->surface_type;
}

void Surface::computeNodes(){
    //std::cout << this->getRightX() << " " << this->getLeftX() << "\n";
    //std::cout << this->getTopY() << " " << this->getBottomY();
    double width = this->getRightX() - this->getLeftX();
    double height = this->getTopY() - this->getBottomY();
    double nodew = width/this->division_factor;
    double nodeh = height/this->division_factor;
    std::vector< coordinates > temp;
    coordinates temp1;

    for(int i=0;i<=this->division_factor;i++){
        for(int j=0;j<=this->division_factor;j++){
            temp1.x = this->getLeftX() + (j*nodew);
            temp1.y = this->getBottomY() + (i*nodeh);
            temp1.z = this->computeZ(temp1.x,temp1.y);
            temp.push_back(temp1);
        }
        this->nodes.push_back(temp);
        temp.clear();
    }
}

double Surface::computeZ(double x, double y){
    double sum_rl_by_r = 0.0;
    double sum_one_by_r = 0.0;
    for(int i=0;i<this->holes_coordinates.size();i++){
        if(x == this->holes_coordinates[i].x && y == this->holes_coordinates[i].y)
            return this->holes_coordinates[i].z;
        sum_one_by_r += 1/(pow((x-this->holes_coordinates[i].x),2)+pow((y-this->holes_coordinates[i].y),2));
        sum_rl_by_r += (this->holes_coordinates[i].z)/(pow((x-this->holes_coordinates[i].x),2)+pow((y-this->holes_coordinates[i].y),2));
    }
    return (sum_rl_by_r/sum_one_by_r);
}

void Surface::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    GLfloat lightColor[] = {DISPLAY_WIDTH, DISPLAY_WIDTH, DISPLAY_WIDTH, 1.0f};
    GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glTranslatef(-15.0f, -5.0f, this->depth - 30.0f);
    glRotatef(this->angle_y,1.0f,0.0f,0.0f);                     // Rotate On The X Axis
    glRotatef(this->angle_x,0.0f,1.0f,0.0f);                     // Rotate On The Y Axis
    //glRotatef(this->angle,0.0f,0.0f,1.0f);                     // Rotate On The Z Axis
    //glScalef(2.0f, 2.0f, 2.0f); //Scale by 0.7 in the x, y, and z directions
    //swapBuffers();
    //GLWidget::m_timer->start(100);
    this->drawSurface();
}

void Surface::drawSurface(){
    for(int i=0;i<this->division_factor;i++){
        for(int j=0;j<this->division_factor;j++){
            if(this->getSurfaceType() == 0)
                glBegin(GL_LINE_STRIP);
            else
                glBegin(GL_QUAD_STRIP);
            //glTexCoord2f(0.0f, 0.0f);
            glVertex3f(this->nodes[i][j].x,this->nodes[i][j].y,this->nodes[i][j].z);
            //glTexCoord2f(1.0f, 0.0f);
            glVertex3f(this->nodes[i][j+1].x,this->nodes[i][j+1].y,this->nodes[i][j+1].z);
            //glTexCoord2f(1.0f, 1.0f);
            glVertex3f(this->nodes[i+1][j].x,this->nodes[i+1][j].y,this->nodes[i+1][j].z);
            //glTexCoord2f(0.0f, 1.0f);
            glVertex3f(this->nodes[i+1][j+1].x,this->nodes[i+1][j+1].y,this->nodes[i+1][j+1].z);
            glEnd();
        }
    }
}

Surface::Surface(std::vector< coordinates > c, int s){
    this->holes_coordinates = c;
    this->setX();
    this->setY();
    this->setSurfaceType(s);
}
