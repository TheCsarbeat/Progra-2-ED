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
    QComboBox * arrayCBO[2] = {ui->cboLastNameConsulta, ui->cboCountryConsulta};
    mainstruct = new MainStruct(arrayLabelsBuenasAcciones,arrayLabelsPecados, arrayCBO);

    QVBoxLayout * lay = new QVBoxLayout();
    lay->addWidget(ui->lbHumanFound);
    ui->scrollAreaWidgetContents_4->setLayout(lay);

    QVBoxLayout * lay1 = new QVBoxLayout();
    lay1->addWidget(ui->lbFamiliaBA);
    ui->scrollAreaWidgetContents_5->setLayout(lay1);

    QVBoxLayout * lay2 = new QVBoxLayout();
    lay2->addWidget(ui->lbPecadosFamilias);
    ui->scrollAreaWidgetContents_6->setLayout(lay2);

}


//--------------------WORLD PAGE BUTTONS--------------------
void MainWindow::on_btnCrearHumanos_clicked(){
    mainstruct->mundo->crearHumanos(ui->txtCantHumanos->text().toInt());
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
    ui->panelConsultasCieloBuenasAcciones->setCurrentIndex(0);
}


void MainWindow::on_btnMapaPecados_clicked(){
    mainstruct->mundo->continentsMasPecados();
    ui->panelConsultasInfiernoPecados->setCurrentIndex(0);
}

void MainWindow::sendEmail(QString currentEmail, QString subject, QString msg){
    QString fileListString;
    foreach(QString file, files){
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );
        qDebug()<<file;
    }
    Smtp* smtp = new Smtp("ferkssoporte@gmail.com", "DistributividaD...", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if(!files.isEmpty() && currentEmail == "")
        smtp->sendMail("ferkssoporte@gmail.com", "quesonconpicha@gmail.com" , subject,msg, files );
    else if(currentEmail != "")
        smtp->sendMail("ferkssoporte@gmail.com", "quesonconpicha@gmail.com" , subject,msg,QStringList(currentEmail));
    else
        smtp->sendMail("ferkssoporte@gmail.com", "quesonconpicha@gmail.com" , subject,msg);
}



void MainWindow::on_btnTop10Cielo_clicked(){
    mainstruct->mundo->top10Cielo(ui->lbtop10cielo, ui->lbtop10cielo_2);
    ui->panelConsultasCieloBuenasAcciones->setCurrentIndex(1);
}


void MainWindow::on_btnTop5Cielo_clicked(){
    mainstruct->mundo->top5Cielo(ui->lbtop5Cielo,ui->lbtop5Cielo_2);
    ui->panelConsultasCieloBuenasAcciones->setCurrentIndex(2);
}


void MainWindow::on_btnTop10Infierno_clicked(){
     mainstruct->mundo->top10Infierno(ui->lbtop10Infierno,ui->lbtop10Infierno_2);
     ui->panelConsultasInfiernoPecados->setCurrentIndex(1);
}


void MainWindow::on_btnTop5Infierno_clicked(){
    mainstruct->mundo->top5Infierno(ui->lbtop5infierno, ui->lbtop5infierno_2);
    ui->panelConsultasInfiernoPecados->setCurrentIndex(2);
}

void MainWindow::on_btnBAFamilias_clicked()
{
    int id = ui->txtIdBuenasAcciones->text().toUInt();
    mainstruct->mundo->buscarBAFamilias(id, ui->lbFamiliaBA);
    ui->panelConsultasCieloBuenasAcciones->setCurrentIndex(3);

}

void MainWindow::on_btnPecadosFamilia_clicked()
{
    int id = ui->txtPecados->text().toUInt();
    mainstruct->mundo->buscarPecadosFamilias(id, ui->lbPecadosFamilias);
    ui->panelConsultasInfiernoPecados->setCurrentIndex(3);
}


void MainWindow::on_btnMatarTodos_clicked()
{
    mainstruct->mundo->infierno->matarMasPecadores(mainstruct->mundo->personas);
}


void MainWindow::on_btnImprimir_clicked()
{
    mainstruct->mundo->infierno->imprimirDemonio(ui->lineEdit_2->text().toInt());
}


void MainWindow::on_btnPecadosFamilia_2_clicked()
{

}


void MainWindow::on_btnEstadoFamilia_clicked(){
    mainstruct->mundo->consutlaHumanStateFamily(ui->cboLastNameConsulta->currentText(),ui->cboCountryConsulta->currentText(), ui->lbStateFamily);
}


void MainWindow::on_btnSalvacion_clicked(){

    mainstruct->mundo->salvacion();
    files.append(mainstruct->mundo->currentFileName);
    sendEmail(mainstruct->mundo->currentFileName, "Salvación","Se ha presionado el botón de salvación estas son las personas salvadas");
    msg.setText("Se han salvado humanos ver datos en los archivos LOG");
    msg.exec();


}


void MainWindow::on_pushButton_clicked(){
    //sendEmail("", "Files from Heaven vs Hell","These are the files created in the program HEAVEN vs HELL");
    for (int i = 0;i<mainstruct->mundo->filesNameToSend.length() ;i++ ) {
        if(files.indexOf(mainstruct->mundo->filesNameToSend.at(i)) == -1){
            files.append(mainstruct->mundo->filesNameToSend.at(i));
        }
    }
    sendEmail("", "Files from Heaven vs Hell","These are the files created in the program HEAVEN vs HELL");
    msg.setText("Se han enviado los archivos al correo");
    msg.exec();

}

