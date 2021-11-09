#include "struct_personas.h"

bool ListaDoblePersonas::isEmpty(){
    return primerNodo == NULL;
}

bool ListaDoblePersonas::insertar(Persona * persona){
    NodoPersona *nuevo = new NodoPersona(persona);
    if (isEmpty()){
        primerNodo = ultimoNodo = nuevo;

    }else{
        NodoPersona *temp = primerNodo;
        while (temp->persona->id < persona->id){
            temp = temp->siguiente;
            if(temp == NULL) break;
        }
        if(temp == NULL){
            ultimoNodo->siguiente = nuevo;
            nuevo->anterior = ultimoNodo;
            ultimoNodo = nuevo;

        }else if(temp->persona->id == persona->id){
            qDebug()<<temp->persona->id;
            delete(persona);
            delete(nuevo);
            return false;
        }else{
            if(temp == primerNodo){
                primerNodo->anterior = nuevo;
                nuevo->siguiente = primerNodo;
                primerNodo = nuevo;
            }else{
                nuevo->siguiente = temp;
                nuevo->anterior = temp->anterior;
                temp->anterior->siguiente = nuevo;
                temp->anterior = nuevo;
            }
        }
    }
    largo++;
    return true;

}

void ListaDoblePersonas::imprimir(){
    NodoPersona * temp = primerNodo;
    while (temp != NULL){
        temp->persona->imprimir();
        temp = temp->siguiente;
    }
    qDebug()<<"\n\nLargo: "<<largo;
}







//===============================================TREE==============================================================================

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
//  VACIAR EL: ARBOL
void ArbolPersonas::vaciarArbol(){
    vaciarArbol(raiz);
     raiz = NULL;
     cantElementos = 0;
}


void ArbolPersonas::vaciarArbol(NodoPersonaArbol* nodo){
    if (nodo != NULL){
        vaciarArbol(nodo->hijoizquierdo);
        vaciarArbol(nodo->hijoderecho);
        nodo = NULL;
        delete(nodo);
    }
}


//BUSCAR EL MAS CERCANO
NodoPersona* ArbolPersonas::buscarMasCercano(int datoID){
    if (raiz != NULL)return NULL;

    /*if(raiz->nodoPersona->persona->id == dato)return raiz->nodoPersona;

    else if(raiz->nodoPersona->persona->id < dato){
        return buscarMasCercano(dato,'d', abs(raiz->nodoPersona->persona->id - dato), raiz->hijoderecho)->nodoPersona;
    }else{
        return buscarMasCercano(dato,'i', abs(raiz->nodoPersona->persona->id - dato), raiz->hijoizquierdo)->nodoPersona;
    }*/

    buscarMasCercano(raiz, datoID);
}

NodoPersonaArbol* ArbolPersonas::diferencia(NodoPersonaArbol * nodo1, NodoPersonaArbol * nodo2, int dato){
    int diferencia1 = abs(nodo1->nodoPersona->persona->id - dato);
    int diferencia2 = abs(nodo2->nodoPersona->persona->id - dato);

    if(diferencia1 < diferencia2)        return nodo1;
    else       return nodo2;
}

NodoPersonaArbol* ArbolPersonas::buscarMasCercano(NodoPersonaArbol * raizNodo,int datoID){

    if(raizNodo->hijoizquierdo != NULL  &&  raizNodo->hijoderecho != NULL){
       return diferencia(raizNodo,buscarMasCercano(diferencia(raizNodo->hijoizquierdo, raizNodo->hijoderecho,datoID),datoID), datoID);

    }else{
        return raizNodo;
    }

}


void ArbolPersonas::posOrden(NodoPersonaArbol* nodo)
{
   if (nodo != NULL)
   {
     posOrden(nodo->hijoizquierdo);
     posOrden(nodo->hijoderecho);
     qDebug() << nodo->nodoPersona->persona->id << "  ";

   }
}
