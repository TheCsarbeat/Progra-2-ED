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





