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
    //mainstruct->mundo->guarDatosWorld();

    msg.setText("Se han guardado los datos");
    msg.exec();
}

void MainWindow::on_pushButton_2_clicked(){

    //qDebug()<<"El mas cercano: "<<mainstruct->mundo->treePersonas->buscarMasCercano(ui->txtcerca->text().toInt())->persona->id;
    mainstruct->mundo->arbolAngeles->nivel ++;
    int nivel = mainstruct->mundo->arbolAngeles->nivel;
    int cantArboles  = qPow(3, nivel);
    for(int i = 0; i < cantArboles; i++)
        mainstruct->mundo->arbolAngeles->insertar(new Angel("FERKS "+QString::number(i+1), nivel, i+1, new Persona));
    qDebug()<<"\n\n";
    mainstruct->mundo->arbolAngeles->imprimirNivel(nivel);
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

    Smtp* smtp = new Smtp("ferkssoporte@gmail.com", "DistributividaD...", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if(!files.isEmpty())
        smtp->sendMail("ferkssoporte@gmail.com", "cesarjjxd@gmail.com" , "ui->subject->text()","ui->msg->toPlainText()", files);
    else
        smtp->sendMail("ferkssoporte@gmail.com", "cesarjjxd@gmail.com" , "ui->subject->text()","ui->msg->toPlainText()");
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
        mainstruct->mundo->infierno->matarMasPecadores(mainstruct->mundo->personas, mainstruct->mundo->files);
        msg.setText("Los demonios han tomado las almas más pecadoras");
        msg.exec();
    }else{
        msg.setText("No hay humanos en el mundo");
        msg.exec();
    }
}


void MainWindow::on_btnImprimir_clicked()
{
    mainstruct->mundo->infierno->imprimirDemonio(ui->lineEdit_2->text().toInt());
}

