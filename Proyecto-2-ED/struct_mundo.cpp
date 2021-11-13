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
        QString profesion = files->jobs[QRandomGenerator::global()->bounded(80)];
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
    qDebug()<<personas->primerNodo->persona->id;
}

void Mundo::guarDatosWorld(){
    QString datosWorld = +"Datos Arbol"
            "\nLa cantidad de niveles del árbol es: " +QString::number(treePersonas->treeHeight(treePersonas->raiz))
            +"\nLa cantidad de Humanos del arbol es: " +QString::number(treePersonas->cantNodos(treePersonas->raiz))
            +"\n\nDatos de lista: "
            +"\nEl tamaño de la lista: " +QString::number(personas->largo)
            +"\n\n";
    datosWorld += *treePersonas->toStringHojas();
    files->writeFile("datosWorld.txt", datosWorld);
}

void Mundo::buscarHuman(int dato, QLabel * lb){

    NodoPersona* buscado= treePersonas->buscarMasCercano(dato);
    buscado = personas->buscar(dato, buscado);
    if(buscado!= NULL){
        lb->setText(buscado->persona->toString()+buscado->persona->hijos->toStringIDHijos());
    }else{
        lb->setText("buscado->persona->toString()");
    }

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
    int random = 0;
    int africa = 0, america = 0, asia = 0, europa= 0, oceania = 0;

    while(tmp!=NULL){

        for(unsigned int i=0;i<7;i++){
            random = QRandomGenerator::global()->bounded(100);
            tmp->persona->pecados[i]->cant += random;
            //hacerHerencia(tmp->persona,random, i);
            tmp->persona->buenasAcciones[i]->cant += QRandomGenerator::global()->bounded(100);
            if(tmp->persona->pais->continente == "africa"){
                africa += random;
            }else if(tmp->persona->pais->continente == "africa"){
                africa += random;
            }else if(tmp->persona->pais->continente == "america"){
                america += random;
            }else if(tmp->persona->pais->continente == "asia"){
                asia += random;
            }else if(tmp->persona->pais->continente == "europa"){
                europa += random;
            }else if(tmp->persona->pais->continente == "oceania"){
                oceania += random;
            }
        }
        tmp = tmp->siguiente;
    }
    qDebug()<<"\n\nLos pecados de africa: "<<africa;
    qDebug()<<"Los pecados de America: "<<america;
    qDebug()<<"Los pecados de oceania: "<<oceania;
    qDebug()<<"Los pecados de Asia: "<<asia;
    qDebug()<<"Los pecados de Europa: "<<europa;
}

void Mundo::hacerHerencia(Persona * persona, int random, int position){
    NodoPersona * hijo = persona->hijos->primerNodo;
    while(hijo!=NULL){
        hijo->persona->pecados[position]->cant += random*0.5;
        NodoPersona * nieto = hijo->persona->hijos->primerNodo;
        while(nieto!=NULL){
            nieto->persona->pecados[position]->cant += random*0.25;
            nieto = nieto->siguiente;
        }
        hijo = hijo->siguiente;
    }
}


//---------------------- Consultas del Cielo
void Mundo::continentsMasBuenasAcciones(){
    NodoPersona * tmp = personas->primerNodo;
    int buenasAcionesPersona = 0;
    for(unsigned int i=0;i<5;i++){
        arrayBuenasAccionesMapa->arrayContinents[i]->cant = 0;
    }

    while(tmp!=NULL){
        buenasAcionesPersona = 0;
        for(unsigned int i=0;i<7;i++){
            buenasAcionesPersona += tmp->persona->buenasAcciones[i]->cant;
        }
        if (tmp == personas->primerNodo){
            qDebug()<<"Buenas acciones persona: "<<buenasAcionesPersona;
        }

        if(tmp->persona->pais->continente == arrayBuenasAccionesMapa->arrayContinents[0]->name)
            arrayBuenasAccionesMapa->arrayContinents[0]->cant += buenasAcionesPersona;

        else if(tmp->persona->pais->continente == arrayBuenasAccionesMapa->arrayContinents[1]->name)
            arrayBuenasAccionesMapa->arrayContinents[1]->cant += buenasAcionesPersona;

        else if(tmp->persona->pais->continente == arrayBuenasAccionesMapa->arrayContinents[2]->name)
            arrayBuenasAccionesMapa->arrayContinents[2]->cant += buenasAcionesPersona;

        else if(tmp->persona->pais->continente == arrayBuenasAccionesMapa->arrayContinents[3]->name)
            arrayBuenasAccionesMapa->arrayContinents[3]->cant += buenasAcionesPersona;

        else if(tmp->persona->pais->continente == arrayBuenasAccionesMapa->arrayContinents[4]->name)
            arrayBuenasAccionesMapa->arrayContinents[4]->cant += buenasAcionesPersona;
        else{

        }
        tmp = tmp->siguiente;
    }
    arrayBuenasAccionesMapa->bubbleSort();
    qDebug()<<"\nBuenas Acciones\n";
    arrayBuenasAccionesMapa->imprimir();
    arrayBuenasAccionesMapa->showMap(0);
}

