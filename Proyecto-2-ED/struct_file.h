#ifndef STRUCT_FILE_H
#define STRUCT_FILE_H

#include <QString>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

struct Pais;
struct Files;


struct Pais{
    QString name;
    QString continente;

    Pais(){
        name = "";
        continente = "";
    }

    Pais(QString _name, QString _continente){
        name = _name;
        continente = _continente;
    }

    void toString();
};

struct Files{
    QString names[1000];
    QString lastNames[1000];
    QString religions[19];
    QString jobs[80];
    Pais * paises[196];
    int index;

    Files(){
        index = 0;
        loadNames();
        loadLastNames();
        loadReligions();
        loadJobs();
        loadAmerica();
        loadAfrica();
        loadEuropa();
        loadAsia();
        loadOceania();
    }

    void loadNames();
    void loadLastNames();
    void loadReligions();
    void loadJobs();
    void loadAmerica();
    void loadAfrica();
    void loadEuropa();
    void loadAsia();
    void loadOceania();

    void printNames();
};

#endif // STRUCT_FILE_H
