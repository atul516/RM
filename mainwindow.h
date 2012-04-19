#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "surface.h"
#include "drawhole.h"
#include "GLContour.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_checkBox_2_stateChanged(int arg1);
    void on_pushButton_2_clicked();
    void on_checkBox_stateChanged(int arg1);
    void updateHoles(int);
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    DrawHole *hole;
    CGLContour *contour;
    Surface *surface;
    std::string holes_file;
    std::string holes_info_file;
};

#endif // MAINWINDOW_H
