#include "struct_infierno.h"

//==================================HEAPFAMILIAS===================================

void HeapFamilia::swap(int a1, int a2){
    Persona temp = array[a1];
    array[a1] = array[a2];
    array[a2] = temp;
}
//sigue cambiar que el heap ordene a las personas por el pecado que es
void HeapFamilia::heapifyUp(int i){
    // check if the node at index `i` and its parent violate the heap property
    int parent1 = parent(i);
    if (i >= 0 && parent(i) >= 0 && array[parent(i)].pecados[pecado]->cant < array[i].pecados[pecado]->cant){
        // swap the two if heap property is violated
        swap(i,parent(i));
        // call heapify-up on the parent
        heapifyUp(parent(i));
    }

}

void HeapFamilia::insertar(Persona nuevo){
    array.push_back(nuevo);
    cant++;
    int i = cant - 1;
    heapifyUp(i);
}

void HeapFamilia::imprimir(){
    for(int i=0;i<cant;i++){
        array[i].imprimir();
        array[i].pecados[pecado]->imprimir();
        qDebug()<<"\n"<<cant;
    }
}
//==================================LISTA-SIMPLE-HEAPS===================================

bool ListaSimpleHeaps::isEmpy(){
    return primerNodo == NULL;
}

void ListaSimpleHeaps::insertarAlInicio(HeapFamilia * heap){
    if(isEmpy()){
        primerNodo = new NodoListaSimpleHeaps(heap);
    }else{
        NodoListaSimpleHeaps *nuevo = new NodoListaSimpleHeaps(heap);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
    largo++;
}

void ListaSimpleHeaps::deleteAllNodes(){
    NodoListaSimpleHeaps * tmp;
    while(primerNodo!=NULL){
        tmp = primerNodo;
        primerNodo = primerNodo->siguiente;
        delete tmp;
    }
    largo = 0;
}

void ListaSimpleHeaps::imprimir(){
    NodoListaSimpleHeaps * tmp = primerNodo;
    int i =0;
    while(tmp!=NULL){
        qDebug()<<"\n\nFamilia "<<i;
        tmp->heap->imprimir();
        tmp = tmp->siguiente;
        i++;
    }
}

//==================================DEMONIO===================================
void Demonio::crearHeap(ListaSimpleArbolFamilias * listaArboles){
    NodoFamiliaListaSimple * tmp = listaArboles->primerNodo;
    ListaDoblePersonas * lista;
    NodoPersona * p;
    while(tmp!=NULL){
        listaHeaps->insertarAlInicio(new HeapFamilia(pecado));
        lista = tmp->arbol->getNodesInList();
        p = lista->primerNodo;
        while(p!=NULL){
            listaHeaps->primerNodo->heap->insertar(*(p->persona));
            p = p->siguiente;
        }
        tmp = tmp->siguiente;
    }
}

void Demonio::limpiarListaHeaps(){
    NodoListaSimpleHeaps * tmp = listaHeaps->primerNodo;
    while(tmp!=NULL){
        tmp->heap->array.clear();
        delete tmp->heap;
        tmp = tmp->siguiente;
    }
    listaHeaps->deleteAllNodes();
}

//==================================INFIERNO===================================
void Infierno::imprimirDemonio(int id){
    for(int i=0;i<7;i++){
        if(i==id){
            demonios[i]->listaHeaps->imprimir();
            return;
        }
    }
}
//imprimir arbol
void Infierno::crearHeapsDemonios(ListaSimpleArbolFamilias * lista){
    for(int i=0;i<7;i++){
        demonios[i]->crearHeap(lista);
    }
}

void Infierno::limpiarDemonios(){
    for(int i=0;i<7;i++){
        demonios[i]->limpiarListaHeaps();
    }
}

