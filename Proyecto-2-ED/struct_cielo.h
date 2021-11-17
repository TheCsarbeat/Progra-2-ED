#ifndef STRUCT_CIELO_H
#define STRUCT_CIELO_H
#include "struct_arbolfamilias.h"

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

struct CieloHash{
    ArbolFamilias *hashTableCielo[1000];
    CieloHash(){
        for(int i = 0; i<1000; i++)
            hashTableCielo[i] = new ArbolFamilias();
    }

    int funcioHash(Persona* persona){
        return persona->id% 1000;
    }

    void insertar(Persona *persona){
        hashTableCielo[funcioHash(persona)]->insertSinHijos(persona);
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
};

#endif // STRUCT_CIELO_H
