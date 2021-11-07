#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

#include "struct_personas.h"
#include "struct_file.h"

#include <QRandomGenerator>
#include <QString>

struct Mundo;

struct Mundo{
    ListaDoblePersonas * personas;
    Files * files;
    ArbolPersonas * treePersonas;
    Mundo(){
        personas = new ListaDoblePersonas();
        treePersonas = new ArbolPersonas();
        files = new Files();
    }

    void crearHumanos(int);
    void crearArbol();
    void crearArbol(NodoPersona* array[], int);
};

#endif // STRUCT_MUNDO_H
