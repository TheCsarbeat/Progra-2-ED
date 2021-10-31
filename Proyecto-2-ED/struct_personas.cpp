#include "struct_personas.h"

//------------------------- ARbol--------------------------------------
void ArbolPersonas::insertar(int dato, NodoPersona* nodoListaPersona){
     raiz = insertar(dato, raiz, nodoListaPersona);
     cantElementos++;
}

//  INSERTA RECURSIVAMENTE
NodoPersonaArbol* ArbolPersonas::insertar(int valor, NodoPersonaArbol* nodo, NodoPersona* nodoListaPersona){
    if (nodo == NULL){
        return new NodoPersonaArbol(nodoListaPersona);

    }else if (nodo->nodoPersona->persona->id < valor){
        nodo->hijoderecho = insertar(valor, nodo->hijoderecho, nodoListaPersona);

    }else if (nodo->nodoPersona->persona->id >= valor){
        nodo->hijoizquierdo = insertar(valor, nodo->hijoizquierdo, nodoListaPersona);
    }
    return nodo;
}
