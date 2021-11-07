/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QStackedWidget *MainPanel;
    QWidget *page;
    QPushButton *pushButton_2;
    QLineEdit *txtCantHumanos;
    QPushButton *pushButton;
    QLineEdit *txtcerca;
    QWidget *page_2;
    QRadioButton *radioButton;
    QToolButton *toolButton;
    QWidget *page_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1306, 689);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 391, 271));
        label->setStyleSheet(QString::fromUtf8("image:url(\":/images/picture.jpg\");"));
        MainPanel = new QStackedWidget(centralwidget);
        MainPanel->setObjectName(QString::fromUtf8("MainPanel"));
        MainPanel->setGeometry(QRect(560, 40, 661, 541));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 100, 151, 21));
        txtCantHumanos = new QLineEdit(page);
        txtCantHumanos->setObjectName(QString::fromUtf8("txtCantHumanos"));
        txtCantHumanos->setGeometry(QRect(140, 150, 113, 21));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 150, 80, 21));
        txtcerca = new QLineEdit(page);
        txtcerca->setObjectName(QString::fromUtf8("txtcerca"));
        txtcerca->setGeometry(QRect(130, 100, 113, 21));
        MainPanel->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        radioButton = new QRadioButton(page_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(240, 220, 82, 17));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(240, 320, 25, 19));
        MainPanel->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        MainPanel->addWidget(page_3);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 360, 75, 23));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 440, 75, 23));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 490, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1306, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        MainPanel->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "buscarmas cerca", nullptr));
        txtCantHumanos->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Generar", nullptr));
        txtcerca->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
