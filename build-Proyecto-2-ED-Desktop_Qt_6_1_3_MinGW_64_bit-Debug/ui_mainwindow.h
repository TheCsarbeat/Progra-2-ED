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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *mainPanel;
    QWidget *pageCrearHumano;
    QPushButton *pushButton_2;
    QLineEdit *txtcerca;
    QLineEdit *txtCantHumanos_2;
    QFrame *frame_12;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *txtCantHumanos;
    QPushButton *btnCrearHumanos;
    QLabel *label_8;
    QFrame *frame_13;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *txtBuscar;
    QLabel *label_11;
    QPushButton *btnBuscarPersona;
    QScrollArea *scrollDatosWorld;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *lbDatosWorld;
    QFrame *frame_15;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *btnPecar;
    QWidget *pageCielo;
    QPushButton *botonBAFamilias;
    QLineEdit *txtIdBuenasAcciones;
    QLabel *idBuenasAcciones;
    QFrame *frameAngeles;
    QLabel *labelAngeles;
    QPushButton *botonNuriel;
    QPushButton *botonMiguel;
    QPushButton *botonAniel;
    QPushButton *botonRaguel;
    QPushButton *botonAzrael;
    QPushButton *botonRafael;
    QPushButton *botonUriel;
    QPushButton *botonSariel;
    QPushButton *botonShamsiel;
    QPushButton *botonGabriel;
    QFrame *frame_14;
    QLabel *label_13;
    QPushButton *botonMapaBueno;
    QPushButton *botonTopBA;
    QPushButton *botonPaisMenosMalos;
    QLineEdit *txtCantHumanos_4;
    QLabel *label_12;
    QLabel *label_14;
    QStackedWidget *panelConsultasCieloBuenasAcciones;
    QWidget *page_3;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QWidget *page_4;
    QWidget *pageInfierno;
    QLabel *idPecados;
    QLineEdit *txtPecados;
    QPushButton *pushButton_3;
    QPushButton *botonTopPecados;
    QPushButton *botonPaisMenosMalos_2;
    QPushButton *botonmapaMalo;
    QFrame *frameDemonios;
    QPushButton *botonMammon;
    QLabel *codicia;
    QLabel *labelDemonios;
    QPushButton *botonLucifer;
    QPushButton *botonBelcebu;
    QPushButton *botonSatan;
    QPushButton *botonAbandon;
    QPushButton *botonBelfegor;
    QPushButton *botonAsmodeo;
    QLabel *orgullo;
    QLabel *envidia;
    QLabel *pereza;
    QLabel *ira;
    QLabel *glotoneria;
    QLabel *lujuria;
    QLabel *label_3;
    QWidget *pageConsultas;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QStackedWidget *panelConsultas;
    QWidget *page;
    QScrollArea *scrollConsultaBueno;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *labelListadoBuenos;
    QScrollArea *scrollConsultaPecado;
    QWidget *scrollAreaWidgetContents;
    QLabel *labelListadoPecador;
    QWidget *page_2;
    QWidget *pageConsultas2;
    QLabel *labelApellidoPais;
    QLineEdit *lineEdit;
    QScrollArea *scrollEstadoHumanos;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *labelIngresarFam;
    QLabel *label_6;
    QWidget *pageGanador;
    QFrame *frameGanadorCielo;
    QLabel *cantPecadosCielo;
    QLabel *imprimirCantPecadosCielo;
    QLabel *cantAccionesBuenasCielo;
    QLabel *imprimirCantAccionesBuenasCielo;
    QLabel *netoCielo;
    QLabel *imprimirCantNetoCielo;
    QLabel *infoCielo;
    QFrame *frameGanadorCielo_2;
    QLabel *cantPecadosInfierno;
    QLabel *imprimirCantPecadosInfierno;
    QLabel *cantAccionesBuenasInfierno;
    QLabel *imprimirCantAccionesBuenasInfierno;
    QLabel *netoInfierno;
    QLabel *imprimirCantNetoInfierno;
    QLabel *infoInfierno;
    QFrame *sideBarFrame;
    QPushButton *botonHumanos;
    QPushButton *botonInfierno;
    QPushButton *botonGanador;
    QPushButton *botonConsultas;
    QPushButton *botonConsultas2;
    QPushButton *botonCielo;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1900, 1000);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainPanel = new QStackedWidget(centralwidget);
        mainPanel->setObjectName(QString::fromUtf8("mainPanel"));
        mainPanel->setGeometry(QRect(220, 0, 1671, 1000));
        mainPanel->setStyleSheet(QString::fromUtf8(""));
        pageCrearHumano = new QWidget();
        pageCrearHumano->setObjectName(QString::fromUtf8("pageCrearHumano"));
        pageCrearHumano->setStyleSheet(QString::fromUtf8("background-color:white;"));
        pushButton_2 = new QPushButton(pageCrearHumano);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1260, 30, 161, 51));
        txtcerca = new QLineEdit(pageCrearHumano);
        txtcerca->setObjectName(QString::fromUtf8("txtcerca"));
        txtcerca->setGeometry(QRect(1350, 50, 113, 21));
        txtCantHumanos_2 = new QLineEdit(pageCrearHumano);
        txtCantHumanos_2->setObjectName(QString::fromUtf8("txtCantHumanos_2"));
        txtCantHumanos_2->setGeometry(QRect(1290, 80, 113, 21));
        frame_12 = new QFrame(pageCrearHumano);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(60, 30, 541, 241));
        frame_12->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_12);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 65, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        font.setPointSize(12);
        label_5->setFont(font);
        label_7 = new QLabel(frame_12);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 541, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Doppio One")});
        font1.setPointSize(16);
        font1.setBold(false);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(60, 185, 75);\n"
