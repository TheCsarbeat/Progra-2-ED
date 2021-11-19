#include "struct_infierno.h"

QString convertPecadoToString(int i){
    QString pecados[] = {"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    return pecados[i];
}

QString convertBuenaAccionToString(int i){
    QString buenasAcciones[] = {"Castidad","Ayuno","Donación","Diligencia","Calma","Solidaridad","Humildad"};
    return buenasAcciones[i];
}

QString convertDemonioToString(int i){
    QString demonios[] = {"Asmodeo","Belfegor","Mammón","Abadón","Satán","Belcebú","Lucifer"};
    return demonios[i];
}

//==================================HEAPFAMILIAS===================================

void HeapFamilia::swap(NodoHeap * a1, NodoHeap * a2){
    NodoHeap temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
//sigue cambiar que el heap ordene a las personas por el pecado que es
void HeapFamilia::heapifyUp(int i){
    // check if the node at index `i` and its parent violate the heap property
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

void Demonio::swap(NodoHeap * a1, NodoHeap * a2){
    NodoHeap temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

int Demonio::partition(NodoHeap * list[], int low, int high){
    int pivot = list[high]->persona->calcularPecado(pecado);
        int i = (low - 1);
        for (int j = low; j <= high- 1; j++)
        {
            if (list[j]->persona->calcularPecado(pecado) <= pivot)
            {
                i++;
                swap(list[i], list[j]);
            }
        }
        swap(list[i + 1], list[high]);
        return (i + 1);
}

void Demonio::quickSort(NodoHeap * list[], int low, int high){
    if (low < high)
        {
            int pi = partition(list, low, high);
            quickSort(list, low, pi - 1);
            quickSort(list, pi + 1, high);
        }
}

void Demonio::generateLog(QString * log, Persona * array[], int limite){
    QDateTime date = QDateTime::currentDateTime();
    for(int i=0;i<limite;i++){
        *log += "\n"+date.toString()+" Humano #"+QString::number(array[i]->id)
                +" "+array[i]->name+" "+array[i]->apellido+" Murió en "+date.toString("yyyy-MM-dd")
                +" condenado por "+QString::number(array[i]->pecados[pecado]->cant)+" pecados de "
                +convertPecadoToString(pecado)+" y "+QString::number(array[i]->buenasAcciones[pecado]->cant)
                +" acciones de "+convertBuenaAccionToString(pecado)+" por el demonio "+convertDemonioToString(pecado);
   }
}

void Demonio::buscarMasPecadores(NodoHeap * array[], int largo, QString * log){
    int limite = largo * 0.05;
    Persona * top5[limite];
    quickSort(array,0,largo-1);
    int i = 0;
    for(int j=largo-1;i<limite;j--){
        if(array[j]->persona->estado == 0){
            top5[i] = array[j]->persona;
            array[j]->persona->estado = 1;
            i++;
        }
    }
    generateLog(log, top5, limite);
    agregarAHeaps(top5, limite);
}

void Demonio::agregarAHeaps(Persona * list[], int size){
    NodoListaSimpleHeaps * nodo = listaHeaps->primerNodo;
    bool flag = false;
    for(int i=0;i<size;i++){
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

void Infierno::matarMasPecadores(ListaDoblePersonas * list, Files * file){
    int largo = list->largo;
    NodoHeap * arrayPersonasInfierno[largo];
    NodoPersona * p = list->primerNodo;
    int cont = 0;
    while(p!=NULL){
        arrayPersonasInfierno[cont] = new NodoHeap(p->persona);
        p = p->siguiente;
        cont++;
    }
    for(int i=0;i<7;i++){
        demonios[i]->buscarMasPecadores(arrayPersonasInfierno, largo, &log);
    }
    QDateTime date = QDateTime::currentDateTime();
    QString name = "Condenados_"+date.toString("yyyyMMdd")+"_"+date.toString("HHmmss")+".txt";
    file->writeFile(name,log);
}
