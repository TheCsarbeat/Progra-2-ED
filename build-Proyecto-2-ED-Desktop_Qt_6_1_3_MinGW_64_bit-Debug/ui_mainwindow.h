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
    QPushButton *pushButton;
    QLineEdit *txtCantHumanos;
    QLabel *label_4;
    QLineEdit *txtCantHumanos_2;
    QPushButton *pushButton_4;
    QWidget *pageCielo;
    QLabel *label_2;
    QPushButton *botonBAFamilias;
    QLineEdit *txtIdBuenasAcciones;
    QLabel *idBuenasAcciones;
    QPushButton *botonTopBA;
    QPushButton *botonPaisMenosMalos;
    QPushButton *botonMapaBueno;
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
    QScrollArea *scrollConsultaPecado;
    QWidget *scrollAreaWidgetContents;
    QLabel *labelListadoPecador;
    QLabel *labelListadoBuenos;
    QScrollArea *scrollConsultaBueno;
    QWidget *scrollAreaWidgetContents_2;
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
    QPushButton *botonHumanos;
    QPushButton *botonCielo;
    QPushButton *botonInfierno;
    QLabel *label;
    QPushButton *botonConsultas;
    QPushButton *botonGanador;
    QPushButton *botonConsultas2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1900, 1000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainPanel = new QStackedWidget(centralwidget);
        mainPanel->setObjectName(QString::fromUtf8("mainPanel"));
        mainPanel->setGeometry(QRect(390, 10, 1580, 1000));
        pageCrearHumano = new QWidget();
        pageCrearHumano->setObjectName(QString::fromUtf8("pageCrearHumano"));
        pushButton_2 = new QPushButton(pageCrearHumano);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 130, 161, 51));
        txtcerca = new QLineEdit(pageCrearHumano);
        txtcerca->setObjectName(QString::fromUtf8("txtcerca"));
        txtcerca->setGeometry(QRect(270, 150, 113, 21));
        pushButton = new QPushButton(pageCrearHumano);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 60, 131, 41));
        txtCantHumanos = new QLineEdit(pageCrearHumano);
        txtCantHumanos->setObjectName(QString::fromUtf8("txtCantHumanos"));
        txtCantHumanos->setGeometry(QRect(270, 70, 113, 21));
        label_4 = new QLabel(pageCrearHumano);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 270, 161, 101));
        txtCantHumanos_2 = new QLineEdit(pageCrearHumano);
        txtCantHumanos_2->setObjectName(QString::fromUtf8("txtCantHumanos_2"));
        txtCantHumanos_2->setGeometry(QRect(490, 210, 113, 21));
        pushButton_4 = new QPushButton(pageCrearHumano);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 200, 131, 41));
        mainPanel->addWidget(pageCrearHumano);
        pageCielo = new QWidget();
        pageCielo->setObjectName(QString::fromUtf8("pageCielo"));
        label_2 = new QLabel(pageCielo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 10, 141, 16));
        botonBAFamilias = new QPushButton(pageCielo);
        botonBAFamilias->setObjectName(QString::fromUtf8("botonBAFamilias"));
        botonBAFamilias->setGeometry(QRect(340, 130, 191, 25));
        txtIdBuenasAcciones = new QLineEdit(pageCielo);
        txtIdBuenasAcciones->setObjectName(QString::fromUtf8("txtIdBuenasAcciones"));
        txtIdBuenasAcciones->setGeometry(QRect(370, 90, 113, 24));
        idBuenasAcciones = new QLabel(pageCielo);
        idBuenasAcciones->setObjectName(QString::fromUtf8("idBuenasAcciones"));
        idBuenasAcciones->setGeometry(QRect(380, 60, 91, 16));
        botonTopBA = new QPushButton(pageCielo);
        botonTopBA->setObjectName(QString::fromUtf8("botonTopBA"));
        botonTopBA->setGeometry(QRect(30, 40, 191, 25));
        botonPaisMenosMalos = new QPushButton(pageCielo);
        botonPaisMenosMalos->setObjectName(QString::fromUtf8("botonPaisMenosMalos"));
        botonPaisMenosMalos->setGeometry(QRect(30, 90, 191, 25));
        botonMapaBueno = new QPushButton(pageCielo);
        botonMapaBueno->setObjectName(QString::fromUtf8("botonMapaBueno"));
        botonMapaBueno->setGeometry(QRect(30, 140, 191, 25));
        frameAngeles = new QFrame(pageCielo);
        frameAngeles->setObjectName(QString::fromUtf8("frameAngeles"));
        frameAngeles->setGeometry(QRect(50, 190, 761, 551));
        frameAngeles->setFrameShape(QFrame::StyledPanel);
        frameAngeles->setFrameShadow(QFrame::Raised);
        labelAngeles = new QLabel(frameAngeles);
        labelAngeles->setObjectName(QString::fromUtf8("labelAngeles"));
        labelAngeles->setGeometry(QRect(330, 10, 131, 31));
        QFont font;
        font.setPointSize(14);
        labelAngeles->setFont(font);
        botonNuriel = new QPushButton(frameAngeles);
        botonNuriel->setObjectName(QString::fromUtf8("botonNuriel"));
        botonNuriel->setGeometry(QRect(240, 80, 120, 120));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Courier New")});
        font1.setPointSize(14);
        font1.setBold(true);
        botonNuriel->setFont(font1);
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
        botonMiguel->setFont(font1);
        botonMiguel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel1.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
        botonAniel = new QPushButton(frameAngeles);
        botonAniel->setObjectName(QString::fromUtf8("botonAniel"));
        botonAniel->setGeometry(QRect(410, 80, 120, 120));
        botonAniel->setFont(font1);
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
        botonRaguel->setFont(font1);
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
        botonAzrael->setFont(font1);
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
        botonRafael->setFont(font1);
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
        botonUriel->setFont(font1);
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
        botonSariel->setFont(font1);
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
        botonShamsiel->setFont(font1);
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
        botonGabriel->setFont(font1);
        botonGabriel->setStyleSheet(QString::fromUtf8("image:url(\":/images/angel5.png\");\n"
" background-color: white;\n"
" border-radius:15px;\n"
" color: rgb(64, 150, 180);\n"
" text-align: top ;\n"
"border:1px;\n"
"border-style:solid;"));
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
        botonMammon->setFont(font1);
        botonMammon->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        codicia = new QLabel(frameDemonios);
        codicia->setObjectName(QString::fromUtf8("codicia"));
        codicia->setGeometry(QRect(70, 60, 71, 16));
        QFont font2;
        font2.setPointSize(12);
        codicia->setFont(font2);
        labelDemonios = new QLabel(frameDemonios);
        labelDemonios->setObjectName(QString::fromUtf8("labelDemonios"));
        labelDemonios->setGeometry(QRect(330, 10, 131, 31));
        labelDemonios->setFont(font);
        botonLucifer = new QPushButton(frameDemonios);
        botonLucifer->setObjectName(QString::fromUtf8("botonLucifer"));
        botonLucifer->setGeometry(QRect(320, 80, 120, 120));
        botonLucifer->setFont(font1);
        botonLucifer->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon1.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonBelcebu = new QPushButton(frameDemonios);
        botonBelcebu->setObjectName(QString::fromUtf8("botonBelcebu"));
        botonBelcebu->setGeometry(QRect(600, 80, 120, 120));
        botonBelcebu->setFont(font1);
        botonBelcebu->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon2.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonSatan = new QPushButton(frameDemonios);
        botonSatan->setObjectName(QString::fromUtf8("botonSatan"));
        botonSatan->setGeometry(QRect(40, 260, 120, 120));
        botonSatan->setFont(font1);
        botonSatan->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon3.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonAbandon = new QPushButton(frameDemonios);
        botonAbandon->setObjectName(QString::fromUtf8("botonAbandon"));
        botonAbandon->setGeometry(QRect(320, 260, 120, 120));
        botonAbandon->setFont(font1);
        botonAbandon->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon4.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonBelfegor = new QPushButton(frameDemonios);
        botonBelfegor->setObjectName(QString::fromUtf8("botonBelfegor"));
        botonBelfegor->setGeometry(QRect(600, 260, 120, 120));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Courier New")});
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        botonBelfegor->setFont(font3);
        botonBelfegor->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon6.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        botonAsmodeo = new QPushButton(frameDemonios);
        botonAsmodeo->setObjectName(QString::fromUtf8("botonAsmodeo"));
        botonAsmodeo->setGeometry(QRect(320, 420, 120, 120));
        botonAsmodeo->setFont(font1);
        botonAsmodeo->setStyleSheet(QString::fromUtf8("image:url(\":/images/demon7.png\");\n"
" background-color: rgb(32, 30, 30);\n"
" border-radius:15px;\n"
" color: rgb(198, 46, 48);\n"
" text-align: top ;"));
        orgullo = new QLabel(frameDemonios);
        orgullo->setObjectName(QString::fromUtf8("orgullo"));
        orgullo->setGeometry(QRect(350, 50, 81, 31));
        orgullo->setFont(font2);
        envidia = new QLabel(frameDemonios);
        envidia->setObjectName(QString::fromUtf8("envidia"));
        envidia->setGeometry(QRect(630, 60, 71, 16));
        envidia->setFont(font2);
        pereza = new QLabel(frameDemonios);
        pereza->setObjectName(QString::fromUtf8("pereza"));
        pereza->setGeometry(QRect(340, 240, 71, 16));
        pereza->setFont(font2);
        ira = new QLabel(frameDemonios);
        ira->setObjectName(QString::fromUtf8("ira"));
        ira->setGeometry(QRect(90, 230, 71, 16));
        ira->setFont(font2);
        glotoneria = new QLabel(frameDemonios);
        glotoneria->setObjectName(QString::fromUtf8("glotoneria"));
        glotoneria->setGeometry(QRect(610, 240, 91, 20));
        glotoneria->setFont(font2);
        lujuria = new QLabel(frameDemonios);
        lujuria->setObjectName(QString::fromUtf8("lujuria"));
        lujuria->setGeometry(QRect(350, 395, 71, 21));
        lujuria->setFont(font2);
        label_3 = new QLabel(pageInfierno);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 10, 111, 16));
        mainPanel->addWidget(pageInfierno);
        pageConsultas = new QWidget();
        pageConsultas->setObjectName(QString::fromUtf8("pageConsultas"));
        pushButton_16 = new QPushButton(pageConsultas);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(20, 30, 141, 25));
        pushButton_17 = new QPushButton(pageConsultas);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(20, 80, 141, 25));
        scrollConsultaPecado = new QScrollArea(pageConsultas);
        scrollConsultaPecado->setObjectName(QString::fromUtf8("scrollConsultaPecado"));
        scrollConsultaPecado->setGeometry(QRect(220, 60, 661, 301));
        scrollConsultaPecado->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 659, 299));
        scrollConsultaPecado->setWidget(scrollAreaWidgetContents);
        labelListadoPecador = new QLabel(pageConsultas);
        labelListadoPecador->setObjectName(QString::fromUtf8("labelListadoPecador"));
        labelListadoPecador->setGeometry(QRect(350, 30, 311, 16));
        labelListadoBuenos = new QLabel(pageConsultas);
        labelListadoBuenos->setObjectName(QString::fromUtf8("labelListadoBuenos"));
        labelListadoBuenos->setGeometry(QRect(380, 390, 281, 16));
        scrollConsultaBueno = new QScrollArea(pageConsultas);
        scrollConsultaBueno->setObjectName(QString::fromUtf8("scrollConsultaBueno"));
        scrollConsultaBueno->setGeometry(QRect(220, 410, 661, 301));
        scrollConsultaBueno->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 659, 299));
        scrollConsultaBueno->setWidget(scrollAreaWidgetContents_2);
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
        botonHumanos = new QPushButton(centralwidget);
        botonHumanos->setObjectName(QString::fromUtf8("botonHumanos"));
        botonHumanos->setGeometry(QRect(40, 80, 121, 25));
        botonCielo = new QPushButton(centralwidget);
        botonCielo->setObjectName(QString::fromUtf8("botonCielo"));
        botonCielo->setGeometry(QRect(40, 130, 121, 25));
        botonInfierno = new QPushButton(centralwidget);
        botonInfierno->setObjectName(QString::fromUtf8("botonInfierno"));
        botonInfierno->setGeometry(QRect(40, 180, 121, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 390, 321, 191));
        label->setStyleSheet(QString::fromUtf8("image:url(\":/images/picture.jpg\");"));
        botonConsultas = new QPushButton(centralwidget);
        botonConsultas->setObjectName(QString::fromUtf8("botonConsultas"));
        botonConsultas->setGeometry(QRect(40, 230, 121, 25));
        botonGanador = new QPushButton(centralwidget);
        botonGanador->setObjectName(QString::fromUtf8("botonGanador"));
        botonGanador->setGeometry(QRect(40, 330, 121, 25));
        botonConsultas2 = new QPushButton(centralwidget);
        botonConsultas2->setObjectName(QString::fromUtf8("botonConsultas2"));
        botonConsultas2->setGeometry(QRect(40, 280, 121, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1900, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        mainPanel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Buscar humano m\303\241s cerca", nullptr));
        txtcerca->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Generar humanos", nullptr));
        txtCantHumanos->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Aqu\303\255 se ve el texto.", nullptr));
        txtCantHumanos_2->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "buscar humano", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Consultas cielo", nullptr));
        botonBAFamilias->setText(QCoreApplication::translate("MainWindow", "Buenas acciones por familia", nullptr));
        idBuenasAcciones->setText(QCoreApplication::translate("MainWindow", "Ingrese un ID:", nullptr));
        botonTopBA->setText(QCoreApplication::translate("MainWindow", "Top 10 pa\303\255ses buenas acciones", nullptr));
        botonPaisMenosMalos->setText(QCoreApplication::translate("MainWindow", "Top 5 pa\303\255ses \"Malos\"", nullptr));
        botonMapaBueno->setText(QCoreApplication::translate("MainWindow", "Mapa de Continentes", nullptr));
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
        labelListadoPecador->setText(QCoreApplication::translate("MainWindow", "Listado de humano m\303\241s pecador al menos pecador:", nullptr));
        labelListadoBuenos->setText(QCoreApplication::translate("MainWindow", "Listado de humano m\303\241s bueno al menos bueno:", nullptr));
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
        botonCielo->setText(QCoreApplication::translate("MainWindow", "Cielo", nullptr));
        botonInfierno->setText(QCoreApplication::translate("MainWindow", "Infierno", nullptr));
        label->setText(QString());
        botonConsultas->setText(QCoreApplication::translate("MainWindow", "Consultas", nullptr));
        botonGanador->setText(QCoreApplication::translate("MainWindow", "Ganador", nullptr));
        botonConsultas2->setText(QCoreApplication::translate("MainWindow", "Consultas 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
