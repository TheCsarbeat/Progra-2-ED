#include "struct_mundo.h"
void Mundo::crearHumanos(int dato){
    int contador = 0;
    while(contador!=dato){
        int id = QRandomGenerator::global()->bounded(99999);
        QString name = files->names[QRandomGenerator::global()->bounded(100)];
        QString apellido = files->lastNames[QRandomGenerator::global()->bounded(100)];
        QString pais = files->lastNames[QRandomGenerator::global()->bounded(100)];
        QString creencia = QString::number(contador);
        QString profesion = files->jobs[QRandomGenerator::global()->bounded(100)];
        Persona *p = new Persona(id, name, apellido, pais, creencia, profesion);
        bool respuesta = personas->insertar(p);
        if(respuesta) contador++;
    }

    personas->imprimir();
}




//======================MUNDO===============================

Persona * Mundo::generar(){
    Persona * persona = new Persona();
    persona->id = QRandomGenerator::global()->bounded(0,99999);
    persona->name = files->names[QRandomGenerator::global()->bounded(0,999)];
    persona->apellido = files->lastNames[QRandomGenerator::global()->bounded(0,500)];
    persona->pais = files->paises[QRandomGenerator::global()->bounded(0,195)];
    persona->creencia = files->religions[QRandomGenerator::global()->bounded(0,18)];
    persona->profesion = files->jobs[QRandomGenerator::global()->bounded(0,79)];

    return persona;
}


