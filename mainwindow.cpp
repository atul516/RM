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
    this->hole = new DrillHole(ui->lineEdit->text().toStdString().c_str());
    ui->checkBox->setCheckable(true);
    ui->checkBox_2->setCheckable(true);
    ui->checkBox_2->setChecked(true);
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(this->hole != NULL){

        if(ui->checkBox_2->isChecked()){
            this->hole->single = 0;
            ui->checkBox->setChecked(false);
        }
        else {
            this->hole->single = 1;
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
            this->hole->single = 1;
            ui->checkBox_2->setChecked(false);
        }
        else {
            this->hole->single = 0;
            ui->checkBox_2->setChecked(true);
        }
    }
}
