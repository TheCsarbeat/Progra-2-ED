#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H

#include "struct_personas.h"

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
struct MainStruct;

struct MainStruct{
    QString names[1000];
    QString lastNames[1000];

    MainStruct(){
    }

    void loadNames();
    void loadLastNames();
    void printNames();
};

#endif // MAINSTRUCT_H
