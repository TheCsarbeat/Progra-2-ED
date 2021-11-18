#ifndef STRUCT_PERSONAS_H
#define STRUCT_PERSONAS_H

#include "struct_file.h"

#include <QString>
#include <QDateTime>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QLabel>
struct Pecado;
struct BuenaAccion;
struct Persona;
struct NodoPersona;
struct ListaDoblePersonas;
struct NodoPersonaArbol;
struct ArbolPersonas;

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

    void imprimir();

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

    void imprimir();

};

struct Persona{
    int id;
    QString name;
    QString apellido;
    Pais* pais;
    QString creencia;
    QString profesion;
    QString email;
    QDateTime nacimiento;
    Pecado * pecados[7];
    BuenaAccion * buenasAcciones[7];
    Persona * padre;
    ListaDoblePersonas *hijos;
    int estado; //0=Vivo, 1=Infierno, 2=Cielo
    Persona(){
        id = 0;
        name = "";
        apellido = "";
        pais = new Pais();
        creencia = "";
        profesion = "";
        email = "ytcesarjs@gmail.com";
        nacimiento = QDateTime::currentDateTime();
        estado = 0;
        for(int i = 0; i<7; i++){
            pecados[i] = new Pecado(); //se debe asignar el nombre del pecado según la posición ya que por el momento está vacío, lo mismo con las buenas acciones
            buenasAcciones[i] = new BuenaAccion();
        }
        padre = NULL;
        hijos = NULL;
    }

    Persona(int _id, QString _name, QString _apellido, Pais* _pais, QString _creencia, QString _profesion){
        id = _id;
        name = _name;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        email = "erksmartinez2014@gmail.com";
        nacimiento = QDateTime::currentDateTime();
        estado = 0;
        QString arrayNamePecado[7] = {"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
        QString arrayNameBuenas[7] = {"Castidad","Ayuno","Donación","Diligencia","Calma","Solidaridad","Humildad"};
        for(int i = 0; i<7; i++){
            pecados[i] = new Pecado();
            pecados[i]->name = arrayNamePecado[i];

            buenasAcciones[i] = new BuenaAccion();
            buenasAcciones[i]->name = arrayNameBuenas[i];
        }
        padre = NULL;
        hijos = NULL;
    }

    void imprimir(){
        qDebug()<<"\n-----------------\nID: "<<id<<"\nNombre: "<<name<<"\nApellido: "<<apellido<<"\nContador: "<<creencia;        
    }

    void imprimirPecados(){
        for(unsigned int i=0;i<7;i++){
            pecados[i]->imprimir();
        }
    }

    void imprimirBuenasAcciones(){
        for(unsigned int i=0;i<7;i++){
            buenasAcciones[i]->imprimir();
        }
    }

    QString toString();
    int calcularPecado(int);
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
    bool insertar(Persona * persona, NodoPersona * masCernano);
    void buscar(int);
    NodoPersona * buscar(int id,NodoPersona * masCercano);


    void imprimir();
    void insertarALInicio(NodoPersona * persona);
    void insertarAlFinal(NodoPersona * persona);

    void imprimirReverse();
    NodoPersona * borrarALInicio();
    NodoPersona * borrarALFinal();


    void insertarEn(int index, NodoPersona * persona);

    void toString();



    QString toStringIDHijos(){
        QString dato;
        NodoPersona * temp = primerNodo;
        while (temp != NULL){
            dato += "\n\t"+QString::number(temp->persona->id);
            temp = temp->siguiente;
        }
        dato+="\n------------------------------------------------------------------\n";
        return dato;
    }
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

    QString* toStringHojas();
    void toStringHojas(NodoPersonaArbol*, QString*);

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
