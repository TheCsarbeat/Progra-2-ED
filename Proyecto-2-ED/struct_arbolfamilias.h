#ifndef STRUCT_ARBOLFAMILIAS_H
#define STRUCT_ARBOLFAMILIAS_H

#include "struct_personas.h"
#include <QString>
#include <QTextStream>

#include <QRandomGenerator>
#include <QString>

struct NodoArbolFamiliaALV{
    Persona *persona;
    NodoArbolFamiliaALV *l;
    NodoArbolFamiliaALV *r;

    NodoArbolFamiliaALV(){
        persona = new Persona();
        l = r = NULL;
    }
    NodoArbolFamiliaALV(Persona * _persona){
        persona = _persona;
        l = r = NULL;
    }
};

struct ArbolFamilias{
    NodoArbolFamiliaALV *raiz;


    ArbolFamilias(){
        raiz =  NULL;
    }

    bool isEmpty();
    int height(NodoArbolFamiliaALV *t);
    int difference(NodoArbolFamiliaALV *t);
    NodoArbolFamiliaALV* rr_rotat(NodoArbolFamiliaALV *parent);
    NodoArbolFamiliaALV* ll_rotat(NodoArbolFamiliaALV *parent);
    NodoArbolFamiliaALV* lr_rotat(NodoArbolFamiliaALV *parent);
    NodoArbolFamiliaALV* rl_rotat(NodoArbolFamiliaALV *parent);
    NodoArbolFamiliaALV* balance(NodoArbolFamiliaALV *t);
    NodoArbolFamiliaALV* insert(Persona*);
    NodoArbolFamiliaALV* insert(NodoArbolFamiliaALV *r, Persona*);

    NodoArbolFamiliaALV* insertSinHijos(Persona*);
    NodoArbolFamiliaALV* insertSinHijos(NodoArbolFamiliaALV *r, Persona*);

    void asignarHijos(Persona *persona);
    int asignarHijos(Persona *persona, NodoArbolFamiliaALV *t, int);

    void imprimirNivel(int nivel);
    void nivelImprimir(NodoArbolFamiliaALV* , int , int);
    int treeHeight(NodoArbolFamiliaALV* nodo);

    void show(NodoArbolFamiliaALV *p, int l);

    void inOrder(NodoArbolFamiliaALV *t);
    void preOrder(NodoArbolFamiliaALV *t);
    void postOrder(NodoArbolFamiliaALV *t);

    void getNodesInList(NodoArbolFamiliaALV *, ListaDoblePersonas *);
    ListaDoblePersonas * getNodesInList();
    int getTotalPecado(int);
    int getTotalPecadoAux(NodoArbolFamiliaALV*,int);

    QString* toStringInOrden();
    void toStringInOrden(NodoArbolFamiliaALV*, QString*);

    QString* toStringInOrdenBA();
    void toStringInOrdenBA(NodoArbolFamiliaALV*, QString*);
};

struct NodoFamiliaListaSimple{
    ArbolFamilias * arbol;
    NodoFamiliaListaSimple * siguiente;
    NodoFamiliaListaSimple(){
        arbol = new ArbolFamilias();
        siguiente  =NULL;
    }
    NodoFamiliaListaSimple(ArbolFamilias * _persona){
        arbol = _persona;
        siguiente = NULL;
    }

    NodoFamiliaListaSimple(Persona* p){
        arbol = new ArbolFamilias();
        arbol->insert(p);
        siguiente = NULL;
    }


};

struct ListaSimpleArbolFamilias{
    NodoFamiliaListaSimple * primerNodo;
    NodoFamiliaListaSimple * ultimoNodo;
    int largo;
    ListaSimpleArbolFamilias(){
        primerNodo = ultimoNodo = NULL;
        largo = 0;
    }
    bool isEmpy();
    void imprimir();

    QString toString(){
        QString dato = "";
        NodoFamiliaListaSimple * temp = primerNodo;
        int cont =0;
        while (temp != NULL){
            dato += "\n\n\nFamilia: "+QString::number(cont)+"\n";
            dato += *temp->arbol->toStringInOrden();
            cont++;
            temp = temp->siguiente;
        }
        dato += "\n\nLargo: "+QString::number(largo);
        return dato;
    }
    void insertarALInicio(Persona *);
    NodoFamiliaListaSimple * buscar(Persona * );

    //no funciona
    NodoFamiliaListaSimple * buscar(int);
};


#endif // STRUCT_ARBOLFAMILIAS_H
