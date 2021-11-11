#ifndef STRUCT_INFIERNO_H
#define STRUCT_INFIERNO_H

#include <QString>
#include <QCoreApplication>

#include "struct_arbolfamilias.h"

struct Infierno;
struct Demonio;
struct HeapFamilias;

struct HeapFamilias{
    ArbolFamilias * heapFamilias;
    int capacidad;
    int size;

    HeapFamilias(){
        size = 0;
        capacidad = 0;
        heapFamilias = new ArbolFamilias[capacidad];
    }
    HeapFamilias(int _capacidad){
        size = 0;
        capacidad = _capacidad;
        heapFamilias = new ArbolFamilias[capacidad];
    }

};

struct Demonio{
    QString name;
    QString pecado;
    HeapFamilias * heap;
    Demonio(){
        name = "";
        pecado = "";
        heap = new HeapFamilias();
    }
    Demonio(QString _name,QString _pecado){
        name = _name;
        pecado = _pecado;
    }
};

struct Infierno{
    Demonio * demonios[7];

    Infierno(){
        QString names[7] = {"Asmodeo","Belfegor","Mammón","Abadón","Satán","Belcebú","Lucifer"};
        QString pecados[7] = {"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
        for(unsigned int i=0;i<7;i++){
            demonios[i]= new Demonio(names[i],pecados[i]);
        }
    }
};

#endif // STRUCT_INFIERNO_H
