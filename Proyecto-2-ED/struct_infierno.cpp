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
    if(cant>0){
        if (i >= 0 && parent(i) >= 0 && array[parent(i)]->persona->pecados[pecado]->cant < array[i]->persona->pecados[pecado]->cant){
            swap(array[i],array[parent(i)]);
            heapifyUp(parent(i));
        }
    }
}

void HeapFamilia::heapifyDown(int i){
    int leftChild = left(i);
    int rightChild = right(i);
    int largest = i;
    if(leftChild < array.size() && array[leftChild]->persona->pecados[pecado]->cant > array[i]->persona->pecados[pecado]->cant){
        largest = leftChild;
    }
    if(rightChild < array.size() && array[rightChild]->persona->pecados[pecado]->cant > array[largest]->persona->pecados[pecado]->cant){
        largest = rightChild;
    }
    if(largest != i){
        swap(array[i],array[largest]);
        heapifyDown(largest);
    }
}

void HeapFamilia::insertar(Persona * nuevo){
    array.push_back(new NodoHeap(nuevo));
    cant++;
    int i = cant - 1;
    heapifyUp(i);
}

void HeapFamilia::deleteAtPosition(int index){
    array[index] = array.back();
    array.pop_back();
    cant--;
    if(cant > index){
        heapifyDown(index);
        heapifyUp(index);
    }
}

