#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#include "imageloader.h"

struct coordinates{
    double x;
    double y;
    double z;
};

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    GLWidget(QWidget *parent = NULL);
    void updateGL();

protected:
    GLdouble angle_x;
    GLdouble angle_y;
    double depth;
    double left;
    double top;
    bool dragging;
    bool rotate;
    bool speed_zoom;
    double drag_x_origin;
    double drag_y_origin;
    double drag_x_end;
    double drag_y_end;
    void initializeGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void timeout();
    void drawCube();
    QTimer *m_timer;
protected slots:
  void timeOutSlot();
private:
};

#endif  /* _GLWIDGET_H */
