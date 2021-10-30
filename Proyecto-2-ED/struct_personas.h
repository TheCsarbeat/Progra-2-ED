#ifndef STRUCT_PERSONAS_H
#define STRUCT_PERSONAS_H

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>

struct ListaSimplePersonas;
struct NodoPersona;
struct Persona;

struct Persona{
    int id;
    QString name;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString email;

    Persona(){
        id = 0;
        name = "";
        apellido = "";
        pais = "";
        creencia = "";
        profesion = "";
        email = "";
    }
};

struct NodoPersona{
    Persona * persona;
    NodoPersona * siguiente;

    NodoPersona(){
        persona = new Persona;
        siguiente = NULL;
    }
};

struct ListaSimplePersonas{
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;
    QString names[1000];
    QString lastNames[1000];

    ListaSimplePersonas(){
        primerNodo = ultimoNodo = NULL;
    }

    void loadNames();
    void loadLastNames();
    void printNames();
};

#endif // STRUCT_PERSONAS_H
