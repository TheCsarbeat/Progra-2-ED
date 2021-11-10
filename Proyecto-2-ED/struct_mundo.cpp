#include "struct_mundo.h"
void Mundo::crearHumanos(int dato){
    int contador = 0;
    while(contador!=dato){
        bool respuesta;
        int id = QRandomGenerator::global()->bounded(99999);
        QString name = files->names[QRandomGenerator::global()->bounded(100)];
        QString apellido = files->lastNames[QRandomGenerator::global()->bounded(50)];
        QString pais = files->lastNames[QRandomGenerator::global()->bounded(50)];
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

    personas->imprimir();
    //treePersonas->preOrden(treePersonas->raiz);
    qDebug()<<"\nLa altura del arbol es: "<<treePersonas->treeHeight(treePersonas->raiz);
    qDebug()<<"La cantidad de nodos del arbol es: "<<treePersonas->cantNodos(treePersonas->raiz);
    qDebug()<<"El tama;o de la lista: "<<personas->largo;

    qDebug()<<"Arbol de familia: ";
    //listArbolFamilias->imprimir();


    // Prueba del arbol de la familias
    /*NodoPersona *temp = personas->primerNodo;
    for(int i = 1; i<=12; i++){
       temp->persona->imprimir();
       treeFamilias->insert(temp->persona);
       temp = temp->siguiente;
    }


    qDebug()<<"\nLa altura del arbol Familias es: "<<treeFamilias->treeHeight(treeFamilias->raiz);

    for(int i = 0; i<=treeFamilias->treeHeight(treeFamilias->raiz); i++){
        qDebug()<<"\n----------";
        treeFamilias->imprimirNivel(i);
    }
    treeFamilias->preOrder(treeFamilias->raiz);*/

}

void Mundo::crearArbol(){
    int treeSize =1;
    int exponent = 0;
    int largoPersonas = personas->largo;
    while(treeSize <= personas->largo*0.01){
        treeSize = treeSize *2;
        exponent++;
    }
    treeSize--;
    NodoPersona *arrayPersonas[treeSize];
    int index= 0;
    int separationValue = personas->largo/treeSize;

    NodoPersona *temp = personas->primerNodo;
    int i = 1;
    while(temp != NULL && index < treeSize){
        if(i == separationValue){
            arrayPersonas[index] = temp;
            separationValue+=personas->largo/treeSize;
            index++;
        }
        i++;
        temp = temp->siguiente;
    }

    //Imprimir el array
    /*for(int i = 0; i<treeSize; i++){
        arrayPersonas[i]->persona->imprimir();
    }*/

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

            /*qDebug()<<"\n\n\nArray derecho";
            for(int i = 0; i<(size-1)/2; i++){
                qDebug()<<"\n";
                arrayPersonasDerecho[i]->persona->imprimir();
            }

            qDebug()<<"\nArray Izquierdo";
            for(int i = 0; i<(size-1)/2; i++){
                qDebug()<<"\n";
                arrayPersonasIzquierdo[i]->persona->imprimir();
            }*/
        }else{
            index = middle+1;
            treePersonas->insertar(array[index]->persona->id,array[index]);
            index = middle-1;
            treePersonas->insertar(array[index]->persona->id,array[index]);
        }
    }
}






