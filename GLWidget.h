#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QtCore>
#include "params.h"
class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    GLWidget(QWidget *parent = NULL);
    void updateGL();

protected:
    float angle;
    float depth;
    float left;
    float top;
    //int dragging;
    //float drag_x_origin;
    //float drag_y_origin;
    //float drag_x_end;
    //float drag_y_end;
    void initializeGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void timeout();
    void drawCube();
protected slots:
  void timeOutSlot();
private:
    QTimer *m_timer;
};

#endif  /* _GLWIDGET_H */
