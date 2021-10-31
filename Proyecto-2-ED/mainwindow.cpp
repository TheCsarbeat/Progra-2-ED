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
    mainstruct->mundo->files->printNames();
    Persona * person;
    for(int i=0;i<10000;i++){
        person = mainstruct->mundo->generar();
        person->imprimir();
    }

}


void MainWindow::on_pushButton_clicked()
{

}