""));
        txtCantHumanos = new QLineEdit(frame_12);
        txtCantHumanos->setObjectName(QString::fromUtf8("txtCantHumanos"));
        txtCantHumanos->setGeometry(QRect(125, 70, 221, 21));
        txtCantHumanos->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(60, 185, 75);"));
        btnCrearHumanos = new QPushButton(frame_12);
        btnCrearHumanos->setObjectName(QString::fromUtf8("btnCrearHumanos"));
        btnCrearHumanos->setGeometry(QRect(20, 160, 331, 61));
        btnCrearHumanos->setStyleSheet(QString::fromUtf8("\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
"background-color: rgb(60, 185, 75);"));
        label_8 = new QLabel(frame_12);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(400, 40, 111, 111));
        label_8->setStyleSheet(QString::fromUtf8("image:url(\":/images/world.png\");"));
        frame_13 = new QFrame(pageCrearHumano);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(650, 30, 541, 241));
        frame_13->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_13);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 65, 121, 31));
        label_9->setFont(font);
        label_10 = new QLabel(frame_13);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 541, 31));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(60, 185, 75);\n"
""));
        txtBuscar = new QLineEdit(frame_13);
        txtBuscar->setObjectName(QString::fromUtf8("txtBuscar"));
        txtBuscar->setGeometry(QRect(175, 70, 171, 21));
        txtBuscar->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(60, 185, 75);"));
        label_11 = new QLabel(frame_13);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(400, 40, 111, 111));
        label_11->setStyleSheet(QString::fromUtf8("image:url(\":/images/human.png\");"));
        btnBuscarPersona = new QPushButton(frame_13);
        btnBuscarPersona->setObjectName(QString::fromUtf8("btnBuscarPersona"));
        btnBuscarPersona->setGeometry(QRect(10, 150, 351, 61));
        btnBuscarPersona->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
"background-color: rgb(60, 185, 75);"));
        scrollDatosWorld = new QScrollArea(pageCrearHumano);
        scrollDatosWorld->setObjectName(QString::fromUtf8("scrollDatosWorld"));
        scrollDatosWorld->setGeometry(QRect(80, 310, 541, 461));
        scrollDatosWorld->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 539, 459));
        lbDatosWorld = new QLabel(scrollAreaWidgetContents_4);
        lbDatosWorld->setObjectName(QString::fromUtf8("lbDatosWorld"));
        lbDatosWorld->setGeometry(QRect(0, 0, 541, 441));
        lbDatosWorld->setStyleSheet(QString::fromUtf8("font: 12pt \"Open Sans\";"));
        scrollDatosWorld->setWidget(scrollAreaWidgetContents_4);
        frame_15 = new QFrame(pageCrearHumano);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(660, 310, 541, 181));
        frame_15->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(frame_15);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 0, 541, 31));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(60, 185, 75);\n"
""));
        label_22 = new QLabel(frame_15);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(400, 40, 111, 111));
        label_22->setStyleSheet(QString::fromUtf8("image:url(\":/images/human.png\");"));
        btnPecar = new QPushButton(frame_15);
        btnPecar->setObjectName(QString::fromUtf8("btnPecar"));
        btnPecar->setGeometry(QRect(20, 100, 351, 61));
        btnPecar->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
"background-color: rgb(60, 185, 75);"));
        mainPanel->addWidget(pageCrearHumano);
        pageCielo = new QWidget();
        pageCielo->setObjectName(QString::fromUtf8("pageCielo"));
        botonBAFamilias = new QPushButton(pageCielo);
        botonBAFamilias->setObjectName(QString::fromUtf8("botonBAFamilias"));
        botonBAFamilias->setGeometry(QRect(50, 140, 191, 25));
        txtIdBuenasAcciones = new QLineEdit(pageCielo);
        txtIdBuenasAcciones->setObjectName(QString::fromUtf8("txtIdBuenasAcciones"));
        txtIdBuenasAcciones->setGeometry(QRect(370, 90, 113, 24));
        idBuenasAcciones = new QLabel(pageCielo);
        idBuenasAcciones->setObjectName(QString::fromUtf8("idBuenasAcciones"));
        idBuenasAcciones->setGeometry(QRect(380, 60, 91, 16));
        frameAngeles = new QFrame(pageCielo);
        frameAngeles->setObjectName(QString::fromUtf8("frameAngeles"));
        frameAngeles->setGeometry(QRect(50, 190, 761, 551));
        frameAngeles->setFrameShape(QFrame::StyledPanel);
        frameAngeles->setFrameShadow(QFrame::Raised);
        labelAngeles = new QLabel(frameAngeles);
        labelAngeles->setObjectName(QString::fromUtf8("labelAngeles"));
        labelAngeles->setGeometry(QRect(330, 10, 131, 31));
        QFont font2;
        font2.setPointSize(14);
        labelAngeles->setFont(font2);
        botonNuriel = new QPushButton(frameAngeles);
        botonNuriel->setObjectName(QString::fromUtf8("botonNuriel"));
        botonNuriel->setGeometry(QRect(240, 80, 120, 120));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Courier New")});
        font3.setPointSize(14);
        font3.setBold(true);
        botonNuriel->setFont(font3);
        botonNuriel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel2.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonMiguel = new QPushButton(frameAngeles);
        botonMiguel->setObjectName(QString::fromUtf8("botonMiguel"));
        botonMiguel->setGeometry(QRect(50, 80, 120, 120));
        botonMiguel->setFont(font3);
        botonMiguel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel1.png\");\n"
