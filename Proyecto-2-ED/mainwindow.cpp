#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start(){
    mainstruct = new MainStruct();
   // mainstruct->mundo->files->printNames();
}


void MainWindow::on_pushButton_clicked(){
    mainstruct->mundo->crearHumanos(ui->txtCantHumanos->text().toInt());
}


void MainWindow::on_pushButton_2_clicked(){

    qDebug()<<"El mas cercano: "<<mainstruct->mundo->treePersonas->buscarMasCercano(ui->txtcerca->text().toInt())->persona->id;
}


void MainWindow::on_botonHumanos_clicked()
{
    ui->mainPanel->setCurrentIndex(0);
}


void MainWindow::on_botonCielo_clicked()
{
    ui->mainPanel->setCurrentIndex(1);
}


void MainWindow::on_botonInfierno_clicked()
{
    ui->mainPanel->setCurrentIndex(2);
}


void MainWindow::on_botonGanador_clicked()
{
    ui->mainPanel->setCurrentIndex(5);
}


void MainWindow::on_botonConsultas_clicked()
{
    ui->mainPanel->setCurrentIndex(3);
}


void MainWindow::on_botonConsultas2_clicked()
{
    ui->mainPanel->setCurrentIndex(4);
}