void Mundo::continentsMasPecados(){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosPersona = 0;
    int africa = 0;
    for(unsigned int i=0;i<5;i++){
        arrayPecadosMapa->arrayContinents[i]->cant = 0;
    }
    while(tmp!=NULL){
        pecadosPersona = 0;
        for(unsigned int i=0;i<7;i++){
            pecadosPersona += tmp->persona->pecados[i]->cant;
        }

        if (tmp == personas->primerNodo){
            qDebug()<<"Pecados persona: "<<pecadosPersona;
        }

        if(tmp->persona->pais->continente == "africa"){
            africa += pecadosPersona;
        }

        if(tmp->persona->pais->continente == arrayPecadosMapa->arrayContinents[0]->name)
            arrayPecadosMapa->arrayContinents[0]->cant += pecadosPersona;

        else if(tmp->persona->pais->continente == arrayPecadosMapa->arrayContinents[1]->name)
            arrayPecadosMapa->arrayContinents[1]->cant += pecadosPersona;

        else if(tmp->persona->pais->continente == arrayPecadosMapa->arrayContinents[2]->name)
            arrayPecadosMapa->arrayContinents[2]->cant += pecadosPersona;

        else if(tmp->persona->pais->continente == arrayPecadosMapa->arrayContinents[3]->name)
            arrayPecadosMapa->arrayContinents[3]->cant += pecadosPersona;

        else if(tmp->persona->pais->continente == arrayPecadosMapa->arrayContinents[4]->name)
            arrayPecadosMapa->arrayContinents[4]->cant += pecadosPersona;
        else{

        }
        tmp = tmp->siguiente;
    }
    qDebug()<<"Los pecados de africa desde el contador de pecados de Maynor: "<<africa;
    arrayPecadosMapa->bubbleSort();
    qDebug()<<"\n Pecados\n";
    arrayPecadosMapa->imprimir();
    arrayPecadosMapa->showMap(1);
}

void Mundo::top10Cielo(){
    NodoPersona * tmp = personas->primerNodo;
    int buenasAccionesP = 0;
    for( int i=0; i<files->index; i++){
        arrayBuenasAcciones->arrayPaises[i]->cantidad = 0;

    }

    while(tmp!=NULL){
        buenasAccionesP = 0;
        for(unsigned int i=0;i<7;i++){
            buenasAccionesP += tmp->persona->buenasAcciones[i]->cant;
        }
         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayBuenasAcciones->arrayPaises[i]->nombre)
                 arrayBuenasAcciones->arrayPaises[i]->cantidad += buenasAccionesP;
             tmp = tmp->siguiente;
         }
    }
    arrayBuenasAcciones->bubbleSortMayorMenor(files);
    arrayBuenasAcciones->imprimir();

}

void Mundo::top5Cielo(){
    NodoPersona * tmp = personas->primerNodo;
    int buenasAccionesP = 0;
    for( int i=0; i<files->index; i++){
        arrayBuenasAcciones->arrayPaises[i]->cantidad = 0;

    }

    while(tmp!=NULL){
        buenasAccionesP = 0;
        for(unsigned int i=0;i<7;i++){
            buenasAccionesP += tmp->persona->buenasAcciones[i]->cant;
        }
         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayBuenasAcciones->arrayPaises[i]->nombre)
                 arrayBuenasAcciones->arrayPaises[i]->cantidad += buenasAccionesP;
             tmp = tmp->siguiente;
         }
    }
    arrayBuenasAcciones->bubbleSortMenorMayor(files);
    arrayBuenasAcciones->imprimir2();

}

void Mundo::top10Infierno(){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;

    for( int i=0; i<files->index; i++){
        arrayPecados->arrayPaises[i]->cantidad = 0;
    }

    while(tmp!=NULL){
        pecadosP = 0;
        for(unsigned int i=0;i<7;i++){
            pecadosP += tmp->persona->pecados[i]->cant;
        }
         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayPecados->arrayPaises[i]->nombre)
                 arrayPecados->arrayPaises[i]->cantidad += pecadosP;
             tmp = tmp->siguiente;
         }
    }
    arrayPecados->bubbleSortMayorMenor(files);
    arrayPecados->imprimir();

}

void Mundo::top5Infierno(){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<files->index; i++){
        arrayPecados->arrayPaises[i]->cantidad = 0;

    }

    while(tmp!=NULL){
        pecadosP = 0;
        for(unsigned int i=0;i<7;i++){
            pecadosP += tmp->persona->pecados[i]->cant;
        }
         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayPecados->arrayPaises[i]->nombre)
                 arrayPecados->arrayPaises[i]->cantidad += pecadosP;
             tmp = tmp->siguiente;
         }
    }
    arrayPecados->bubbleSortMenorMayor(files);
    arrayPecados->imprimir2();

}
