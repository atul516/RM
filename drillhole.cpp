#include "drillhole.h"
#include <stdio.h>
#include"parseCSV.h"

int DrillHole::drawHole(){
    this->image = new ImageLoader();
    for(int i=0;i<6;i++){
        temp[i] = atof(spcf[0][i].c_str());
        name[i] = spcf[1][i];
        if(name[i].compare("water") == 0){
            this->textureId[i] = this->image->Water;
        }
        else if(name[i].compare("sandstone")== 0){
            this->textureId[i] = this->image->Sandstone;
        }
        else if(name[i].compare("marble")== 0){
            this->textureId[i] = this->image->Marble;
        }
        else if(name[i].compare("shale")== 0){
            this->textureId[i] = this->image->Shale;
        }
        else if(name[i].compare("coal")== 0){
            this->textureId[i] = this->image->Coal;
        }
        else{
            this->textureId[i] = this->image->Tex;
        }

        if(spcf[2][i].compare("!") == 0){
            UCS[i] = 0.0f;
        }
        else{
            UCS[i] = atof(spcf[2][i].c_str());
            UCS_str[i] = spcf[2][i].c_str();
        }

        if(spcf[3][i].compare("!") == 0){
            RQD[i] = 0.0f;
        }
        else{
            RQD[i] = atof(spcf[3][i].c_str());
            RQD_str[i] = spcf[3][i].c_str();
        }
    }
    for(int i=0;i<6;i++){
        if(i!=0)
            texture_depth[i] = (temp[i] - temp[i-1])/REDUCTION_FACTOR;
        else
            texture_depth[i] = temp[i]/REDUCTION_FACTOR;
    }
    if(single == 1)
        this->Caption();
   else
     glTranslatef(17.6f, 2.0f, 0.0f);
    this->Lithology();
    return 1;
}

int DrillHole::Property(){

}

int DrillHole::Caption(){
    glTranslatef(-4.6f, 0.9f, 0.0f);
    hole_id = QString("Hole 1");
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, hole_id,f);
    glTranslatef(0.0f, -0.4f, 0.0f);
    hole_location = QString("Location : xyz");
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, hole_location,f);
    glTranslatef(0.0f, -0.4f, 0.0f);
    hole_direction = QString("Direction : Vertical");
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, hole_direction,f);

    glTranslatef(-0.5f, -0.7f, 0.0f);

    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 25.0f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 25.0f, -0.02f, DISPLAY_HEIGHT);
    glVertex3f(0.0f,-0.02f, DISPLAY_HEIGHT);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 0.02f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 0.02f, -13.0f, DISPLAY_HEIGHT);
    glVertex3f(0.0f, -13.0f, DISPLAY_HEIGHT);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(8.00f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 8.02f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 8.02f, -13.0f, DISPLAY_HEIGHT);
    glVertex3f(8.00f, -13.0f, DISPLAY_HEIGHT);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(14.00f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 14.02f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 14.02f, -13.0f, DISPLAY_HEIGHT);
    glVertex3f(14.00f, -13.0f, DISPLAY_HEIGHT);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(20.00f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 20.02f, 0.0f, DISPLAY_HEIGHT);
    glVertex3f( 20.02f, -13.0f, DISPLAY_HEIGHT);
    glVertex3f(20.00f, -13.0f, DISPLAY_HEIGHT);
    glEnd();

    glTranslatef(0.5f, 0.7f, 0.0f);

    glTranslatef(5.0f, -0.4f, 0.0f);
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString("Material Type"),f);
    glTranslatef(3.0f, 0.0f, 0.0f);
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString("UCS (in MPa)"),f);
    glTranslatef(6.0f, 0.0f, 0.0f);
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString("RQD index"),f);
    glTranslatef(6.0f, 0.0f, 0.0f);
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString("Rock Hardness"),f);
}

int DrillHole::Lithology(){
    glTranslatef(-17.6f, -2.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    for(int i=0;i<spcf[0].size();i++){
        if(i!=0){
            glTranslatef(0.0f, -(texture_depth[i-1]/2)-(texture_depth[i]/2), 0.0f);
        }

        glBindTexture(GL_TEXTURE_2D, textureId[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-DISPLAY_WIDTH, -texture_depth[i]/2, DISPLAY_HEIGHT);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(DISPLAY_WIDTH, -texture_depth[i]/2, DISPLAY_HEIGHT);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(DISPLAY_WIDTH, texture_depth[i]/2, DISPLAY_HEIGHT);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-DISPLAY_WIDTH, texture_depth[i]/2, DISPLAY_HEIGHT);
        glEnd();
        str = QString(name[i].c_str());
        renderText(2.8f, 0.0f, DISPLAY_HEIGHT, str,f);
        if(single == 1){
            glTranslatef(5.1f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f(0.0f, -0.1f, DISPLAY_HEIGHT);
            glVertex3f( (UCS[i]/100.0)*5.0f, -0.1f, DISPLAY_HEIGHT);
            glVertex3f( (UCS[i]/100.0)*5.0f,0.1f, DISPLAY_HEIGHT);
            glVertex3f(0.0f,0.1f, DISPLAY_HEIGHT);
            glEnd();
            renderText((UCS[i]/100.0)*5.0f, 0.0f, DISPLAY_HEIGHT, UCS_str[i].c_str(),f);

            glTranslatef(6.0f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f(0.0f, -0.1f, DISPLAY_HEIGHT);
            glVertex3f( (RQD[i]/100.0)*5.0f, -0.1f, DISPLAY_HEIGHT);
            glVertex3f( (RQD[i]/100.0)*5.0f,0.1f, DISPLAY_HEIGHT);
            glVertex3f(0.0f,0.1f, DISPLAY_HEIGHT);
            glEnd();
            renderText((RQD[i]/100.0)*5.0f, 0.0f, DISPLAY_HEIGHT, RQD_str[i].c_str(),f);
            glTranslatef(-11.1f, 0.0f, 0.0f);
        }
    }
    glDisable(GL_TEXTURE_2D);
}

void DrillHole::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //glRotatef(_angle,0.0f,1.0f,0.0f);                     // Rotate On The Y Axis
    // glScalef(2.0f, 2.0f, 2.0f); //Scale by 0.7 in the x, y, and z directions
    glLoadIdentity();
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat lightColor[] = {DISPLAY_WIDTH, DISPLAY_WIDTH, DISPLAY_WIDTH, 1.0f};
    GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glTranslatef(this->left, this->top, this->depth);
    //DrillHole h;
    this->drawHole();
    /*
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -14.0f);
    glPushMatrix();
    glRotatef(this->angle,1.0f,0.0f,0.0f);                     // Rotate On The X Axis
   glRotatef(this->angle,0.0f,1.0f,0.0f);                     // Rotate On The Y Axis
    //glRotatef(this->angle,0.0f,0.0f,1.0f);                     // Rotate On The Z Axis
    glScalef(2.0f, 2.0f, 2.0f); //Scale by 0.7 in the x, y, and z directions
    drawCube();
    swapBuffers();
   GLWidget::m_timer->start(100);
   */
}
DrillHole::DrillHole(const char *filenm){
    //std::cout<<filenm;
    this->spcf = parseData(filenm);
}
