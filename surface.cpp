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

void Surface::setSeamCoordinates(std::vector< std::vector< double > > s){
    this->seam_coordinates = s;
    this->show_holes = true;
}

void Surface::setHoleDepths(std::vector< double > d){
    this->hole_depths = d;
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

void Surface::computeSurfaceNodes(){
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
        this->surface_nodes.push_back(temp);
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

void Surface::setHighLow(){
    double min = this->holes_coordinates[0].z;
    double max = this->holes_coordinates[0].z;
    for(int i=1;i<this->holes_coordinates.size();i++){
        if(this->holes_coordinates[i].y < min)
            min = this->holes_coordinates[i].z;
        if(this->holes_coordinates[i].y > max)
            max = this->holes_coordinates[i].z;
    }
    this->highest = max;
    this->lowest = min;
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
    glTranslatef(this->left, this->top, this->depth);           // Translation fix
    glRotatef(this->angle_y,1.0f,0.0f,0.0f);                     // Rotate On The X Axis
    //glRotatef(this->angle_x,0.0f,1.0f,0.0f);                     // Rotate On The Y Axis
    glRotatef(this->angle_x,0.0f,0.0f,1.0f);                     // Rotate On The Z Axis
    //glScalef(2.0f, 2.0f, 2.0f); //Scale by 0.7 in the x, y, and z directions
    //swapBuffers();
    //GLWidget::m_timer->start(100);
    this->drawSurface();
}

void Surface::drawSurface(){
    float red = 0.0f;
    float blue = 0.0f;
    float green = 1.0f;
    QFont f;
    //Draw X-Axis
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z);
    glVertex3f(this->surface_nodes[0][0].x + this->rightX - this->leftX,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z);
    glEnd();
    renderText(this->surface_nodes[0][0].x + this->rightX - this->leftX,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z, QString("X-Axis"),f);
    //Draw Y-Axis
    glBegin(GL_LINES);
    glVertex3f(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z);
    glVertex3f(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y + this->topY - this->bottomY,this->surface_nodes[0][0].z);
    glEnd();
    renderText(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y + this->topY - this->bottomY,this->surface_nodes[0][0].z, QString("Y-Axis"),f);
    //Draw Z-Axis
    glBegin(GL_LINES);
    glVertex3f(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z);
    glVertex3f(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z + this->highest - this->lowest);
    glEnd();
    renderText(this->surface_nodes[0][0].x,this->surface_nodes[0][0].y,this->surface_nodes[0][0].z + this->highest - this->lowest, QString("Z-Axis"),f);
    if(this->show_holes)
        this->drawHolesUnderSurface();
    glColor3f(1.0f,1.0f,1.0f);
    for(int i=0;i<this->division_factor;i++){
        for(int j=0;j<this->division_factor;j++){
            if(this->getSurfaceType() == 0)
                glBegin(GL_LINE_STRIP);
            else
                glBegin(GL_QUAD_STRIP);
            red = (this->surface_nodes[i][j].z/this->highest > 0) ? (1.0f * (this->surface_nodes[i][j].z/this->highest)) : 0.0f;
            blue = ((this->surface_nodes[i][j].z)/this->lowest > 0) ? (1.0f * (this->surface_nodes[i][j].z/this->lowest)) : 0.0f;
            glColor3f(red,green,blue);
            //glTexCoord2f(0.0f, 0.0f);
            glVertex3f(this->surface_nodes[i][j].x,this->surface_nodes[i][j].y,this->surface_nodes[i][j].z);
            //glTexCoord2f(1.0f, 0.0f);
            glVertex3f(this->surface_nodes[i][j+1].x,this->surface_nodes[i][j+1].y,this->surface_nodes[i][j+1].z);
            //glTexCoord2f(1.0f, 1.0f);
            glVertex3f(this->surface_nodes[i+1][j].x,this->surface_nodes[i+1][j].y,this->surface_nodes[i+1][j].z);
            //glTexCoord2f(0.0f, 1.0f);
            glVertex3f(this->surface_nodes[i+1][j+1].x,this->surface_nodes[i+1][j+1].y,this->surface_nodes[i+1][j+1].z);
            glEnd();
        }
    }    
}

void Surface::drawHolesUnderSurface(){
    for(int i=0;i<this->holes_coordinates.size();i++){
        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex3f(this->holes_coordinates[i].x,this->holes_coordinates[i].y,this->holes_coordinates[i].z);
        glVertex3f(this->holes_coordinates[i].x,this->holes_coordinates[i].y,-this->hole_depths[i]);
        glEnd();
        this->drawSeamPatches(i);
    }
}

void Surface::drawSeamPatches(int i){
    int no_of_patches = (this->seam_coordinates[i][1] - this->seam_coordinates[i][0])/0.25;
    double left_point = this->holes_coordinates[i].x - 0.3;
    double right_point = this->holes_coordinates[i].x + 0.3;
    double top_point = this->holes_coordinates[i].y + 0.3;
    double bottom_point = this->holes_coordinates[i].y - 0.3;
    glColor3f(0.0f,0.0f,1.0f);
    for(int j=0;j<no_of_patches;j++){
        glBegin(GL_LINES);
        glVertex3f(left_point,this->holes_coordinates[i].y,-(this->seam_coordinates[i][0] + j*0.25));
        glVertex3f(right_point,this->holes_coordinates[i].y,-(this->seam_coordinates[i][0] + j*0.25));
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(this->holes_coordinates[i].x,top_point,-(this->seam_coordinates[i][0] + j*0.25));
        glVertex3f(this->holes_coordinates[i].x,bottom_point,-(this->seam_coordinates[i][0] + j*0.25));
        glEnd();
    }
}

Surface::Surface(std::vector< coordinates > c, int s){
    this->depth = -84.0f;
    this->left = -14.0f;
    this->top = -2.0f;
    this->holes_coordinates = c;
    this->show_holes = false;
    this->setX();
    this->setY();
    this->setHighLow();
    this->setSurfaceType(s);
}