"background-color: white;\n"
"border-radius:15px;\n"
"color: rgb(64, 150, 180);\n"
"text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonAniel = new QPushButton(frameAngeles);
        botonAniel->setObjectName(QString::fromUtf8("botonAniel"));
        botonAniel->setGeometry(QRect(410, 80, 120, 120));
        botonAniel->setFont(font3);
        botonAniel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel3.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonRaguel = new QPushButton(frameAngeles);
        botonRaguel->setObjectName(QString::fromUtf8("botonRaguel"));
        botonRaguel->setGeometry(QRect(60, 410, 120, 120));
        botonRaguel->setFont(font3);
        botonRaguel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel7.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonAzrael = new QPushButton(frameAngeles);
        botonAzrael->setObjectName(QString::fromUtf8("botonAzrael"));
        botonAzrael->setGeometry(QRect(430, 410, 120, 120));
        botonAzrael->setFont(font3);
        botonAzrael->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel9.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonRafael = new QPushButton(frameAngeles);
        botonRafael->setObjectName(QString::fromUtf8("botonRafael"));
        botonRafael->setGeometry(QRect(590, 80, 120, 120));
        botonRafael->setFont(font3);
        botonRafael->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel4.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonUriel = new QPushButton(frameAngeles);
        botonUriel->setObjectName(QString::fromUtf8("botonUriel"));
        botonUriel->setGeometry(QRect(250, 410, 120, 120));
        botonUriel->setFont(font3);
        botonUriel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel8.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonSariel = new QPushButton(frameAngeles);
        botonSariel->setObjectName(QString::fromUtf8("botonSariel"));
        botonSariel->setGeometry(QRect(600, 410, 120, 120));
        botonSariel->setFont(font3);
        botonSariel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel10.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonShamsiel = new QPushButton(frameAngeles);
        botonShamsiel->setObjectName(QString::fromUtf8("botonShamsiel"));
        botonShamsiel->setGeometry(QRect(470, 250, 120, 120));
        botonShamsiel->setFont(font3);
        botonShamsiel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel6.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonGabriel = new QPushButton(frameAngeles);
        botonGabriel->setObjectName(QString::fromUtf8("botonGabriel"));
        botonGabriel->setGeometry(QRect(190, 250, 120, 120));
        botonGabriel->setFont(font3);
        botonGabriel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel5.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        frame_14 = new QFrame(pageCielo);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(890, 0, 671, 241));
        frame_14->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_14);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, 0, 671, 31));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(64, 150, 180);\n"
