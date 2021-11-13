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
    QLabel *arrayLabelsBuenasAcciones[5] = {ui->lbAmericaHeaven, ui->lbAfricaHeaven, ui->lbEuropaHeaven, ui->lbAustraliaHeaven, ui->lbAsiaHeaven };
    QLabel *arrayLabelsPecados[5] = {ui->lbAmericaHell, ui->lbAfricaHell, ui->lbEuropaHell, ui->lbAustraliaHell, ui->lbAsiaHell };
    mainstruct = new MainStruct(arrayLabelsBuenasAcciones,arrayLabelsPecados);

    QVBoxLayout * lay = new QVBoxLayout();
    lay->addWidget(ui->lbHumanFound);
    ui->scrollAreaWidgetContents_4->setLayout(lay);
}


//--------------------WORLD PAGE BUTTONS--------------------
void MainWindow::on_btnCrearHumanos_clicked(){
    mainstruct->mundo->crearHumanos(ui->txtCantHumanos->text().toInt(), ui->lbHumanFound);
    msg.setText("Se han creado: "+QString::number(ui->txtCantHumanos->text().toInt())+" humanos");
    msg.exec();
}

void MainWindow::on_btnBuscarPersona_clicked(){
    mainstruct->mundo->buscarHuman(ui->txtBuscar->text().toInt(), ui->lbHumanFound);

}
void MainWindow::on_btnPecar_clicked(){
    mainstruct->mundo->hacerPecar();
    msg.setText("Los humanos han pecado y hecho buenas acciones");
    msg.exec();
}

void MainWindow::on_btnGuardarDatosWorld_clicked(){
    mainstruct->mundo->guarDatosWorld();
    msg.setText("Se han guardado los datos");
    msg.exec();
}

void MainWindow::on_pushButton_2_clicked(){

    qDebug()<<"El mas cercano: "<<mainstruct->mundo->treePersonas->buscarMasCercano(ui->txtcerca->text().toInt())->persona->id;
}

//--------------------SIDE BUTTONS--------------------
void MainWindow::cambiarColor(QPushButton *btn){
    QString style = btn->styleSheet();
    for (int i = 210; i <=510; i+=50) {
        QString styleChild = ui->sideBarFrame->childAt(0,i)->styleSheet();
        styleChild += colorBackground;
        ui->sideBarFrame->childAt(0,i)->setStyleSheet(styleChild);
    }
    style += colorHovered;
    btn->setStyleSheet(style);


}

void MainWindow::on_botonHumanos_clicked(){
    ui->mainPanel->setCurrentIndex(0);
    cambiarColor(ui->botonHumanos);
}


void MainWindow::on_botonCielo_clicked(){
    ui->mainPanel->setCurrentIndex(1);
    cambiarColor(ui->botonCielo);
}


void MainWindow::on_botonInfierno_clicked(){
    ui->mainPanel->setCurrentIndex(2);
    cambiarColor(ui->botonInfierno);
}


void MainWindow::on_botonGanador_clicked(){
    ui->mainPanel->setCurrentIndex(5);
    cambiarColor(ui->botonGanador);
}


void MainWindow::on_botonConsultas_clicked(){
    ui->mainPanel->setCurrentIndex(3);
    cambiarColor(ui->botonConsultas);
}


void MainWindow::on_botonConsultas2_clicked(){
    ui->mainPanel->setCurrentIndex(4);
    cambiarColor(ui->botonConsultas2);
}







//---------------------------------- Cielo ----------------
void MainWindow::on_btnMapaContinentesBuenasAcciones_clicked(){
    mainstruct->mundo->continentsMasBuenasAcciones();
}


void MainWindow::on_btnMapaPecados_clicked(){
    mainstruct->mundo->continentsMasPecados();
}


void MainWindow::on_pushButton_clicked(){
    files.clear();

    /*QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();*/
    files.append("datosWorld.txt");
    QString fileListString;
    foreach(QString file, files){
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );
        qDebug()<<file;
    }

    //ui->file->setText( fileListString );

    Smtp* smtp = new Smtp("laroxeta2018@gmail.com", "l4roseta32", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if(!files.isEmpty())
        smtp->sendMail("laroxeta2018@gmail.com", "cesarjjxd@gmail.com" , "ui->subject->text()","ui->msg->toPlainText()", files );
    else
        smtp->sendMail("laroxeta2018@gmail.com", "cesarjjxd@gmail.com" , "ui->subject->text()","ui->msg->toPlainText()");
}

