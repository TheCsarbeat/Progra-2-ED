#ifndef STRUCT_PERSONAS_H
#define STRUCT_PERSONAS_H

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>


struct Pecado;
struct BuenaAccion;

struct Persona;
struct NodoPersona;
struct ListaDoblePersonas;

//-------------------------------------------------------------
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

//-------------------------------------------------------------
struct Persona{
    int id;
    QString name;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString email;
    Pecado * pecados[7];
    BuenaAccion * buenasAcciones[7];

    Persona(){
        id = 0;
        name = "";
        apellido = "";
        pais = "";
        creencia = "";
        profesion = "";
        email = "";        
        for(int i = 0; i<7; i++){
            pecados[i] = new Pecado();
            buenasAcciones[i] = new BuenaAccion();
        }
    }
};

struct NodoPersona{
    Persona * persona;
    NodoPersona * siguiente, *anterior;

    NodoPersona(){
        persona = new Persona();
        siguiente = anterior = NULL;
    }

    NodoPersona(Persona * _persona){
        persona = _persona;
        siguiente = anterior = NULL;
    }
};

struct ListaDoblePersonas{
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;
    QString names[1000];
    QString lastNames[1000];

    ListaDoblePersonas(){
        primerNodo = ultimoNodo = NULL;
    }

    bool isEmpty();
    void insertarALInicio(NodoPersona * persona);
    void insertarAlFinal(NodoPersona * persona);
    void imprimir();
    void imprimirReverse();
    NodoPersona * borrarALInicio();
    NodoPersona * borrarALFinal();
    NodoPersona * buscar(NodoPersona * persona);
    void insertarEn(int index, NodoPersona * persona);
};

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

    void insertar (int, NodoPersona*);
    NodoPersonaArbol * insertar (int, NodoPersonaArbol*, NodoPersona*);

    void inOrden(NodoPersonaArbol*);
    void inOrdenClientes(NodoPersonaArbol*);
    void preOrden(NodoPersonaArbol*);
    void posOrden(NodoPersonaArbol*);
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
