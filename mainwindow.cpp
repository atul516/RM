#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setCheckable(false);
    ui->checkBox_2->setCheckable(false);
    this->hole = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->holes_file = ui->lineEdit->text().toStdString();
    this->holes_info_file = ui->lineEdit_2->text().toStdString();
    ui->checkBox->setCheckable(true);
    ui->checkBox_2->setCheckable(true);
    ui->checkBox_2->setChecked(true);
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(ui->checkBox->isCheckable()){
        if(ui->checkBox_2->isChecked()){
            this->hole = new DrillHole(this->holes_file.c_str(),this->holes_info_file.c_str(),0);
            ui->checkBox->setChecked(false);
        }
        else {
            this->hole = new DrillHole(this->holes_file.c_str(),this->holes_info_file.c_str(),1);
            ui->checkBox->setChecked(true);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(this->hole != NULL){
        this->hole->show();
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(this->hole != NULL){
        if(ui->checkBox->isChecked()){
            this->hole->setDisplayType(1);
            ui->checkBox_2->setChecked(false);
        }
        else {
            this->hole->setDisplayType(0);
            ui->checkBox_2->setChecked(true);
        }
    }
}
