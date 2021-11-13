#include "struct_mundo.h"
void Mundo::crearHumanos(int dato, QLabel * lb){
    int contador = 0;
    while(contador!=dato){
        bool respuesta;
        int id = QRandomGenerator::global()->bounded(99999);
        QString name = files->names[QRandomGenerator::global()->bounded(100)];
        QString apellido = files->lastNames[QRandomGenerator::global()->bounded(50)];
        Pais *pais = files->paises[QRandomGenerator::global()->bounded(50)];
        QString creencia = QString::number(personas->largo);
        QString profesion = files->jobs[QRandomGenerator::global()->bounded(100)];
        Persona *p = new Persona(id, name, apellido, pais, creencia, profesion);
        p->hijos = new ListaDoblePersonas();

        if(treePersonas->raiz ==NULL){
            respuesta = personas->insertar(p);
        }else{
            respuesta = personas->insertar(p, treePersonas->buscarMasCercano(p->id));
        }
        if(respuesta)contador++;
        if(personas->largo%300==0){
            treePersonas->vaciarArbol();
            crearArbol();
        }
        NodoFamiliaListaSimple *buscado = listArbolFamilias->buscar(p);
        if( buscado!= NULL && respuesta){
            buscado->arbol->insert(p);
        }else{
            listArbolFamilias->insertarALInicio(p);
        }

    }
    //crearArbol();

    //personas->imprimir();
    //treePersonas->preOrden(treePersonas->raiz);

    QString daato;
    QString datosTree = +"Datos Arbol"
            "\nLa cantidad de niveles del árbol es: " +QString::number(treePersonas->treeHeight(treePersonas->raiz))
            +"\nLa cantidad de Humanos del arbol es: " +QString::number(treePersonas->cantNodos(treePersonas->raiz))
            +"\n\nDatos de lista: "
            +"\nEl tamaño de la lista: " +QString::number(personas->largo);
    datosTree += *treePersonas->toStringHojas();

    lb->setText(datosTree);
    qDebug()<<"Arbol de familia: ";
    //listArbolFamilias->imprimir();
}

void Mundo::crearArbol(){
    int treeSize =1;   
    while(treeSize <= personas->largo*0.01)
        treeSize = treeSize *2;    
    treeSize--;

    NodoPersona *arrayPersonas[treeSize];
    int index= 0;
    int separationValue = personas->largo/treeSize;
    int i = 1;

    NodoPersona *temp = personas->primerNodo;    
    while(temp != NULL && index < treeSize){
        if(i == separationValue){
            arrayPersonas[index] = temp;
            separationValue+=personas->largo/treeSize;
            index++;
        }
        i++;
        temp = temp->siguiente;
    }

    crearArbol(arrayPersonas, treeSize);
}

void Mundo::crearArbol(NodoPersona * array[], int size){

    int childrenSize = (size-1)/2;
    NodoPersona *arrayPersonasDerecho[childrenSize];
    NodoPersona *arrayPersonasIzquierdo[childrenSize];

    int middle = size/2;
    int index = 0;

    treePersonas->insertar(array[middle]->persona->id , array[middle]);
    if(size!=1){
        if(size!=3){
            for(int i =0; i<middle; i++){
                arrayPersonasIzquierdo[i] = array[i];
            }
            int indexArrayDerecho = 0;
            for(int i = middle+1; i<size; i++){
                arrayPersonasDerecho[indexArrayDerecho] = array[i];
                indexArrayDerecho++;
            }
            crearArbol(arrayPersonasIzquierdo,childrenSize);
            crearArbol(arrayPersonasDerecho,childrenSize);
        }else{
            index = middle+1;
            treePersonas->insertar(array[index]->persona->id,array[index]);
            index = middle-1;
            treePersonas->insertar(array[index]->persona->id,array[index]);
        }
    }
}

void Mundo::hacerPecar(){
    NodoPersona * tmp = personas->primerNodo;
    int randomP = 0;
    int randomBA = 0;
    while(tmp!=NULL){
        for(unsigned int i=0;i<7;i++){
            randomP = QRandomGenerator::global()->bounded(100);
            randomBA = QRandomGenerator::global()->bounded(100);
            tmp->persona->pecados[i]->cant += randomP;
            tmp->persona->buenasAcciones[i]->cant += randomBA;
            hacerHerencia(tmp->persona, randomP, randomBA, i);
        }
        tmp = tmp->siguiente;
    }
}

void Mundo::hacerHerencia(Persona * persona, int randomP, int randomBA, int position){
    NodoPersona * hijo = persona->hijos->primerNodo;
    while(hijo!=NULL){
        hijo->persona->pecados[position]->cant += randomP*0.5;
        hijo->persona->buenasAcciones[position]->cant += randomBA*0.5;
        NodoPersona * nieto = hijo->persona->hijos->primerNodo;
        while(nieto!=NULL){
            nieto->persona->pecados[position]->cant += randomBA*0.25;
            nieto->persona->buenasAcciones[position]->cant += randomBA*0.25;
            nieto = nieto->siguiente;
        }
        hijo = hijo->siguiente;
    }
}

