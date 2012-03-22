#include "drawhole.h"
#include <stdio.h>
#include"parseCSV.h"

int DrawHole::drawHole(){
    this->setTextures();
    if(isSingle())
        this->Caption();
    else
        glTranslatef(17.6f, 2.0f, 0.0f);
    //this->Lithology();
    return 1;
}

void DrawHole::displayError(const char* s){

}

void DrawHole::setHoleParams(){
    /*
     * Extract hole properties for all holes
     */
    std::string sep("#"); // Separater used in the input file
    if(spcf[0][0].compare("@format") != 0)
        displayError("File format incorrect!!!");

    // Start extracting the format of hole property info
    int i=1;
    while(spcf[i][0].compare(sep) != 0){
        property_name[i-1] = spcf[i][0];
        property_type[i-1] = spcf[i][1];
        property_unit[i-1] = spcf[i][2];
        i++;
    }
    // Start extracting from hole material properties
    Hole *h = new Hole();
    no_of_properties = i-1;
    std::vector< std::string > property;
    no_of_holes = 0;
    int property_counter = 0;
    i++;
    while(i<((int)this->spcf.size())){
        if(spcf[i][0].compare(sep) == 0){
            no_of_holes++;
            property_counter = 0;
            i++;
            for(int c=0;c<temp.size();c++){
                if(c!=0)
                    h->material_depth.push_back((temp[c] - temp[c-1])/REDUCTION_FACTOR);
                else
                    h->material_depth.push_back(temp[c]/REDUCTION_FACTOR);
            }
            this->holes.push_back(*h);
            temp.clear();
            property.clear();
            h = NULL;
            h = new Hole();
            continue;
        }
        for(int k=0;k<((int)this->spcf[i].size());k++){
            if(property_counter == 0)
                temp.push_back(atof(spcf[i][k].c_str()));
            else if(property_counter == 1)
                h->material_name.push_back(spcf[i][k]);
            else
                property.push_back(spcf[i][k]);

        }
        if(property_counter > 1)
            h->other_material_properties.push_back(property);
        property_counter++;
        i++;
    }

    //start extracting hole id,length,dip etc.
    i=0;
    while(i<((int)this->hole_info.size())){
        this->holes[i].setHoleId(this->hole_info[i][0].c_str());
        this->holes[i].setHoleLength(atof(this->hole_info[i][1].c_str()));
        this->holes[i].setHoleDip(atof(this->hole_info[i][2].c_str()));
        i++;
    }
} // Done extracting hole properties

void DrawHole::setTextures(){
    /*
     * Load all available texture bitmaps
     */
    this->image = new ImageLoader();
    std::string name;
    for(int i=0;i<((int)this->spcf[0].size());i++){
        name = spcf[1][i];
        if(name.compare("water") == 0){
            this->textureId[i] = this->image->Water;
        }
        else if(name.compare("sandstone")== 0){
            this->textureId[i] = this->image->Sandstone;
        }
        else if(name.compare("marble")== 0){
            this->textureId[i] = this->image->Marble;
        }
        else if(name.compare("shale")== 0){
            this->textureId[i] = this->image->Shale;
        }
        else if(name.compare("coal")== 0){
            this->textureId[i] = this->image->Coal;
        }
        else{
            this->textureId[i] = this->image->Tex;
        }
        textures.insert ( std::pair<std::string,GLuint>(name,textureId[i]) ); // Insert texture to the texture map
    }
} // Done loading textures

int DrawHole::Caption(){
    /*
     * Draw Hole Caption in case of single hole
     */
    if(!isSingle())
        return 0;
    // Display Hole Imformation
    glTranslatef(-4.6f, 0.9f, 0.0f);
    label.str(std::string());
    label << "Hole Id : " << this->holes[which_hole].getHoleId().c_str();
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString(label.str().c_str()),f);
    glTranslatef(0.0f, -0.4f, 0.0f);
    label.str(std::string());
    label << "Length : " << this->holes[which_hole].getHoleLength();
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString(label.str().c_str()),f);
    glTranslatef(0.0f, -0.4f, 0.0f);
    label.str(std::string());
    label << "Dip : " << this->holes[which_hole].getHoleDip();
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString(label.str().c_str()),f);
    label.str(std::string());

    glTranslatef(-0.5f, -0.7f, 0.0f);

    // Draw different display blocks
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
    glTranslatef(8.0f, 0.0f, 0.0f);
    for(int i=2;i<no_of_properties;i++){
        glBegin(GL_QUADS);
        glVertex3f(0.00f, 0.0f, DISPLAY_HEIGHT);
        glVertex3f( 0.02f, 0.0f, DISPLAY_HEIGHT);
        glVertex3f( 0.02f, -13.0f, DISPLAY_HEIGHT);
        glVertex3f(0.00f, -13.0f, DISPLAY_HEIGHT);
        glEnd();
        glTranslatef(6.0f, 0.0f, 0.0f);
    }
    glTranslatef(0.5f, 0.7f, 0.0f);
    glTranslatef(-(8.0f + (no_of_properties-2)*6.0f), 0.0f, 0.0f);

    // Display hole properties' names and units
    glTranslatef(5.0f, -0.4f, 0.0f);
    label.str(std::string());
    label << "Material Type";
    renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString(""),f);
    glTranslatef(3.0f, 0.0f, 0.0f);
    for(int i=2;i<no_of_properties;i++){
        label.str(std::string());
        label << property_name[i] << " (in " << property_unit[i] << ")";
        renderText(0.0f, 0.0f, DISPLAY_HEIGHT, QString(label.str().c_str()),f);
        glTranslatef(6.0f, 0.0f, 0.0f);
    }
    return 1;
} // Done drawing caption
/*
int DrawHole::Lithology(){
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
        if(isSingle()){
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
*/
void DrawHole::paintGL() {
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
    //DrawHole h;
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

DrawHole::DrawHole(const char* holes_file, const char* holes_info_file){
    this->spcf = parseData(holes_file);
    this->hole_info = parseData(holes_info_file);
    this->setHoleParams();
    this->setDisplayType(1);
    this->setHole(0);
}

void DrawHole::setDisplayType(int t){
    this->single = t;
}

bool DrawHole::isSingle(){
    return this->single;
}

void DrawHole::setHole(int h){
    if(isSingle())
        which_hole = h;
}

int DrawHole::getHoleCount(){
    return no_of_holes;
}