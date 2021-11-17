#include "struct_cielo.h"

void ArbolAngelesCielo::insertar(Angel *a){
    QString *insertado = new QString;
    *insertado = "";
    raiz= insertar(raiz, a, insertado);
}

NodoArbolAngelesCielo* ArbolAngelesCielo::insertar(NodoArbolAngelesCielo * nodo, Angel* a, QString *insertado){

    if (nodo == NULL){
        a->insertado = true;
        return new NodoArbolAngelesCielo(a);
    }else if (nodo->angel->generacion < a->generacion-1){

        if(a->insertado) return nodo;
        nodo->izquierdo = insertar(nodo->izquierdo,a, 0);

        if(a->insertado) return nodo;
        nodo->centro =  insertar(nodo->centro,a, 0);

        if(a->insertado) return nodo;
        nodo->derecho = insertar(nodo->derecho, a, 0);

    }else if(nodo->angel->generacion == a->generacion-1 && nodo->angel->version*3 >= a->version){
        if(nodo->izquierdo ==NULL)
            nodo->izquierdo = insertar(nodo->izquierdo,a, 0);

        else if(nodo->centro == NULL && nodo->izquierdo->angel != a)
            nodo->centro = insertar(nodo->centro,a, 0);

        else if(nodo->derecho ==NULL && nodo->izquierdo->angel != a && nodo->centro->angel != a)
            nodo->derecho= insertar(nodo->derecho,a, 0);
    }
    return nodo;
}

void ArbolAngelesCielo::imprimirNivel(int nivel){
    nivelImprimir(raiz, nivel, 0);
}

void ArbolAngelesCielo::nivelImprimir(NodoArbolAngelesCielo *nodo , int nivel, int nivelActual){
    if (nodo != NULL)   {
        //cout<<"|"<<nivel<<", "<<nivelActual<<"|";
        if( nivel == nivelActual){
            qDebug() <<"Nombre: "<<nodo->angel->name<<"Version: "<< nodo->angel->version<< ", Generacion: "<<nodo->angel->generacion;
        }else if(nivel>nivelActual){
            nivelImprimir(nodo->izquierdo, nivel,nivelActual+1);
            nivelImprimir(nodo->centro, nivel,nivelActual+1);
            nivelImprimir(nodo->derecho , nivel,nivelActual+1);
        }
   }
}
