#include "struct_mundo.h"
void Mundo::crearHumanos(int dato){
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
        if( buscado!= NULL){
            buscado->arbol->insert(p);
        }else{
            listArbolFamilias->insertarALInicio(p);
        }


    }
    //crearArbol();

    //personas->imprimir();
    //treePersonas->preOrden(treePersonas->raiz);
    qDebug()<<"\nLa altura del arbol es: "<<treePersonas->treeHeight(treePersonas->raiz);
    qDebug()<<"La cantidad de nodos del arbol es: "<<treePersonas->cantNodos(treePersonas->raiz);
    qDebug()<<"El tama;o de la lista: "<<personas->largo;

    qDebug()<<"Arbol de familia: ";
    listArbolFamilias->imprimir();
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






