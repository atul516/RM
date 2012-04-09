#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("Resource Modeling");
    ui->checkBox->setCheckable(false);
    ui->checkBox_2->setCheckable(false);
    ui->comboBox->setDisabled(true);
    this->hole = NULL;
    this->surface = NULL;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::changeEvent(QEvent *e){
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked(){
    this->holes_file = ui->lineEdit->text().toStdString();
    this->holes_info_file = ui->lineEdit_2->text().toStdString();
    ui->checkBox->setCheckable(true);
    ui->checkBox_2->setCheckable(true);
    ui->checkBox->setChecked(true);
    this->hole = new DrawHole(this->holes_file.c_str(),this->holes_info_file.c_str());
    this->updateHoles(this->hole->getHoleCount());
    ui->comboBox->setDisabled(false);
}

void MainWindow::on_checkBox_2_stateChanged(int arg1){
    if(!ui->checkBox->isCheckable())
        return;
    if(ui->checkBox_2->isChecked()){
        ui->checkBox->setChecked(false);
        ui->comboBox->setDisabled(true);
    }
    else {
        ui->checkBox->setChecked(true);
        ui->comboBox->setDisabled(false);
    }

}

void MainWindow::on_pushButton_2_clicked(){
    if(this->hole == NULL)
        return;
    if(ui->checkBox->isChecked()){
        this->hole->setHole(ui->comboBox->currentIndex());
    }
    this->hole->show();
}

void MainWindow::on_checkBox_stateChanged(int arg1){
    if(this->hole == NULL)
        return;
    if(ui->checkBox->isChecked()){
        ui->comboBox->setDisabled(false);
        ui->checkBox_2->setChecked(false);
        this->hole->setDisplayType(1);
    }
    else {
        ui->checkBox_2->setChecked(true);
        ui->comboBox->setDisabled(true);
        this->hole->setDisplayType(0);
    }
}

std::string append_number(std::string const& x, unsigned int num){
    std::stringstream s;
    s << x << num;
    return s.str();
}

void MainWindow::updateHoles(int h){
    for(int i=1;i<=h;i++){
        ui->comboBox->addItem(QString(append_number("Hole ",i).c_str()));
    }
}

void MainWindow::on_pushButton_3_clicked(){
    this->ui->pushButton_3->setText(QString("Computing"));
    if(this->hole == NULL)
        return;
    this->surface = new Surface(this->hole->getHoleCoordinates());
    this->surface->setDivisionFactor(atoi(this->ui->lineEdit_3->text().toStdString().c_str()));
    this->surface->computeNodes();
    this->ui->pushButton_3->setText(QString("Compute"));
}

void MainWindow::on_pushButton_4_clicked(){
    if(this->surface == NULL)
        return;
    this->surface->show();
}
