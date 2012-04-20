/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Apr 20 05:47:56 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QFrame *frame_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_3;
    QFrame *frame_3;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(370, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(370, 500));
        MainWindow->setMaximumSize(QSize(370, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 91, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 190, 191, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 320, 111, 21));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 40, 351, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 20, 101, 31));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 100, 81, 31));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 80, 85, 31));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 80, 101, 26));
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 110, 93, 26));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 21));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 10, 101, 21));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 111, 21));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 40, 101, 21));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 210, 351, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 61, 20));
        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 10, 51, 21));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 91, 21));
        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 40, 81, 31));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 10, 91, 31));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 60, 81, 31));
        checkBox_3 = new QCheckBox(frame_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 70, 121, 26));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 340, 351, 121));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 40, 101, 21));
        comboBox_3 = new QComboBox(frame_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(110, 40, 85, 31));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 10, 66, 21));
        lineEdit_4 = new QLineEdit(frame_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 10, 51, 21));
        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(250, 10, 91, 31));
        pushButton_6 = new QPushButton(frame_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(260, 60, 81, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Draw Hole:-", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Draw Surface and/or Seam:-", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Draw Contours:-", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Parse Files", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Single Hole", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "All Holes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Holes Data File:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "hole.csv", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Holes Info File:", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("MainWindow", "info.csv", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Precision:", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Surface Type:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "MESH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SOLID", 0, QApplication::UnicodeUTF8)
        );
        pushButton_3->setText(QApplication::translate("MainWindow", "Compute ", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindow", "Display Seam", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Field Function:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Precision:", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Compute", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
