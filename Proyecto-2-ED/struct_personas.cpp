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

bool ListaDoblePersonas::insertar(Persona * persona, NodoPersona * masCernano){
    NodoPersona *nuevo = new NodoPersona(persona);
    bool flagTempNULL = true;
    bool flagAnterior = false;
    if (isEmpty()){
        primerNodo = ultimoNodo = nuevo;
    }else{
        NodoPersona *temp = masCernano;
        if(masCernano->persona->id < persona->id){
            while (temp->persona->id < persona->id){
                temp = temp->siguiente;
                if(temp == NULL) break;
            }
        }else{
            while (temp->persona->id > persona->id){
                temp = temp->anterior;
                if(temp == NULL){
                    flagTempNULL= false;
                    break;
                }
            }
            flagAnterior = true;
        }
        if(temp == NULL){
            if(flagTempNULL){
                ultimoNodo->siguiente = nuevo;
                nuevo->anterior = ultimoNodo;
                ultimoNodo = nuevo;
            }else{
                primerNodo->anterior = nuevo;
                nuevo->siguiente = primerNodo;
                primerNodo = nuevo;
            }
        }else if(temp->persona->id == persona->id){
            return false;
        }else{
            if(flagAnterior)temp=temp->siguiente;
            nuevo->siguiente = temp;
            nuevo->anterior = temp->anterior;
            temp->anterior->siguiente = nuevo;
            temp->anterior = nuevo;
        }
    }
    largo++;
    return true;
}

void ListaDoblePersonas::imprimir(){
    NodoPersona * temp = primerNodo;
    int cont =0;
    qDebug()<<"[";
    while (temp != NULL){
        //temp->persona->imprimir();
        //qDebug()<<"Posicion en lista: "<<cont;
        qDebug()<<temp->persona->id<<", ";
        cont++;
        temp = temp->siguiente;
    }
              qDebug()<<"]";
   // qDebug()<<"\nLargo: "<<largo;
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
    if (raiz == NULL)return NULL;

    /*if(raiz->nodoPersona->persona->id == dato)return raiz->nodoPersona;

    else if(raiz->nodoPersona->persona->id < dato){
        return buscarMasCercano(dato,'d', abs(raiz->nodoPersona->persona->id - dato), raiz->hijoderecho)->nodoPersona;
    }else{
        return buscarMasCercano(dato,'i', abs(raiz->nodoPersona->persona->id - dato), raiz->hijoizquierdo)->nodoPersona;
    }*/

    return buscarMasCercano(raiz, datoID)->nodoPersona;


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

void ArbolPersonas::imprimir(NodoPersonaArbol* nodo){
   if (nodo != NULL) {
     posOrden(nodo->hijoizquierdo);
     posOrden(nodo->hijoderecho);
     qDebug() << nodo->nodoPersona->persona->creencia << "  ";
   }
}

void ArbolPersonas::posOrden(NodoPersonaArbol* nodo){
   if (nodo != NULL) {
     posOrden(nodo->hijoizquierdo);
     posOrden(nodo->hijoderecho);
     qDebug() << nodo->nodoPersona->persona->creencia << "  ";

   }
}

void ArbolPersonas::preOrden(NodoPersonaArbol* nodo){
   if (nodo != NULL)   {
     qDebug() << "Posici[on: "<<nodo->nodoPersona->persona->creencia << ", ID:"<<nodo->nodoPersona->persona->id;
     preOrden(nodo->hijoizquierdo);
     preOrden(nodo->hijoderecho);
   }
}
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int ArbolPersonas::treeHeight(NodoPersonaArbol* nodo){
     if (nodo == NULL) // Árbol vacío, devuelve 0
        return 0;
     if (nodo->hijoizquierdo == NULL && nodo->hijoderecho == NULL) // La raíz del árbol devuelve 1
        return 1;
     return max (treeHeight (nodo-> hijoizquierdo), treeHeight (nodo-> hijoderecho)) + 1; // La altura del árbol = MAX (la altura del subárbol izquierdo, la altura del subárbol derecho) + 1;
}

int ArbolPersonas::cantNodos(NodoPersonaArbol* nodo){
    if (nodo == NULL)
        return 0;
    return 1 + cantNodos(nodo->hijoizquierdo)+cantNodos(nodo->hijoderecho);
}

