#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

#include <QString>
#include <QDateTime>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

struct ListaDoblePersonas;
struct NodoPersona;
struct Persona;
struct Mundo;
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


//-------------------------------------------------------
struct Pecado{

    QString name;
    int cant;

    Pecado(){
        cant = 0;
        name = "";
    }
    Pecado(QString _name, int _cant){
        cant = _cant;
        name = _name;
    }

};


//-------------------------------------------------------------
struct BuenaAccion{

    QString name;
    int cant;

    BuenaAccion(){
        cant = 0;
        name = "";
    }
    BuenaAccion(QString _name, int _cant){
        cant = _cant;
        name = _name;
    }

};

struct Persona{
    int id;
    QString name;
    QString apellido;
    Pais * pais;
    QString creencia;
    QString profesion;
    QString email;
    bool vivo;
    QDateTime nacimiento;
    Pecado * pecados[7];
    BuenaAccion * buenasAcciones[7];

    Persona(){
        id = 0;
        name = "";
        apellido = "";
        pais = NULL;
        creencia = "";
        profesion = "";
        email = "ytcesarjs@gmail.com";
        vivo = true;
        nacimiento = QDateTime::currentDateTime();
        for(int i = 0; i<7; i++){
            pecados[i] = new Pecado();
            buenasAcciones[i] = new BuenaAccion();
        }
    }

    void imprimir();
};

struct NodoPersona{
    Persona * persona;
    NodoPersona * siguiente;
    NodoPersona * anterior;

    NodoPersona(){
        persona = new Persona;
        siguiente = NULL;
    }
    NodoPersona(Persona * _persona){
        persona = _persona;
        siguiente = anterior = NULL;
    }
};

struct ListaDoblePersonas{
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;

    ListaDoblePersonas(){
        primerNodo = ultimoNodo = NULL;
    }

    bool isEmpty();
    void insertarAntes(NodoPersona * nodo, Persona * p);
    void insertarDespues(NodoPersona *nodo, Persona *p);
    void imprimir();
    void imprimirReverse();
    NodoPersona * borrarALInicio();
    NodoPersona * borrarALFinal();
    NodoPersona * buscar(NodoPersona * persona);
    void insertarEn(int index, NodoPersona * persona);
};

struct Mundo{
    ListaDoblePersonas * personas;
    Files * files;

    Mundo(){
        personas = new ListaDoblePersonas();
        files = new Files();
    }

    Persona * generar();
    void generarPersonas(int);
};

#endif // STRUCT_MUNDO_H
