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

    qDebug()<<"El m[as cercano: "<<mainstruct->mundo->treePersonas->buscarMasCercano(ui->txtcerca->text().toInt())->persona->id;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->MainPanel->setCurrentIndex(0);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->MainPanel->setCurrentIndex(1);
}

