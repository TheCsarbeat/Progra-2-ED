#include "struct_infierno.h"

//==================================HEAPFAMILIAS===================================

void HeapFamilia::swap(NodoHeap * a1, NodoHeap * a2){
    NodoHeap temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
//sigue cambiar que el heap ordene a las personas por el pecado que es
void HeapFamilia::heapifyUp(int i){
    // check if the node at index `i` and its parent violate the heap property
    int parent1 = parent(i);
    if (i >= 0 && parent(i) >= 0 && array[parent(i)]->persona->pecados[pecado]->cant < array[i]->persona->pecados[pecado]->cant){
        // swap the two if heap property is violated
        swap(array[i],array[parent(i)]);
        // call heapify-up on the parent
        heapifyUp(parent(i));
    }
}

void HeapFamilia::insertar(Persona * nuevo){
    array.push_back(new NodoHeap(nuevo));
    cant++;
    int i = cant - 1;
    heapifyUp(i);
}

void HeapFamilia::imprimir(){
    for(int i=0;i<cant;i++){
        array[i]->persona->imprimir();
        array[i]->persona->pecados[pecado]->imprimir();
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
            listaHeaps->primerNodo->heap->insertar(p->persona);
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

void Demonio::bubblesortDemon(QVector<NodoHeap*> * list){

}

void Demonio::buscarMasPecadores(ListaDoblePersonas * list){
    int limite = list->largo * 0.05;
    QVector<NodoHeap*> todosOrdenados;
    QVector<Persona*> top5;
    NodoPersona * p = list->primerNodo;
    while(p!=NULL){
        todosOrdenados.push_back(new NodoHeap(p->persona));
        p = p->siguiente;
    }
    NodoHeap * tmp = new NodoHeap();
    for(int i = 0; i<todosOrdenados.size(); i++){
        for(int j = i+1; j<todosOrdenados.size(); j++){
            if(todosOrdenados[j]->persona->calcularPecado(pecado) > todosOrdenados[i]->persona->calcularPecado(pecado)){
                 *tmp = *todosOrdenados[i];
                 *todosOrdenados[i] = *todosOrdenados[j];
                 *todosOrdenados[j] = *tmp;
            }
        }
    }
    delete tmp;
    for(int i=0;i<limite;i++){
        top5.push_back(todosOrdenados[i]->persona);
    }
    agregarAHeaps(top5);
}

void Demonio::agregarAHeaps(QVector<Persona*> list){
    NodoListaSimpleHeaps * nodo = listaHeaps->primerNodo;
    bool flag = false;
    for(int i=0;i<list.size();i++){
        flag = false;
        nodo = listaHeaps->primerNodo;
        while(nodo!=NULL){
            if(list[i]->apellido == nodo->heap->apellido && list[i]->pais->name == nodo->heap->pais){
                flag = true;
                nodo->heap->insertar(list[i]);
            }
            nodo = nodo->siguiente;
        }
        if(flag == false){
            listaHeaps->insertarAlInicio(new HeapFamilia(pecado));
            listaHeaps->primerNodo->heap->apellido = list[i]->apellido;
            listaHeaps->primerNodo->heap->pais = list[i]->pais->name;
            listaHeaps->primerNodo->heap->insertar(list[i]);
        }
    }
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

