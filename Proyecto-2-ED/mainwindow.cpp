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

    QVBoxLayout * lay3 = new QVBoxLayout();
    lay3->addWidget(ui->lbApellidos);
    ui->scrollAreaWidgetContents_2->setLayout(lay3);

    QVBoxLayout * lay4 = new QVBoxLayout();
    lay4->addWidget(ui->lbApellidosBuenos);
    ui->scrollAreaWidgetContents_11->setLayout(lay4);

    QVBoxLayout * lay5 = new QVBoxLayout();
    lay5->addWidget(ui->lbPaises);
    ui->scrollAreaWidgetContents_8->setLayout(lay5);

    QVBoxLayout * lay6 = new QVBoxLayout();
    lay6->addWidget(ui->lbPaisesBuenos);
    ui->scrollAreaWidgetContents_12->setLayout(lay6);

    QVBoxLayout * lay7 = new QVBoxLayout();
    lay7->addWidget(ui->lbCreencias);
    ui->scrollAreaWidgetContents_9->setLayout(lay7);

    QVBoxLayout * lay8 = new QVBoxLayout();
    lay8->addWidget(ui->lbCreenciaBueno);
    ui->scrollAreaWidgetContents_13->setLayout(lay8);

    QVBoxLayout * lay9 = new QVBoxLayout();
    lay9->addWidget(ui->lbProfesiones);
    ui->scrollAreaWidgetContents_10->setLayout(lay9);

    QVBoxLayout * lay10 = new QVBoxLayout();
    lay10->addWidget(ui->lbProfesionesBuenos);
    ui->scrollAreaWidgetContents_14->setLayout(lay10);

    QVBoxLayout * lay11 = new QVBoxLayout();
    lay11->addWidget(ui->lbStateFamily);
    ui->scrollAreaWidgetContents_23->setLayout(lay11);
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
    if(mainstruct->mundo->personas->largo > 0){
        mainstruct->mundo->hacerPecar();
        msg.setText("Los humanos han pecado y hecho buenas acciones");
        msg.exec();
    }else{
        msg.setText("No hay humanos en el mundo");
        msg.exec();
    }

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
    for (int i = 210; i <=460; i+=50) {
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
    if(mainstruct->mundo->personas->largo != 0){
        mainstruct->mundo->infierno->matarMasPecadores(mainstruct->mundo->personas, mainstruct->mundo->files, &mainstruct->mundo->filesNameToSend, &mainstruct->mundo->currentFileName);
        mainstruct->mundo->personas->vivos = mainstruct->mundo->personas->largo - mainstruct->mundo->infierno->condenados - mainstruct->mundo->cielo->salvados;
        //sendEmail(mainstruct->mundo->currentFileName, "Condenación","Se ha presionado el botón de condenar estas son las personas condenadas");
        msg.setText("Los demonios han tomado las almas más pecadoras");
        msg.exec();
    }else{
        msg.setText("No hay humanos en el mundo");
        msg.exec();
    }
}


void MainWindow::on_btnEstadoFamilia_clicked(){
    mainstruct->mundo->consutlaHumanStateFamily(ui->cboLastNameConsulta->currentText(),ui->cboCountryConsulta->currentText(), ui->lbStateFamily);
}


void MainWindow::on_btnSalvacion_clicked(){
    if(mainstruct->mundo->infierno->condenados != 0){
            mainstruct->mundo->salvacion();
            files.append(mainstruct->mundo->currentFileName);
            //sendEmail(mainstruct->mundo->currentFileName, "Salvación","Se ha presionado el botón de salvación estas son las personas salvadas");
            msg.setText("Se han salvado humanos ver datos en los archivos LOG");
            msg.exec();
    }else{
        msg.setText("No hay humanos en el infierno y no podemos salvar a humanos :)");
        msg.exec();
    }



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



void MainWindow::on_btnApellidos_clicked()
{


    if (ui->rbPecados->isChecked()){
        ui->panelConsultas_2->setCurrentIndex(1);
        mainstruct->mundo->apellidosPecadores(ui->lbApellidos);
    }else{
        ui->panelConsultas_2->setCurrentIndex(6);
        mainstruct->mundo->apellidosBA(ui->lbApellidosBuenos);
    }
}

void MainWindow::on_btnContinentes_clicked()
{
    if (ui->rbPecados->isChecked()){
            ui->panelConsultas_2->setCurrentIndex(2);
            mainstruct->mundo->continentesPecadores(ui->lbContinentes);
    }else{
        ui->panelConsultas_2->setCurrentIndex(7);
        mainstruct->mundo->continentesBA(ui->lbContinentesBuenos);
    }
}


void MainWindow::on_btnPaises_clicked()
{
    if (ui->rbPecados->isChecked()){
        ui->panelConsultas_2->setCurrentIndex(3);
        mainstruct->mundo->paisesPecadores(ui->lbPaises);
    }else{
        ui->panelConsultas_2->setCurrentIndex(8);
        mainstruct->mundo->paisesBA(ui->lbPaisesBuenos);
    }
}


void MainWindow::on_btnCreencias_clicked()
{
    if (ui->rbPecados->isChecked()){
        ui->panelConsultas_2->setCurrentIndex(4);
        mainstruct->mundo->creenciasPecadores(ui->lbCreencias);
    }else{
        ui->panelConsultas_2->setCurrentIndex(9);
        mainstruct->mundo->creenciasBA(ui->lbCreenciaBueno);
    }
}


void MainWindow::on_btnProfesiones_clicked()
{
    if (ui->rbPecados->isChecked()){
        ui->panelConsultas_2->setCurrentIndex(5);
        mainstruct->mundo->profesionesPecadores(ui->lbProfesiones);
    }else{
        ui->panelConsultas_2->setCurrentIndex(10);
        mainstruct->mundo->profesionesBA(ui->lbProfesionesBuenos);
    }
}

void MainWindow::on_btnGenerarConsultas_clicked()
{
    if(mainstruct->mundo->infierno->condenados != 0){
        mainstruct->mundo->infierno->generarConsulta(mainstruct->mundo->files);
        msg.setText("Se ha generado el archivo de consultas");
        msg.exec();
    }else{
        msg.setText("No hay humanos en el infierno");
        msg.exec();
    }
}

void MainWindow::on_btnGuardarDatosCielo_clicked(){

    if(mainstruct->mundo->cielo->salvados != 0){
        mainstruct->mundo->guardarDatosCielo();
        msg.setText("Se ha generado el archivo de consultas");
        msg.exec();
    }else{
        msg.setText("No hay humanos en el Cielo");
        msg.exec();
    }


}


void MainWindow::on_btnGanador_clicked(){
    QString datos1 = "";
    QString datos2 = "";
    int netoInfierno = mainstruct->mundo->infierno->sacarResultados(&datos1,&datos2);
    ui->lbInfoInfierno->setText(datos1);
    ui->lbInfoInfierno2->setText(datos2);
    int netoCielo = mainstruct->mundo->cielo->calcularNeto(ui->lbInfoCielo, ui->lbInfoCielo2);

    QString resultado = "";
    resultado += "Infierno                              Cielo";
    resultado += "\n"+QString::number(netoInfierno)+"                              "+QString::number(netoCielo);
    if(netoCielo > netoInfierno){
        resultado += "\nEl ganador es el cielo";
    }else if(netoCielo < netoInfierno){
        resultado += "\nEl ganador es el infierno";
    }else{
        resultado += "\nEs un empate";
    }
    ui->lbGanador->setText(resultado);
}

