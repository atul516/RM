#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drillhole.h"

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

private:
    Ui::MainWindow *ui;
    DrillHole *hole;
};

#endif // MAINWINDOW_H
