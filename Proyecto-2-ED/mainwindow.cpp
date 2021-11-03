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

