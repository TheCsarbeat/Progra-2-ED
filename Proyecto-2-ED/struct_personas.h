#ifndef STRUCT_PERSONAS_H
#define STRUCT_PERSONAS_H

#include <QString>
#include <QDateTime>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

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
    QString pais;
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
        pais = "";
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

    Persona(int _id, QString _name, QString _apellido, QString _pais, QString _creencia, QString _profesion){
        id = _id;
        name = _name;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        email = "erksmartinez2014@gmail.com";
        vivo = true;
        nacimiento = QDateTime::currentDateTime();
        for(int i = 0; i<7; i++){
            pecados[i] = new Pecado();
            buenasAcciones[i] = new BuenaAccion();
        }
    }

    void imprimir(){
        qDebug()<<"\n-----------------\nID: "<<id<<"\nNombre: "<<name<<"\nApellido: "<<apellido<<"\nContador: "<<creencia;
    }

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
    int largo;
    ListaDoblePersonas(){
        primerNodo = ultimoNodo = NULL;
        largo = 0;
    }

    bool isEmpty();
    bool insertar(Persona * persona);
    void imprimir();
    void insertarALInicio(NodoPersona * persona);
    void insertarAlFinal(NodoPersona * persona);

    void imprimirReverse();
    NodoPersona * borrarALInicio();
    NodoPersona * borrarALFinal();
    NodoPersona * buscar(NodoPersona * persona);
    void insertarEn(int index, NodoPersona * persona);
};


//-------------Arbol-----------------------
struct NodoPersonaArbol{
    NodoPersona * nodoPersona;
    NodoPersonaArbol * hijoizquierdo,*hijoderecho;

    NodoPersonaArbol(){
        nodoPersona = new NodoPersona();
        hijoizquierdo = hijoderecho = NULL;
    }

    NodoPersonaArbol(NodoPersona * _persona){
        nodoPersona = _persona;
        hijoizquierdo = hijoderecho = NULL;
    }
};

struct ArbolPersonas{
    NodoPersonaArbol * raiz;
    int cantElementos;
    ArbolPersonas(){
        raiz = NULL;
        cantElementos =0;
    }

    void insertar (int,NodoPersona*);
    NodoPersonaArbol * insertar (int, NodoPersonaArbol*, NodoPersona*);

    void vaciarArbol();
    void vaciarArbol(NodoPersonaArbol*);

    NodoPersona* buscarMasCercano(int);
    NodoPersonaArbol * diferencia(NodoPersonaArbol*,NodoPersonaArbol*,int);
    NodoPersonaArbol * buscarMasCercano(NodoPersonaArbol *,int );

    void imprimir(NodoPersonaArbol*);
    void posOrden(NodoPersonaArbol*);
    void imprimirUltimo(NodoPersonaArbol*);

    void inOrden(NodoPersonaArbol*);
    void inOrdenClientes(NodoPersonaArbol*);
    void preOrden(NodoPersonaArbol*);
    int treeHeight(NodoPersonaArbol*);
    int cantNodos(NodoPersonaArbol*);

    NodoPersonaArbol* buscar (int, NodoPersonaArbol*);
    int obtenerNumeroElementos(NodoPersonaArbol*);
    int peso (NodoPersonaArbol*);
    int obtenerAltura(NodoPersonaArbol*);
    NodoPersonaArbol* mayor (NodoPersonaArbol* arbol);
    NodoPersonaArbol* borrarElemento(int);
    NodoPersonaArbol* borrarElemento(int, NodoPersonaArbol*);
    void anchura(NodoPersonaArbol*);
    int altura(NodoPersonaArbol*);
    int cantHojas(NodoPersonaArbol*);
    int cantNodos2(NodoPersonaArbol*);
    void nodos_nivel (NodoPersonaArbol*, int, int);
    int contadorNodos(NodoPersonaArbol*);
};
#endif // STRUCT_PERSONAS_H
