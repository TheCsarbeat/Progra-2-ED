#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include "mainstruct.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include "smtp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{


    Q_OBJECT
    QMessageBox msg;
    QString colorHovered = "background-color:rgb(66, 154, 134);";
    QString colorBackground = "background-color:rgb(2, 49, 70);";

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCrearHumanos_clicked();

    void on_pushButton_2_clicked();

    void on_botonCielo_clicked();

    void on_botonHumanos_clicked();

    void on_botonInfierno_clicked();

    void on_botonGanador_clicked();

    void on_botonConsultas_clicked();

    void on_botonConsultas2_clicked();

    void on_btnPecar_clicked();

    void on_btnBuscarPersona_clicked();

    void cambiarColor(QPushButton *);
    void on_btnGuardarDatosWorld_clicked();

    void on_btnMapaContinentesBuenasAcciones_clicked();

    void on_btnMapaPecados_clicked();

    void on_btnTop10Cielo_clicked();

    void on_btnTop5Cielo_clicked();

    void on_btnTop10Infierno_clicked();

    void on_btnTop5Infierno_clicked();

    void on_btnBAFamilias_clicked();

    void on_btnPecadosFamilia_clicked();

    void on_btnMatarTodos_clicked();

    void on_btnEstadoFamilia_clicked();

    void on_btnSalvacion_clicked();

    void sendEmail(QString currentEmail, QString, QString);

    void on_pushButton_clicked();

    void on_btnApellidos_clicked();

    void on_btnContinentes_clicked();

    void on_btnPaises_clicked();

    void on_btnCreencias_clicked();

    void on_btnProfesiones_clicked();

    void on_btnGenerarConsultas_clicked();

    void on_btnImprimirDatoInfiernoGanador_clicked();

private:
    Ui::MainWindow *ui;
    MainStruct * mainstruct;
    QStringList files;


    void start();
};
#endif // MAINWINDOW_H
