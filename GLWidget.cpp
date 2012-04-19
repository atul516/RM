#include <QtGui/QMouseEvent>
#include <QTimer>
#include <QObject>
#include <QImage>
#include <GLWidget.h>
//const double BOX_SIZE = 7.0f; //The length of each side of the cube

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent){
    GLWidget::m_timer = new QTimer(this);
    QObject::connect(GLWidget::m_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()),Qt::QueuedConnection);
    setMouseTracking(true);
    setWindowTitle("Borehole");
    this->angle_x = 0.0;
    this->angle_y = 0.0;
    depth = -24.0f;
    left = -7.0f;
    top = 6.0f;
}

void GLWidget::timeOutSlot(){
    this->angle_x += 3.0f;
    if (this->angle_x > 360) {
        this->angle_x -= 360;
    }
    this->updateGL();
    this->update();
}

void GLWidget::timeout(){
}

void GLWidget::updateGL(){
    glDraw();
}

void GLWidget::initializeGL(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading

    /*for(int i=0; i<6; i++){
        char s1[12];
        sprintf(s1, "%d", i+1);
        std::string s = "tex" + (std::string)s1 + ".bmp";
        Image* image = loadBMP(s.c_str());
        _textureId[i] = loadTexture(image);
        delete image;
    }*/
}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}

void GLWidget::drawCube(){
    /*std::vector< std::vector<std::string> > spcf;
    spcf = parseData("hole.csv");
    QFont f;
    QString str;
    double depth[6];
    std::string name[10];
    std::string UCS[10];
    std::string RQD[10];

    for(int i=0;i<6;i++){
        depth[i] = atof(spcf[0][i].c_str());
        name[i] = spcf[1][i];
        if(name[i].compare("water") == 0){
            _textureId[i] = _Water;
        }
        else if(name[i].compare("sandstone")== 0){
            _textureId[i] = _Sandstone;
        }
        else if(name[i].compare("marble")== 0){
            _textureId[i] = _Marble;
        }
        else if(name[i].compare("shale")== 0){
            _textureId[i] = _Shale;
        }
        else if(name[i].compare("coal")== 0){
            _textureId[i] = _Coal;
        }
        else{
            _textureId[i] = _Tex;
        }

        if(spcf[2][i].compare("!") == 0){
            UCS[i] = "";
        }
        else{
            UCS[i] = "    UCS = " + spcf[2][i] + "MPa";
        }

        if(spcf[3][i].compare("!") == 0){
            RQD[i] = "";
        }
        else{
            RQD[i] = "    RQD = " + spcf[3][i];
        }
    }
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
    // Front Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _textureId[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _textureId[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Top Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _textureId[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Bottom Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _textureId[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Right face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
    glEnd();

    glBindTexture(GL_TEXTURE_2D, _textureId[5]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Left Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glEnd();
    glDisable(GL_TEXTURE_2D);*/
}

void getSpecifications(){
}

void GLWidget::wheelEvent(QWheelEvent *e){
    int numDegrees = e->delta() / 8;
    int numSteps = numDegrees / 15;

    /*if (event->orientation() == Qt::Horizontal) {
             scrollHorizontally(numSteps);
         } else {
             scrollVertically(numSteps);
         }*/
    this->depth = this->depth + numSteps/8.0;
    this->left = this->left + numSteps/18.0;
    this->top = this->top - numSteps/20.0;
    this->updateGL();
    this->update();
    e->accept();
}

void GLWidget::mouseMoveEvent(QMouseEvent *e){
    if(e->buttons() & Qt::LeftButton)
    {
        if(dragging == true){
            this->angle_x += (e->pos().x() - drag_x_origin)/150.0f;
            this->angle_y += (e->pos().y() - drag_y_origin)/150.0f;
            updateGL();
        }
        e->accept();
    } else {
        e->ignore();
    }
}

void GLWidget::mousePressEvent(QMouseEvent *e){
    if(e->buttons() & Qt::LeftButton){
        dragging = true;
        drag_x_origin = e->pos().x();
        drag_y_origin = e->pos().y();
        e->accept();
    }
    else{
        dragging = false;
        e->ignore();
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *e){
    if(e->buttons() & Qt::LeftButton)
    {
        dragging = false;
        e->accept();
    }
}

void GLWidget::keyPressEvent(QKeyEvent* event){
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        event->ignore();
        break;
    }
}