""));
        botonMapaBueno = new QPushButton(frame_14);
        botonMapaBueno->setObjectName(QString::fromUtf8("botonMapaBueno"));
        botonMapaBueno->setGeometry(QRect(180, 170, 281, 51));
        botonMapaBueno->setStyleSheet(QString::fromUtf8("image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
"background-color: rgb(64, 150, 180);"));
        botonTopBA = new QPushButton(frame_14);
        botonTopBA->setObjectName(QString::fromUtf8("botonTopBA"));
        botonTopBA->setGeometry(QRect(10, 100, 281, 51));
        botonTopBA->setStyleSheet(QString::fromUtf8("image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
"background-color: rgb(64, 150, 180);"));
        botonPaisMenosMalos = new QPushButton(frame_14);
        botonPaisMenosMalos->setObjectName(QString::fromUtf8("botonPaisMenosMalos"));
        botonPaisMenosMalos->setGeometry(QRect(370, 100, 281, 51));
        botonPaisMenosMalos->setStyleSheet(QString::fromUtf8("image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
"background-color: rgb(64, 150, 180);"));
        txtCantHumanos_4 = new QLineEdit(pageCielo);
        txtCantHumanos_4->setObjectName(QString::fromUtf8("txtCantHumanos_4"));
        txtCantHumanos_4->setGeometry(QRect(560, 90, 221, 21));
        txtCantHumanos_4->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(64, 150, 180);"));
        label_12 = new QLabel(pageCielo);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(560, 40, 91, 31));
        label_12->setFont(font);
        label_14 = new QLabel(pageCielo);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(50, 10, 111, 111));
        label_14->setStyleSheet(QString::fromUtf8("image:url(\":/images/world.png\");"));
        panelConsultasCieloBuenasAcciones = new QStackedWidget(pageCielo);
        panelConsultasCieloBuenasAcciones->setObjectName(QString::fromUtf8("panelConsultasCieloBuenasAcciones"));
        panelConsultasCieloBuenasAcciones->setGeometry(QRect(820, 270, 851, 621));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_15 = new QLabel(page_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 30, 221, 321));
        label_15->setStyleSheet(QString::fromUtf8("image:url(\":/images/continents/america.png\");"));
        label_16 = new QLabel(page_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(530, 10, 141, 181));
        label_16->setStyleSheet(QString::fromUtf8("image:url(\":/images/continents/asia.png\");"));
        label_17 = new QLabel(page_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(310, 0, 151, 211));
        label_17->setStyleSheet(QString::fromUtf8("image:url(\":/images/continents/europa.png\");"));
        label_18 = new QLabel(page_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(310, 230, 151, 211));
        label_18->setStyleSheet(QString::fromUtf8("image:url(\":/images/continents/africa.png\");"));
        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(540, 210, 151, 211));
        label_19->setStyleSheet(QString::fromUtf8("image:url(\":/images/continents/australia.png\");"));
        panelConsultasCieloBuenasAcciones->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        panelConsultasCieloBuenasAcciones->addWidget(page_4);
        mainPanel->addWidget(pageCielo);
        pageInfierno = new QWidget();
        pageInfierno->setObjectName(QString::fromUtf8("pageInfierno"));
        idPecados = new QLabel(pageInfierno);
        idPecados->setObjectName(QString::fromUtf8("idPecados"));
        idPecados->setGeometry(QRect(410, 60, 91, 16));
        txtPecados = new QLineEdit(pageInfierno);
        txtPecados->setObjectName(QString::fromUtf8("txtPecados"));
        txtPecados->setGeometry(QRect(390, 100, 113, 24));
        pushButton_3 = new QPushButton(pageInfierno);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 140, 181, 25));
        botonTopPecados = new QPushButton(pageInfierno);
        botonTopPecados->setObjectName(QString::fromUtf8("botonTopPecados"));
        botonTopPecados->setGeometry(QRect(50, 30, 171, 25));
        botonPaisMenosMalos_2 = new QPushButton(pageInfierno);
        botonPaisMenosMalos_2->setObjectName(QString::fromUtf8("botonPaisMenosMalos_2"));
        botonPaisMenosMalos_2->setGeometry(QRect(50, 90, 171, 25));
        botonmapaMalo = new QPushButton(pageInfierno);
        botonmapaMalo->setObjectName(QString::fromUtf8("botonmapaMalo"));
        botonmapaMalo->setGeometry(QRect(50, 150, 171, 25));
        frameDemonios = new QFrame(pageInfierno);
        frameDemonios->setObjectName(QString::fromUtf8("frameDemonios"));
        frameDemonios->setGeometry(QRect(50, 190, 761, 551));
        frameDemonios->setFrameShape(QFrame::StyledPanel);
        frameDemonios->setFrameShadow(QFrame::Raised);
        botonMammon = new QPushButton(frameDemonios);
        botonMammon->setObjectName(QString::fromUtf8("botonMammon"));
        botonMammon->setGeometry(QRect(40, 80, 120, 120));
        botonMammon->setFont(font3);
        botonMammon->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        codicia = new QLabel(frameDemonios);
        codicia->setObjectName(QString::fromUtf8("codicia"));
        codicia->setGeometry(QRect(70, 60, 71, 16));
        QFont font4;
        font4.setPointSize(12);
        codicia->setFont(font4);
        labelDemonios = new QLabel(frameDemonios);
        labelDemonios->setObjectName(QString::fromUtf8("labelDemonios"));
        labelDemonios->setGeometry(QRect(330, 10, 131, 31));
        labelDemonios->setFont(font2);
        botonLucifer = new QPushButton(frameDemonios);
        botonLucifer->setObjectName(QString::fromUtf8("botonLucifer"));
        botonLucifer->setGeometry(QRect(320, 80, 120, 120));
        botonLucifer->setFont(font3);
        botonLucifer->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon1.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonBelcebu = new QPushButton(frameDemonios);
        botonBelcebu->setObjectName(QString::fromUtf8("botonBelcebu"));
        botonBelcebu->setGeometry(QRect(600, 80, 120, 120));
        botonBelcebu->setFont(font3);
        botonBelcebu->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon2.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonSatan = new QPushButton(frameDemonios);
        botonSatan->setObjectName(QString::fromUtf8("botonSatan"));
        botonSatan->setGeometry(QRect(40, 260, 120, 120));
        botonSatan->setFont(font3);
        botonSatan->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon3.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonAbandon = new QPushButton(frameDemonios);
        botonAbandon->setObjectName(QString::fromUtf8("botonAbandon"));
        botonAbandon->setGeometry(QRect(320, 260, 120, 120));
        botonAbandon->setFont(font3);
        botonAbandon->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon4.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonBelfegor = new QPushButton(frameDemonios);
        botonBelfegor->setObjectName(QString::fromUtf8("botonBelfegor"));
        botonBelfegor->setGeometry(QRect(600, 260, 120, 120));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Courier New")});
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        botonBelfegor->setFont(font5);
        botonBelfegor->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon6.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonAsmodeo = new QPushButton(frameDemonios);
        botonAsmodeo->setObjectName(QString::fromUtf8("botonAsmodeo"));
        botonAsmodeo->setGeometry(QRect(320, 420, 120, 120));
        botonAsmodeo->setFont(font3);
        botonAsmodeo->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon7.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        orgullo = new QLabel(frameDemonios);
        orgullo->setObjectName(QString::fromUtf8("orgullo"));
        orgullo->setGeometry(QRect(350, 50, 81, 31));
        orgullo->setFont(font4);
        envidia = new QLabel(frameDemonios);
        envidia->setObjectName(QString::fromUtf8("envidia"));
        envidia->setGeometry(QRect(630, 60, 71, 16));
        envidia->setFont(font4);
        pereza = new QLabel(frameDemonios);
        pereza->setObjectName(QString::fromUtf8("pereza"));
        pereza->setGeometry(QRect(340, 240, 71, 16));
        pereza->setFont(font4);
        ira = new QLabel(frameDemonios);
        ira->setObjectName(QString::fromUtf8("ira"));
        ira->setGeometry(QRect(90, 230, 71, 16));
        ira->setFont(font4);
        glotoneria = new QLabel(frameDemonios);
        glotoneria->setObjectName(QString::fromUtf8("glotoneria"));
        glotoneria->setGeometry(QRect(610, 240, 91, 20));
        glotoneria->setFont(font4);
        lujuria = new QLabel(frameDemonios);
        lujuria->setObjectName(QString::fromUtf8("lujuria"));
        lujuria->setGeometry(QRect(350, 395, 71, 21));
        lujuria->setFont(font4);
        label_3 = new QLabel(pageInfierno);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 10, 111, 16));
        mainPanel->addWidget(pageInfierno);
        pageConsultas = new QWidget();
        pageConsultas->setObjectName(QString::fromUtf8("pageConsultas"));
        pushButton_16 = new QPushButton(pageConsultas);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(20, 30, 151, 41));
        pushButton_17 = new QPushButton(pageConsultas);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(210, 30, 161, 41));
        panelConsultas = new QStackedWidget(pageConsultas);
        panelConsultas->setObjectName(QString::fromUtf8("panelConsultas"));
        panelConsultas->setGeometry(QRect(0, 120, 1671, 831));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        scrollConsultaBueno = new QScrollArea(page);
        scrollConsultaBueno->setObjectName(QString::fromUtf8("scrollConsultaBueno"));
        scrollConsultaBueno->setGeometry(QRect(-30, 50, 661, 301));
        scrollConsultaBueno->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 659, 299));
        labelListadoBuenos = new QLabel(scrollAreaWidgetContents_2);
        labelListadoBuenos->setObjectName(QString::fromUtf8("labelListadoBuenos"));
        labelListadoBuenos->setGeometry(QRect(150, 80, 281, 16));
        scrollConsultaPecado = new QScrollArea(scrollAreaWidgetContents_2);
        scrollConsultaPecado->setObjectName(QString::fromUtf8("scrollConsultaPecado"));
        scrollConsultaPecado->setGeometry(QRect(120, 10, 661, 301));
        scrollConsultaPecado->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 659, 299));
        labelListadoPecador = new QLabel(scrollAreaWidgetContents);
        labelListadoPecador->setObjectName(QString::fromUtf8("labelListadoPecador"));
        labelListadoPecador->setGeometry(QRect(70, 180, 311, 16));
        scrollConsultaPecado->setWidget(scrollAreaWidgetContents);
        scrollConsultaBueno->setWidget(scrollAreaWidgetContents_2);
        panelConsultas->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        panelConsultas->addWidget(page_2);
        mainPanel->addWidget(pageConsultas);
        pageConsultas2 = new QWidget();
        pageConsultas2->setObjectName(QString::fromUtf8("pageConsultas2"));
        labelApellidoPais = new QLabel(pageConsultas2);
        labelApellidoPais->setObjectName(QString::fromUtf8("labelApellidoPais"));
        labelApellidoPais->setGeometry(QRect(330, 10, 181, 16));
        lineEdit = new QLineEdit(pageConsultas2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(310, 40, 211, 24));
        scrollEstadoHumanos = new QScrollArea(pageConsultas2);
        scrollEstadoHumanos->setObjectName(QString::fromUtf8("scrollEstadoHumanos"));
        scrollEstadoHumanos->setGeometry(QRect(110, 80, 641, 321));
        scrollEstadoHumanos->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 639, 319));
        scrollEstadoHumanos->setWidget(scrollAreaWidgetContents_3);
        labelIngresarFam = new QLabel(pageConsultas2);
        labelIngresarFam->setObjectName(QString::fromUtf8("labelIngresarFam"));
        labelIngresarFam->setGeometry(QRect(380, 430, 121, 16));
        label_6 = new QLabel(pageConsultas2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 460, 351, 231));
        mainPanel->addWidget(pageConsultas2);
        pageGanador = new QWidget();
        pageGanador->setObjectName(QString::fromUtf8("pageGanador"));
        frameGanadorCielo = new QFrame(pageGanador);
        frameGanadorCielo->setObjectName(QString::fromUtf8("frameGanadorCielo"));
        frameGanadorCielo->setGeometry(QRect(90, 20, 461, 261));
        frameGanadorCielo->setFrameShape(QFrame::StyledPanel);
        frameGanadorCielo->setFrameShadow(QFrame::Raised);
        cantPecadosCielo = new QLabel(frameGanadorCielo);
        cantPecadosCielo->setObjectName(QString::fromUtf8("cantPecadosCielo"));
        cantPecadosCielo->setGeometry(QRect(10, 60, 131, 21));
        imprimirCantPecadosCielo = new QLabel(frameGanadorCielo);
        imprimirCantPecadosCielo->setObjectName(QString::fromUtf8("imprimirCantPecadosCielo"));
        imprimirCantPecadosCielo->setGeometry(QRect(220, 50, 221, 51));
        cantAccionesBuenasCielo = new QLabel(frameGanadorCielo);
        cantAccionesBuenasCielo->setObjectName(QString::fromUtf8("cantAccionesBuenasCielo"));
        cantAccionesBuenasCielo->setGeometry(QRect(10, 140, 181, 16));
        imprimirCantAccionesBuenasCielo = new QLabel(frameGanadorCielo);
        imprimirCantAccionesBuenasCielo->setObjectName(QString::fromUtf8("imprimirCantAccionesBuenasCielo"));
        imprimirCantAccionesBuenasCielo->setGeometry(QRect(210, 120, 241, 51));
        netoCielo = new QLabel(frameGanadorCielo);
        netoCielo->setObjectName(QString::fromUtf8("netoCielo"));
        netoCielo->setGeometry(QRect(20, 210, 55, 16));
        imprimirCantNetoCielo = new QLabel(frameGanadorCielo);
        imprimirCantNetoCielo->setObjectName(QString::fromUtf8("imprimirCantNetoCielo"));
        imprimirCantNetoCielo->setGeometry(QRect(210, 200, 221, 51));
        infoCielo = new QLabel(frameGanadorCielo);
        infoCielo->setObjectName(QString::fromUtf8("infoCielo"));
        infoCielo->setGeometry(QRect(160, 10, 151, 16));
        frameGanadorCielo_2 = new QFrame(pageGanador);
        frameGanadorCielo_2->setObjectName(QString::fromUtf8("frameGanadorCielo_2"));
        frameGanadorCielo_2->setGeometry(QRect(90, 380, 461, 261));
        frameGanadorCielo_2->setFrameShape(QFrame::StyledPanel);
        frameGanadorCielo_2->setFrameShadow(QFrame::Raised);
        cantPecadosInfierno = new QLabel(frameGanadorCielo_2);
        cantPecadosInfierno->setObjectName(QString::fromUtf8("cantPecadosInfierno"));
        cantPecadosInfierno->setGeometry(QRect(10, 60, 131, 21));
        imprimirCantPecadosInfierno = new QLabel(frameGanadorCielo_2);
        imprimirCantPecadosInfierno->setObjectName(QString::fromUtf8("imprimirCantPecadosInfierno"));
        imprimirCantPecadosInfierno->setGeometry(QRect(220, 50, 221, 51));
        cantAccionesBuenasInfierno = new QLabel(frameGanadorCielo_2);
        cantAccionesBuenasInfierno->setObjectName(QString::fromUtf8("cantAccionesBuenasInfierno"));
        cantAccionesBuenasInfierno->setGeometry(QRect(10, 140, 181, 16));
        imprimirCantAccionesBuenasInfierno = new QLabel(frameGanadorCielo_2);
        imprimirCantAccionesBuenasInfierno->setObjectName(QString::fromUtf8("imprimirCantAccionesBuenasInfierno"));
        imprimirCantAccionesBuenasInfierno->setGeometry(QRect(210, 120, 241, 51));
        netoInfierno = new QLabel(frameGanadorCielo_2);
        netoInfierno->setObjectName(QString::fromUtf8("netoInfierno"));
        netoInfierno->setGeometry(QRect(20, 210, 55, 16));
        imprimirCantNetoInfierno = new QLabel(frameGanadorCielo_2);
        imprimirCantNetoInfierno->setObjectName(QString::fromUtf8("imprimirCantNetoInfierno"));
        imprimirCantNetoInfierno->setGeometry(QRect(210, 200, 221, 51));
        infoInfierno = new QLabel(frameGanadorCielo_2);
        infoInfierno->setObjectName(QString::fromUtf8("infoInfierno"));
        infoInfierno->setGeometry(QRect(160, 10, 171, 16));
        mainPanel->addWidget(pageGanador);
        sideBarFrame = new QFrame(centralwidget);
        sideBarFrame->setObjectName(QString::fromUtf8("sideBarFrame"));
        sideBarFrame->setGeometry(QRect(0, 0, 221, 1000));
        sideBarFrame->setStyleSheet(QString::fromUtf8("background-color:rgb(2, 49, 70);"));
        sideBarFrame->setFrameShape(QFrame::StyledPanel);
        sideBarFrame->setFrameShadow(QFrame::Raised);
        botonHumanos = new QPushButton(sideBarFrame);
        botonHumanos->setObjectName(QString::fromUtf8("botonHumanos"));
        botonHumanos->setGeometry(QRect(0, 250, 221, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Open Sans")});
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setItalic(false);
        botonHumanos->setFont(font6);
        botonHumanos->setStyleSheet(QString::fromUtf8("image:url(\":/images/plus.png\");\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
""));
        botonHumanos->setIconSize(QSize(14, 14));
        botonInfierno = new QPushButton(sideBarFrame);
        botonInfierno->setObjectName(QString::fromUtf8("botonInfierno"));
        botonInfierno->setGeometry(QRect(0, 350, 221, 51));
        botonInfierno->setStyleSheet(QString::fromUtf8("image:url(\":/images/hell.png\");\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";\n"
""));
        botonGanador = new QPushButton(sideBarFrame);
        botonGanador->setObjectName(QString::fromUtf8("botonGanador"));
        botonGanador->setGeometry(QRect(0, 500, 221, 51));
        botonGanador->setStyleSheet(QString::fromUtf8("image:url(\":/images/trophy.png\");\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";"));
        botonConsultas = new QPushButton(sideBarFrame);
        botonConsultas->setObjectName(QString::fromUtf8("botonConsultas"));
        botonConsultas->setGeometry(QRect(0, 400, 221, 51));
        botonConsultas->setStyleSheet(QString::fromUtf8("image:url(\":/images/consulta.png\");\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";"));
        botonConsultas2 = new QPushButton(sideBarFrame);
        botonConsultas2->setObjectName(QString::fromUtf8("botonConsultas2"));
        botonConsultas2->setGeometry(QRect(0, 450, 221, 51));
        botonConsultas2->setStyleSheet(QString::fromUtf8("image:url(\":/images/consulta.png\");\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";"));
        botonCielo = new QPushButton(sideBarFrame);
        botonCielo->setObjectName(QString::fromUtf8("botonCielo"));
        botonCielo->setGeometry(QRect(0, 300, 221, 51));
        botonCielo->setStyleSheet(QString::fromUtf8("image:url(\":/images/heaven.png\");\n"
"image-position:left;\n"
"color: white;\n"
"padding: 10px;\n"
"border:0px;\n"
"font: 12pt \"Open Sans\";"));
        label = new QLabel(sideBarFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 221, 221));
        label->setStyleSheet(QString::fromUtf8("image:url(\":/images/picture.jpg\");"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1900, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        mainPanel->setCurrentIndex(1);
        panelConsultasCieloBuenasAcciones->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Buscar humano m\303\241s cerca", nullptr));
        txtcerca->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        txtCantHumanos_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Cantidad:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Creaci\303\263n de Humanos ", nullptr));
        txtCantHumanos->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        btnCrearHumanos->setText(QCoreApplication::translate("MainWindow", "Generar humanos", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Buscar humano", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "B\303\272squeda de Humanos", nullptr));
        txtBuscar->setText(QString());
        label_11->setText(QString());
        btnBuscarPersona->setText(QCoreApplication::translate("MainWindow", "buscar humano", nullptr));
        lbDatosWorld->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 se ve el texto.", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Hacer Pecar y Buenas Acciones", nullptr));
        label_22->setText(QString());
        btnPecar->setText(QCoreApplication::translate("MainWindow", "Pecados y Buenas Acciones", nullptr));
        botonBAFamilias->setText(QCoreApplication::translate("MainWindow", "Buenas acciones por familia", nullptr));
        idBuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Ingrese un ID:", nullptr));
        labelAngeles->setText(QCoreApplication::translate("MainWindow", "\303\201ngeles", nullptr));
        botonNuriel->setText(QCoreApplication::translate("MainWindow", "Nuriel", nullptr));
        botonMiguel->setText(QCoreApplication::translate("MainWindow", "Miguel", nullptr));
        botonAniel->setText(QCoreApplication::translate("MainWindow", "Aniel", nullptr));
        botonRaguel->setText(QCoreApplication::translate("MainWindow", "Raguel", nullptr));
        botonAzrael->setText(QCoreApplication::translate("MainWindow", "Azrael", nullptr));
        botonRafael->setText(QCoreApplication::translate("MainWindow", "Rafael", nullptr));
        botonUriel->setText(QCoreApplication::translate("MainWindow", "Uriel", nullptr));
        botonSariel->setText(QCoreApplication::translate("MainWindow", "Sariel", nullptr));
        botonShamsiel->setText(QCoreApplication::translate("MainWindow", "Shamsiel", nullptr));
        botonGabriel->setText(QCoreApplication::translate("MainWindow", "Gabriel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Consultas del Cielo", nullptr));
        botonMapaBueno->setText(QCoreApplication::translate("MainWindow", "Mapa de Continentes", nullptr));
        botonTopBA->setText(QCoreApplication::translate("MainWindow", "Top 10 pa\303\255ses buenas acciones", nullptr));
        botonPaisMenosMalos->setText(QCoreApplication::translate("MainWindow", "Top 5 pa\303\255ses \"Buenos\"", nullptr));
        txtCantHumanos_4->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Cantidad:", nullptr));
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        idPecados->setText(QCoreApplication::translate("MainWindow", "Ingrese un ID: ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Pecados de una familia", nullptr));
        botonTopPecados->setText(QCoreApplication::translate("MainWindow", "Top 10 pa\303\255ses m\303\241s pecados", nullptr));
        botonPaisMenosMalos_2->setText(QCoreApplication::translate("MainWindow", "Top 5 pa\303\255ses \"buenos\"", nullptr));
        botonmapaMalo->setText(QCoreApplication::translate("MainWindow", "Mapa de continentes", nullptr));
        botonMammon->setText(QCoreApplication::translate("MainWindow", "Mamm\303\263n", nullptr));
        codicia->setText(QCoreApplication::translate("MainWindow", "Codicia", nullptr));
        labelDemonios->setText(QCoreApplication::translate("MainWindow", "Demonios", nullptr));
        botonLucifer->setText(QCoreApplication::translate("MainWindow", "Lucifer", nullptr));
        botonBelcebu->setText(QCoreApplication::translate("MainWindow", "Belceb\303\272", nullptr));
        botonSatan->setText(QCoreApplication::translate("MainWindow", "Sat\303\241n", nullptr));
        botonAbandon->setText(QCoreApplication::translate("MainWindow", "Aband\303\263n", nullptr));
        botonBelfegor->setText(QCoreApplication::translate("MainWindow", "Belfegor", nullptr));
        botonAsmodeo->setText(QCoreApplication::translate("MainWindow", "Asmodeo", nullptr));
        orgullo->setText(QCoreApplication::translate("MainWindow", "Orgullo", nullptr));
        envidia->setText(QCoreApplication::translate("MainWindow", "Envidia", nullptr));
        pereza->setText(QCoreApplication::translate("MainWindow", "Pereza", nullptr));
        ira->setText(QCoreApplication::translate("MainWindow", "Ira", nullptr));
        glotoneria->setText(QCoreApplication::translate("MainWindow", "Glotoner\303\255a", nullptr));
        lujuria->setText(QCoreApplication::translate("MainWindow", "Lujuria", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Consultas infierno", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Cielo (Salvaci\303\263n)", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Infierno (Condenaci\303\263n)", nullptr));
        labelListadoBuenos->setText(QCoreApplication::translate("MainWindow", "Listado de humano m\303\241s bueno al menos bueno:", nullptr));
        labelListadoPecador->setText(QCoreApplication::translate("MainWindow", "Listado de humano m\303\241s pecador al menos pecador:", nullptr));
        labelApellidoPais->setText(QCoreApplication::translate("MainWindow", "Ingrese un apellido y un pa\303\255s:", nullptr));
        labelIngresarFam->setText(QCoreApplication::translate("MainWindow", "Ingrese una familia:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 se muestra la info correspondiente.", nullptr));
        cantPecadosCielo->setText(QCoreApplication::translate("MainWindow", "Cantidad de pecados:", nullptr));
        imprimirCantPecadosCielo->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 va la cantidad de pecados", nullptr));
        cantAccionesBuenasCielo->setText(QCoreApplication::translate("MainWindow", "Cantidad de acciones buenas:", nullptr));
        imprimirCantAccionesBuenasCielo->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 va la cantidad de acciones buenas", nullptr));
        netoCielo->setText(QCoreApplication::translate("MainWindow", "Neto:", nullptr));
        imprimirCantNetoCielo->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 va el neto", nullptr));
        infoCielo->setText(QCoreApplication::translate("MainWindow", "Informaci\303\263n final del cielo", nullptr));
        cantPecadosInfierno->setText(QCoreApplication::translate("MainWindow", "Cantidad de pecados:", nullptr));
        imprimirCantPecadosInfierno->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 va la cantidad de pecados", nullptr));
        cantAccionesBuenasInfierno->setText(QCoreApplication::translate("MainWindow", "Cantidad de acciones buenas:", nullptr));
        imprimirCantAccionesBuenasInfierno->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 va la cantidad de acciones buenas", nullptr));
        netoInfierno->setText(QCoreApplication::translate("MainWindow", "Neto:", nullptr));
        imprimirCantNetoInfierno->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 va el neto", nullptr));
        infoInfierno->setText(QCoreApplication::translate("MainWindow", "Informaci\303\263n final del infierno", nullptr));
        botonHumanos->setText(QCoreApplication::translate("MainWindow", "Crear Humanos", nullptr));
        botonInfierno->setText(QCoreApplication::translate("MainWindow", "Infierno", nullptr));
        botonGanador->setText(QCoreApplication::translate("MainWindow", "Ganador", nullptr));
        botonConsultas->setText(QCoreApplication::translate("MainWindow", "Consultas", nullptr));
        botonConsultas2->setText(QCoreApplication::translate("MainWindow", "Consultas 2", nullptr));
        botonCielo->setText(QCoreApplication::translate("MainWindow", "Cielo", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
