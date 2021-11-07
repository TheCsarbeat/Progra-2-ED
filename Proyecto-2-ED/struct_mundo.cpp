#include "struct_mundo.h"
void Mundo::crearHumanos(int dato){
    int contador = 0;
    while(contador!=dato){
        bool respuesta;
        int id = QRandomGenerator::global()->bounded(99999);
        QString name = files->names[QRandomGenerator::global()->bounded(100)];
        QString apellido = files->lastNames[QRandomGenerator::global()->bounded(100)];
        QString pais = files->lastNames[QRandomGenerator::global()->bounded(100)];
        QString creencia = QString::number(contador);
        QString profesion = files->jobs[QRandomGenerator::global()->bounded(100)];
        Persona *p = new Persona(id, name, apellido, pais, creencia, profesion);

        if(treePersonas->raiz ==NULL){
            respuesta = personas->insertar(p);
            qDebug()<<"Con raiz nula: "<<contador;

        }else{
            respuesta = personas->insertar(p, treePersonas->buscarMasCercano(p->id));
            qDebug()<<"Con Arbol creado: "<<contador;
        }
        if(respuesta)contador++;
        if(personas->largo%100==0){
            treePersonas->vaciarArbol();
            crearArbol();
        }
    }
    //crearArbol();

    personas->imprimir();
    //treePersonas->preOrden(treePersonas->raiz);
    qDebug()<<"La altura del arbol es: "<<treePersonas->treeHeight(treePersonas->raiz);
    qDebug()<<"La cantidad de nodos del arbol es: "<<treePersonas->cantNodos(treePersonas->raiz);
    qDebug()<<"El tama;o de la lista: "<<personas->largo;

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
    for(int i = 1; i<=personas->largo; i++){
       if(i == separationValue && temp != NULL){
           arrayPersonas[index] = temp;
           temp->persona->creencia = QString::number(i);
           separationValue+=personas->largo/treeSize;
           index++;
       }
       temp = temp->siguiente;
    }

    //Imprimir el array
    /*for(int i = 0; i<treeSize; i++){
        arrayPersonas[i]->persona->imprimir();
    }*/

    int size = sizeof (arrayPersonas)/sizeof (arrayPersonas[0]);
    //if(separationValue!= personas->largo)
        crearArbol(arrayPersonas, size);

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






