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

    Mundo(){
        personas = new ListaDoblePersonas();
        files = new Files();
    }

    void crearHumanos(int);
};

#endif // STRUCT_MUNDO_H
