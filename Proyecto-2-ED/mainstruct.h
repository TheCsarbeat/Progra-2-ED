#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
struct MainStruct;

struct MainStruct{
    QString names[1000];

    MainStruct(){
    }

    void loadNames();
    void printNames();
};

#endif // MAINSTRUCT_H
