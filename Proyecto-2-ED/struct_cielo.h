#ifndef STRUCT_CIELO_H
#define STRUCT_CIELO_H

#include "struct_personas.h"
#include <QString>
#include <QTextStream>
#include <QVector>

#include <QRandomGenerator>
#include <QString>


struct Angel{
    QString name;
    int version;
    int generacion;
    bool insertado;
    Persona  *persona;

    Angel(){
        name = "";
        version = 0;
        generacion = 0;
        insertado = false;
        persona = new Persona();
    }

    Angel(QString nombre, int _generacion,int _version, Persona *p){
        insertado = false;
        name = nombre;
        version = _version;
        generacion = _generacion;
        persona = p;
    }

    QString toString(){
        return "\nAngel: "+name
                +"\nVersión: "+QString::number(version)
                +"\nGeneración: "+QString::number(generacion);
    }

};

struct NodoArbolAngelesCielo{
    Angel * angel;
    NodoArbolAngelesCielo * izquierdo, *centro, *derecho;

    NodoArbolAngelesCielo(){
        angel = new Angel();
        izquierdo = centro = derecho = NULL;
    }
    NodoArbolAngelesCielo(Angel *a){
        angel =a;
        izquierdo = centro = derecho = NULL;
    }
};

struct ArbolAngelesCielo{
    NodoArbolAngelesCielo *raiz;
    int nivel;
    int cantUltimoNivel;

    ArbolAngelesCielo(){
        raiz = new NodoArbolAngelesCielo(new Angel("Dios", 0,1,new Persona()));

        raiz->izquierdo = new NodoArbolAngelesCielo(new Angel("Serafines", 1,1,new Persona()));
        raiz->centro = new NodoArbolAngelesCielo(new Angel("Querubines", 1,2,new Persona()));
        raiz->derecho = new NodoArbolAngelesCielo(new Angel("Tronos", 1,3,new Persona()));
        cantUltimoNivel = 3;
        nivel = 1;

    }

    void insertar(Angel *);
    NodoArbolAngelesCielo* insertar(NodoArbolAngelesCielo*, Angel*, QString*);

    void imprimirNivel(int nivel);
    void nivelImprimir(NodoArbolAngelesCielo *nodo , int nivel, int nivelActual);

};

struct NodoArbolCieloALV{
    Persona *persona;
    Angel *angel;
    NodoArbolCieloALV *l;
    NodoArbolCieloALV *r;


    NodoArbolCieloALV(){
        persona = new Persona();
        angel = new Angel();
        l = r = NULL;
    }
    NodoArbolCieloALV(Persona * _persona, Angel *_angel){
        persona = _persona;
        angel = _angel;
        l = r = NULL;
    }
};

struct ArbolCieloALV{
    NodoArbolCieloALV *raiz;
    int cant;

    ArbolCieloALV(){
        raiz =  NULL;
        cant = 0;
    }

    bool isEmpty();
    int height(NodoArbolCieloALV *t);
    int difference(NodoArbolCieloALV *t);
    NodoArbolCieloALV* rr_rotat(NodoArbolCieloALV *parent);
    NodoArbolCieloALV* ll_rotat(NodoArbolCieloALV *parent);
    NodoArbolCieloALV* lr_rotat(NodoArbolCieloALV *parent);
    NodoArbolCieloALV* rl_rotat(NodoArbolCieloALV *parent);
    NodoArbolCieloALV* balance(NodoArbolCieloALV *t);
    NodoArbolCieloALV* insert(Persona*, Angel*);
    NodoArbolCieloALV* insert(NodoArbolCieloALV *r, Persona*,Angel*);

    void imprimirNivel(int nivel);
    void nivelImprimir(NodoArbolCieloALV* , int , int);
    int treeHeight(NodoArbolCieloALV* nodo);

    void show(NodoArbolCieloALV *p, int l);

    void inOrder(NodoArbolCieloALV *t);
    void preOrder(NodoArbolCieloALV *t);
    void postOrder(NodoArbolCieloALV *t);

    QString* toStringInOrden();
    void toStringInOrden(NodoArbolCieloALV*, QString*);

    QString* toStringInOrdenBA();
    void toStringInOrdenBA(NodoArbolCieloALV*, QString*);

    QString* toStringInOrdenP();
    void toStringInOrdenP(NodoArbolCieloALV*, QString*);

    void bubbleSortPecados(NodoPersona *[]);

    void cantPecadosBA(int arr[],int arr2[]);
    void cantPecadosBA(NodoArbolCieloALV *t, int arr[], int arr2[]);

};

struct CieloHash{
    ArbolCieloALV *hashTableCielo[1000];
    CieloHash(){
        for(int i = 0; i<1000; i++)
            hashTableCielo[i] = new ArbolCieloALV();
    }

    int funcioHash(Persona* persona){
        return persona->id% 1000;
    }

    void insertar(Persona *persona, Angel *angel){
        hashTableCielo[funcioHash(persona)]->insert(persona, angel);
    }
    void imprimir(){
        hashTableCielo[0]->inOrder(hashTableCielo[0]->raiz);
        /*for(int i = 0; i<1000; i++)
            hashTableCielo[i]->inOrder(hashTableCielo[i]->raiz);*/
    }
    QString toString(){
        QString dato = "";
        for(int i = 0; i<1000; i++)
            dato +=  "\n\nPosicion: "+QString::number(i)+"\n"+ *hashTableCielo[i]->toStringInOrden();
        return dato;
    }

    int calcularNeto(QLabel *, QLabel *);
};

#endif // STRUCT_CIELO_H
