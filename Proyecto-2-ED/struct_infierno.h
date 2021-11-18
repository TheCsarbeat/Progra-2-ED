#ifndef STRUCT_INFIERNO_H
#define STRUCT_INFIERNO_H

#include <QString>
#include <QCoreApplication>
#include <QVector>

#include "struct_arbolfamilias.h"

struct Infierno;
struct Demonio;
struct HeapFamilias;
struct NodoListaSimpleHeaps;
struct ListaSimpleHeaps;
struct NodoHeap;

struct NodoHeap{
    Persona * persona;

    NodoHeap(){
        persona = NULL;
    }
    NodoHeap(Persona * _persona){
        persona = _persona;
    }
};

struct HeapFamilia{
    int capacidad;
    int cant;
    int pecado;
    QString apellido;
    QString pais;
    QVector<NodoHeap*> array;

    HeapFamilia(){
        capacidad = 0;
        pecado = -1;
        cant = 0;
    }
    HeapFamilia(int _pecado){
        capacidad = 0;
        pecado = _pecado;
        cant = 0;
    }

    void swap(NodoHeap *, NodoHeap *);

    int parent(int i) {
        return (i - 1) / 2;
    }

    // return left child of `A[i]`
    int left(int i) {
        return (2*i + 1);
    }

    // return right child of `A[i]`
    int right(int i) {
        return (2*i + 2);
    }

    void heapifyUp(int i);
    void insertar(Persona *);
    void imprimir();
};

struct NodoListaSimpleHeaps{
    HeapFamilia * heap;
    NodoListaSimpleHeaps * siguiente;

    NodoListaSimpleHeaps(){
        heap = new HeapFamilia();
        siguiente = NULL;
    }
    NodoListaSimpleHeaps(HeapFamilia * _heap){
        heap = _heap;
        siguiente = NULL;
    }
};

struct ListaSimpleHeaps{
    NodoListaSimpleHeaps * primerNodo;
    NodoListaSimpleHeaps * ultimoNodo;
    int largo;

    ListaSimpleHeaps(){
        primerNodo = ultimoNodo = NULL;
        largo = 0;
    }
    bool isEmpy();
    void imprimir();
    void insertarAlInicio(HeapFamilia *);
    void deleteAllNodes();
};

struct Demonio{
    QString name;
    int pecado;
    ListaSimpleHeaps * listaHeaps;
    Demonio(){
        name = "";
        pecado = -1;
        listaHeaps = new ListaSimpleHeaps();
    }
    Demonio(QString _name,int _pecado){
        name = _name;
        pecado = _pecado;
        listaHeaps = new ListaSimpleHeaps();
    }

    void crearHeap(ListaSimpleArbolFamilias *);
    void limpiarListaHeaps();
    void buscarMasPecadores(ListaDoblePersonas *, QVector<NodoHeap*>);
    void agregarAHeaps(QVector<Persona*>);
};

struct Infierno{
    Demonio * demonios[7];
    QVector<NodoHeap*> arrayPersonasInfierno;

    Infierno(){
        QString names[7] = {"Asmodeo","Belfegor","Mammón","Abadón","Satán","Belcebú","Lucifer"};
        int pecados[7] = {0,1,2,3,4,5,6};
        for(unsigned int i=0;i<7;i++){
            demonios[i]= new Demonio(names[i],pecados[i]);
        }

    }

    void imprimirDemonio(int);
    void crearHeapsDemonios(ListaSimpleArbolFamilias *);
    void limpiarDemonios();
    void matarMasPecadores(ListaDoblePersonas *);
    void llenarArray(ListaDoblePersonas *);
};

#endif // STRUCT_INFIERNO_H
