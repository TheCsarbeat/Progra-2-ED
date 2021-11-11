#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

#include "struct_personas.h"
#include "struct_file.h"
#include "struct_arbolfamilias.h"

#include <QRandomGenerator>
#include <QString>
#include <QLabel>

struct Mundo;

struct Mundo{
    ListaDoblePersonas * personas;
    Files * files;
    ArbolPersonas * treePersonas;
    ArbolFamilias * treeFamilias;
    ListaSimpleArbolFamilias * listArbolFamilias;

    Mundo(){
        personas = new ListaDoblePersonas();
        treePersonas = new ArbolPersonas();
        files = new Files();
        treeFamilias = new ArbolFamilias();
        listArbolFamilias = new ListaSimpleArbolFamilias();
    }

    void crearHumanos(int, QLabel *);
    void crearArbol();
    void crearArbol(NodoPersona* array[], int);
    void hacerPecar();
    void hacerHerencia(Persona *,int, int);

};

#endif // STRUCT_MUNDO_H