QString HeapFamilia::imprimir(){
    QString heap = "";
    for(int i=0;i<cant;i++){
        heap += "\n";
        heap += array[i]->persona->toStringsimplified();
    }
    return heap;
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

QString ListaSimpleHeaps::imprimir(){
    NodoListaSimpleHeaps * tmp = primerNodo;
    int i =0;
    QString heaps;
    while(tmp!=NULL){
        heaps +="\n--------------------------------------------------";
        heaps += "\n\nHeap "+QString::number(i);
        heaps += tmp->heap->imprimir();
        tmp = tmp->siguiente;
        i++;
    }
    return heaps;
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

void Demonio::buscarMasPecadores(NodoHeap * array[], int largo, QString * log, int * totalPeople, int aMatar){
    int limite = aMatar;
    Persona * top5[limite];
    quickSort(array,0,largo-1);
    int i = 0;
    for(int j=largo-1;i<limite;j--){
        if(array[j]->persona->estado == 0){
            if(array[j]->persona->pecados[pecado]->cant > pecadoMayor){
                pecadoMayor = array[j]->persona->pecados[pecado]->cant;
            }
            if(array[j]->persona->pecados[pecado]->cant < pecadoMenor){
                pecadoMenor = array[j]->persona->pecados[pecado]->cant;
            }
            top5[i] = array[j]->persona;
            array[j]->persona->estado = 1;
            i++;
        }
    }
    cantPersonas+=limite;
    *totalPeople += limite;
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

QString Demonio::consulta(){
    QString consulta = "\n\n=================================================\n                  Demonio: "
            +convertDemonioToString(pecado)+"\n=================================================\nPecado: "
            +convertPecadoToString(pecado)
            +"\nCantidad de humanos: "+QString::number(cantPersonas)
            +"\nPromedio de pecados de "+convertPecadoToString(pecado)+": "
            +QString::number(getPromedioPecados())+"\nMáximo de pecados: "
            +QString::number(pecadoMayor)+"\nMínimo de pecados: "
            +QString::number(pecadoMenor);
    consulta += listaHeaps->imprimir();
    return consulta;
}

double Demonio::getPromedioPecados(){
    NodoListaSimpleHeaps * nodo = listaHeaps->primerNodo;
    int cantidadPecados = 0;
    double promedio;
    while(nodo != NULL){
        for(int i=0;i<nodo->heap->array.size();i++){
            cantidadPecados += nodo->heap->array[i]->persona->pecados[pecado]->cant;
        }
        nodo = nodo->siguiente;
    }
    promedio = (double)cantidadPecados / cantPersonas;
    return promedio;
}

int Demonio::getTotalPecados(){
    NodoListaSimpleHeaps * nodo = listaHeaps->primerNodo;
    int total = 0;
    while(nodo != NULL){
        for(int i=0;i<nodo->heap->array.size();i++){
            total += nodo->heap->array[i]->persona->pecados[pecado]->cant;
        }
        nodo = nodo->siguiente;
    }
    return total;
}

int Demonio::getTotalBuenasAcciones(){
    NodoListaSimpleHeaps * nodo = listaHeaps->primerNodo;
    int total = 0;
    while(nodo != NULL){
        for(int i=0;i<nodo->heap->array.size();i++){
            total += nodo->heap->array[i]->persona->buenasAcciones[pecado]->cant;
        }
        nodo = nodo->siguiente;
    }
    return total;
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

void Infierno::matarMasPecadores(ListaDoblePersonas * list, Files * file, QStringList *filesName, QString *current){
    int largo = list->vivos;
    int aMatar = list->vivos * 0.05;
    NodoHeap * arrayPersonasInfierno[largo];
    NodoPersona * p = list->primerNodo;
    int cont = 0;
    while(p!=NULL){
        if(p->persona->estado == 0){
            arrayPersonasInfierno[cont] = new NodoHeap(p->persona);
            cont++;
        }
        p = p->siguiente;
    }
    for(int i=0;i<7;i++){
        demonios[i]->buscarMasPecadores(arrayPersonasInfierno, largo, &log, &condenados,aMatar);
    }
    QDateTime date = QDateTime::currentDateTime();
    QString name = "Condenados_"+date.toString("yyyyMMdd")+"_"+date.toString("HHmmss")+".txt";
    filesName->append(name);
    *current = name;
    file->writeFile(name,log);
}

Persona * Infierno::salvarHumano(){
    //**************Buscar Humano a salvar********
    Persona * personaSalvada;
    for(int i = 0; i<7; i++){
        NodoListaSimpleHeaps *temp = demonios[i]->listaHeaps->primerNodo;
        while(temp!=NULL){
            for(int j = 0; j<temp->heap->cant; j++){
                if(temp->heap->array[j]->persona->buenasAccionesPersona > temp->heap->array[j]->persona->pecadosPersona && temp->heap->array[j]->persona->estado == 1){
                    personaSalvada = temp->heap->array[j]->persona;
                    personaSalvada->estado = 2;
                    temp->heap->deleteAtPosition(j);
                    demonios[i]->cantPersonas--;
                    condenados--;
                    return personaSalvada;
                }
                //qDebug()<<"Cant: "<<temp->heap->array[j]->persona->buenasAccionesPersona <<temp->heap->array[j]->persona->pecadosPersona <<temp->heap->array[j]->persona->estado;
            }
            temp = temp->siguiente;
        }
    }
    return NULL;
}

void Infierno::generarConsulta(Files * file){
    QString consulta;
    for(int i=0;i<7;i++){
        consulta += demonios[i]->consulta();
    }
    file->writeFile("ConsultasInfierno.txt",consulta);
}

int Infierno::sacarResultados(QString * pecados, QString * buenasAcciones){
    int totalPecados = 0;
    int totalBuenasAcciones = 0;
    int tempPecado = 0;
    int tempBuenaAccion = 0;
    int neto = 0;
    for(int i=0;i<7;i++){
        tempPecado = demonios[i]->getTotalPecados();
        totalPecados += tempPecado;
        *pecados += "\n\nPecado: "+convertPecadoToString(demonios[i]->pecado);
        *pecados += "\nCantidad: "+QString::number(tempPecado);
    }
    *pecados += "\n\nTotal: "+QString::number(totalPecados);
    for(int i=0;i<7;i++){
        tempBuenaAccion = demonios[i]->getTotalBuenasAcciones();
        totalBuenasAcciones += tempBuenaAccion;
        *buenasAcciones += "\n\nBuena Acción: "+convertBuenaAccionToString(demonios[i]->pecado);
        *buenasAcciones += "\nCantidad: "+QString::number(tempBuenaAccion);
    }
    *buenasAcciones += "\n\nTotal: "+QString::number(totalBuenasAcciones);
    neto = totalPecados - totalBuenasAcciones;
    return neto;
}
