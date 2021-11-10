#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include "mainstruct.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_botonCielo_clicked();

    void on_botonHumanos_clicked();

    void on_botonInfierno_clicked();

    void on_botonGanador_clicked();

    void on_botonConsultas_clicked();

    void on_botonConsultas2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    MainStruct * mainstruct;


    void start();
};
#endif // MAINWINDOW_H
