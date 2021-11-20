#include "struct_mundo.h"
void Mundo::crearHumanos(int dato){
    int contador = 0;

    while(contador!=dato && personas->largo<99999){
        bool respuesta;
        int id = QRandomGenerator::global()->bounded(100000);
        QString name = files->names[QRandomGenerator::global()->bounded(101)];
        QString apellido = files->lastNames[QRandomGenerator::global()->bounded(51)];
        Pais *pais = files->paises[QRandomGenerator::global()->bounded(files->index)];
        //QString creencia = QString::number(personas->largo);
        QString creencia = files->religions[QRandomGenerator::global()->bounded(files->indexReligions)];
        QString profesion = files->jobs[QRandomGenerator::global()->bounded(files->indexJobs)];
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
        if(respuesta){

            if( buscado!= NULL)
                buscado->arbol->insert(p);
            else
                listArbolFamilias->insertarALInicio(p);
        }
    }
    //cielo->imprimir();
    //files->writeFile("worldLista.txt", personas->toString());
    files->writeFile("familiasMundoInOrden.txt", listArbolFamilias->toString());
    //files->writeFile("cieloInOrden.txt", cielo->toString());
    //qDebug()<<personas->primerNodo->persona->id;
}

void Mundo::guarDatosWorld(){
    QString datosWorld = +"Datos Arbol"
            "\nLa cantidad de niveles del árbol es: " +QString::number(treePersonas->treeHeight(treePersonas->raiz))
            +"\nLa cantidad de Humanos del arbol es: " +QString::number(treePersonas->cantNodos(treePersonas->raiz))
            +"\n\nDatos de lista: "
            +"\nEl tamaño de la lista: " +QString::number(personas->largo)
            +"\n\n";
    datosWorld += *treePersonas->toStringHojas();

    files->writeFile("familiasMundoInOrden.txt", listArbolFamilias->toString());
    filesNameToSend.append("familiasMundoInOrden.txt");

    files->writeFile("datosWorldArbol.txt", datosWorld);
    filesNameToSend.append("datosWorld.txt");

    files->writeFile("worldLista.txt", personas->toString());
    filesNameToSend.append("worldLista.txt");
}

void Mundo::guardarDatosCielo(){
    files->writeFile("cieloInOrden.txt", cielo->toString());
    filesNameToSend.append("cieloInOrden.txt");

}

void Mundo::buscarHuman(int dato, QLabel * lb){

    NodoPersona* buscado= treePersonas->buscarMasCercano(dato);
    buscado = personas->buscar(dato, buscado);
    if(buscado!= NULL){
        lb->setText(buscado->persona->toString()+buscado->persona->hijos->toStringIDHijos());
    }else{
        lb->setText("No se ha encontrado ningún humano");
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
    int randomP = 0;
    int randomBA = 0;
    while(tmp!=NULL){
        if(tmp->persona->estado==0){
            for(unsigned int i=0;i<7;i++){
                randomP = QRandomGenerator::global()->bounded(100);
                randomBA = QRandomGenerator::global()->bounded(100);
                tmp->persona->pecados[i]->cant += randomP;
                tmp->persona->pecadosPersona += randomP;
                tmp->persona->buenasAcciones[i]->cant += randomBA;
                tmp->persona->buenasAccionesPersona += randomBA;
                hacerHerencia(tmp->persona, randomP, randomBA, i);
            }
        }
        tmp = tmp->siguiente;
    }
}

void Mundo::hacerHerencia(Persona * persona, int randomP, int randomBA, int position){
    NodoPersona * hijo = persona->hijos->primerNodo;
    while(hijo!=NULL){
        hijo->persona->pecados[position]->cant += randomP*0.5;
        hijo->persona->buenasAcciones[position]->cant += randomBA*0.5;
        hijo->persona->pecadosPersona += randomP*0.5;
        hijo->persona->buenasAccionesPersona += randomBA*0.5;

        NodoPersona * nieto = hijo->persona->hijos->primerNodo;
        while(nieto!=NULL){
            nieto->persona->pecados[position]->cant += randomBA*0.25;
            nieto->persona->buenasAcciones[position]->cant += randomBA*0.25;

            nieto->persona->pecadosPersona += randomP*0.25;
            nieto->persona->buenasAccionesPersona += randomBA*0.25;
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
    arrayBuenasAccionesMapa->showMap(0);
}

void Mundo::continentsMasPecados(){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosPersona = 0;

    for(unsigned int i=0;i<5;i++){
        arrayPecadosMapa->arrayContinents[i]->cant = 0;
    }
    while(tmp!=NULL){
        pecadosPersona = 0;
        for(unsigned int i=0;i<7;i++){
            pecadosPersona += tmp->persona->pecados[i]->cant;
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
        tmp = tmp->siguiente;
    }
    arrayPecadosMapa->bubbleSort();
    arrayPecadosMapa->showMap(1);
}

void Mundo::top10Cielo(QLabel *lb,QLabel *lb2){
    NodoPersona * tmp = personas->primerNodo;
    int buenasAccionesP = 0;
    for( int i=0; i<files->index; i++){
        arrayBuenasAcciones->arrayPaises[i]->cantidad = 0;
    }

    while(tmp!=NULL){
        buenasAccionesP = 0;
        for(unsigned int i=0;i<7;i++)
            buenasAccionesP += tmp->persona->buenasAcciones[i]->cant;

        for (int i = 0; i < files->index; i ++){
            if(tmp->persona->pais->name == arrayBuenasAcciones->arrayPaises[i]->nombre)
                 arrayBuenasAcciones->arrayPaises[i]->cantidad += buenasAccionesP;
        }
        tmp = tmp->siguiente;
    }

    arrayBuenasAcciones->bubbleSortMayorMenor(files);
    lb->setText(arrayBuenasAcciones->toStringMayores());
    lb2->setText(arrayBuenasAcciones->toStringMayoresCantidad());
}

void Mundo::top5Cielo(QLabel * lb,QLabel *lb2){
    NodoPersona * tmp = personas->primerNodo;
    int buenasAccionesP = 0;
    for( int i=0; i<files->index; i++){
        arrayBuenasAcciones->arrayPaises[i]->cantidad = 0;
    }
    while(tmp!=NULL){
        buenasAccionesP = 0;
        for(unsigned int i=0;i<7;i++)
            buenasAccionesP += tmp->persona->buenasAcciones[i]->cant;

        for (int i = 0; i < files->index; i ++){
         if(tmp->persona->pais->name == arrayBuenasAcciones->arrayPaises[i]->nombre)
             arrayBuenasAcciones->arrayPaises[i]->cantidad += buenasAccionesP;
        }
        tmp = tmp->siguiente;
    }
    arrayBuenasAcciones->bubbleSortMenorMayor(files);
    lb->setText(arrayBuenasAcciones->toStringMenores());
    lb2->setText(arrayBuenasAcciones->toStringMenoresCantidad());

}

void Mundo::top10Infierno(QLabel *lb,QLabel *lb2){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;

    for( int i=0; i<files->index; i++){
        arrayPecados->arrayPaises[i]->cantidad = 0;
    }

    while(tmp!=NULL){
        pecadosP = 0;
        for(unsigned int i=0;i<7;i++)
            pecadosP += tmp->persona->pecados[i]->cant;

         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayPecados->arrayPaises[i]->nombre)
                 arrayPecados->arrayPaises[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecados->bubbleSortMayorMenor(files);
    lb->setText(arrayPecados->toStringMayores());
    lb2->setText(arrayPecados->toStringMayoresCantidad());

}

void Mundo::top5Infierno(QLabel *lb, QLabel *lb2){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<files->index; i++){
        arrayPecados->arrayPaises[i]->cantidad = 0;
    }

    while(tmp!=NULL){
        pecadosP = 0;
        for(unsigned int i=0;i<7;i++)
            pecadosP += tmp->persona->pecados[i]->cant;

         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayPecados->arrayPaises[i]->nombre)
                 arrayPecados->arrayPaises[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecados->bubbleSortMenorMayor(files);
    lb->setText(arrayPecados->toStringMenores());
    lb2->setText(arrayPecados->toStringMenoresCantidad());
}

void Mundo::buscarBAFamilias(int id, QLabel *lb){
    NodoPersona* buscado= treePersonas->buscarMasCercano(id);
    buscado = personas->buscar(id, buscado);
    if(buscado!= NULL){
        NodoFamiliaListaSimple *nodoBuscado = listArbolFamilias->buscar(buscado->persona);
        lb->setText(*nodoBuscado->arbol->toStringInOrdenBA());
    }else{
        lb->setText("No existe");
    }

}

void Mundo::buscarPecadosFamilias(int id, QLabel *lb){
    NodoPersona* buscado= treePersonas->buscarMasCercano(id);
    buscado = personas->buscar(id, buscado);
    if(buscado!= NULL){
        NodoFamiliaListaSimple *nodoBuscado = listArbolFamilias->buscar(buscado->persona);
        lb->setText(*nodoBuscado->arbol->toStringInOrdenP());
    }else{
        lb->setText("No existe");
    }

}


void Mundo::consutlaHumanStateFamily(QString lastName, QString country,QLabel *lb){
    NodoFamiliaListaSimple *nodoBuscado = listArbolFamilias->buscar(lastName, country);
    int cantidadCielo = 0;
    int cantidadInfierno = 0;
    int cantidadVivos = 0;

    if(nodoBuscado!= NULL){
        NodoPersona * lista[nodoBuscado->arbol->cant];
        nodoBuscado->arbol->aplastarArbolBB(lista);
        QString datos;
        for(int i = 0; i<nodoBuscado->arbol->cant; i++){
            datos +=lista[i]->persona->toStringConsulta2()+lista[i]->persona->hijos->toStringIDHijos();
            if (lista[i]->persona->estado == 0){
                cantidadVivos ++;
            }else if(lista[i]->persona->estado == 1){
                cantidadInfierno ++;
            }else{
                cantidadCielo++;
            }
        }
        qDebug()<<nodoBuscado->arbol->cant;
        qDebug()<<cantidadCielo;
        qDebug()<<cantidadInfierno;
        qDebug()<<cantidadVivos;
        if (cantidadCielo!=0)
            datos += "\nPorcentaje en el cielo: "+ QString::number((double)(cantidadCielo*100)/nodoBuscado->arbol->cant) + " %" ;
        else
            datos += "\nPorcentaje en el cielo: 0";
        if (cantidadInfierno!=0)
            datos += "\nPorcentaje en el infierno: "+QString::number((double)(cantidadInfierno*100)/nodoBuscado->arbol->cant) + " %" ;
        else
            datos += "\nPorcentaje en el infierno: 0";
        if(cantidadVivos!=0)
            datos += "\nPorcentaje vivos: "+QString::number((double)(cantidadVivos*100)/nodoBuscado->arbol->cant) + " %" ;
        else
            datos += "\nPorcentaje vivos: 0";
        lb->setText(datos);


    }else{
        lb->setText("No existe");
    }
}

void Mundo::salvacion(){
    //qDebug()<<"El mas cercano: "<<mainstruct->mundo->treePersonas->buscarMasCercano(ui->txtcerca->text().toInt())->persona->id;
    QString arrayAngelNames[9] ={"Miguel", "Nuriel", "Aniel", "Rafael", "Gabriel", "Shamsiel", "Raguel", "Uriel", "Azrael"};
    arbolAngeles->nivel ++;
    int nivel = arbolAngeles->nivel;
    int cantNodosNuevos = qPow(3, nivel);

    QDateTime fecha = QDateTime::currentDateTime();
    QString datosLog ="";
    for(int index = 0; index < cantNodosNuevos; index++){
        Persona * humanoSalvado = infierno->salvarHumano();
        Angel * angel;
        if(humanoSalvado != NULL){
            angel = new Angel(arrayAngelNames[QRandomGenerator::global()->bounded(9)], nivel, index+1, humanoSalvado);
            cielo->insertar(humanoSalvado, angel);
            datosLog += fecha.toString();
            datosLog += humanoSalvado->toStringsimplified()+"\n";
            datosLog += angel->toString();
            datosLog+="\n-------------------------------------------------\n\n";
            cielo->insertar(humanoSalvado, angel);
        }else
            angel = new Angel(arrayAngelNames[QRandomGenerator::global()->bounded(9)]+QString::number(index+1), nivel, index+1, new Persona);
        arbolAngeles->insertar(angel);
    }
    QString nombreArchivo = "SalvacionLog"+fecha.toString("yyyy-MM-dd")+"__"+fecha.toString("HHmmss")+".txt";
    currentFileName = nombreArchivo;
    filesNameToSend.append(nombreArchivo);
    files->writeFile(nombreArchivo, datosLog);

}


void Mundo::apellidosPecadores(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<50; i++){
        arrayPecadoApellidos->arrayApellidos[i]->cantidad = 0;
    }
    arrayPecadoApellidos->cantidadPecados = 0;
    while(tmp!=NULL){

        pecadosP = tmp->persona->pecadosPersona;


        arrayPecadoApellidos->cantidadPecados += pecadosP;

         for (int i = 0; i < 50; i ++){
             if(tmp->persona->apellido == arrayPecadoApellidos->arrayApellidos[i]->apellido)
                 arrayPecadoApellidos->arrayApellidos[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecadoApellidos->bubbleSort(files);
    lb->setText(arrayPecadoApellidos->toStringApellidos());

}

void Mundo::apellidosBA(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int buenasP = 0;
    for( int i=0; i<50; i++){
        arrayBAapellidos->arrayApellidos[i]->cantidad = 0;
    }
    arrayBAapellidos->cantidadBA = 0;
    while(tmp!=NULL){

        buenasP = tmp->persona->buenasAccionesPersona;

        arrayBAapellidos->cantidadBA += buenasP;

         for (int i = 0; i < 50; i ++){
             if(tmp->persona->apellido == arrayBAapellidos->arrayApellidos[i]->apellido)
                 arrayBAapellidos->arrayApellidos[i]->cantidad += buenasP;
         }
         tmp = tmp->siguiente;
    }
    arrayBAapellidos->bubbleSort(files);
    lb->setText(arrayBAapellidos->toStringApellidos2());

}

void Mundo::continentesPecadores(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<5; i++){
        arrayPecadosContinentes->arrayContinentes[i]->cantidad = 0;
    }
    arrayPecadosContinentes->cantidadPecados = 0;
    while(tmp!=NULL){

        pecadosP = tmp->persona->pecadosPersona;


        arrayPecadosContinentes->cantidadPecados += pecadosP;

         for (int i = 0; i < 5; i ++){
             if(tmp->persona->pais->continente == arrayPecadosContinentes->arrayContinentes[i]->nombre)
                 arrayPecadosContinentes->arrayContinentes[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecadosContinentes->bubbleSort();
    lb->setText(arrayPecadosContinentes->toStringContinentes());

}

void Mundo::continentesBA(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int buenasP = 0;
    for( int i=0; i<5; i++){
        arrayBAContinentes->arrayContinentes[i]->cantidad = 0;
    }
    arrayBAContinentes->cantidadBA = 0;
    while(tmp!=NULL){

        buenasP = tmp->persona->buenasAccionesPersona;

        arrayBAContinentes->cantidadBA += buenasP;

         for (int i = 0; i < 5; i ++){
             if(tmp->persona->pais->continente == arrayBAContinentes->arrayContinentes[i]->nombre)
                 arrayBAContinentes->arrayContinentes[i]->cantidad += buenasP;
         }
         tmp = tmp->siguiente;
    }
    arrayBAContinentes->bubbleSort();
    lb->setText(arrayBAContinentes->toStringContinentes2());
}

void Mundo::paisesPecadores(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<files->index; i++){
        arrayPecadoPaises->arrayPaises[i]->cantidad = 0;
    }
    arrayPecadoPaises->cantidadPecados = 0;
    while(tmp!=NULL){

        pecadosP = tmp->persona->pecadosPersona;


        arrayPecadoPaises->cantidadPecados += pecadosP;

         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayPecadoPaises->arrayPaises[i]->nombre)
                 arrayPecadoPaises->arrayPaises[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecadoPaises->bubbleSort(files);
    lb->setText(arrayPecadoPaises->toStringPaises(files));

}

void Mundo::paisesBA(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int buenasP = 0;
    for( int i=0; i<files->index; i++){
        arrayBAPaises->arrayPaises[i]->cantidad = 0;
    }
    arrayBAPaises->cantidadBA = 0;
    while(tmp!=NULL){

        buenasP = tmp->persona->buenasAccionesPersona;

        arrayBAPaises->cantidadBA += buenasP;

         for (int i = 0; i < files->index; i ++){
             if(tmp->persona->pais->name == arrayBAPaises->arrayPaises[i]->nombre)
                 arrayBAPaises->arrayPaises[i]->cantidad += buenasP;
         }
         tmp = tmp->siguiente;
    }
    arrayBAPaises->bubbleSort(files);
    lb->setText(arrayBAPaises->toStringPaises2(files));
}

void Mundo::creenciasPecadores(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<files->indexReligions; i++){
        arrayPecadoCreencias->arrayCreencia[i]->cantidad = 0;
    }
    arrayPecadoCreencias->cantidadPecados = 0;
    while(tmp!=NULL){

        pecadosP = tmp->persona->pecadosPersona;


        arrayPecadoCreencias->cantidadPecados += pecadosP;

         for (int i = 0; i < files->indexReligions; i ++){
             if(tmp->persona->creencia == arrayPecadoCreencias->arrayCreencia[i]->nombre)
                 arrayPecadoCreencias->arrayCreencia[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecadoCreencias->bubbleSort();
    lb->setText(arrayPecadoCreencias->toStringCreencia());

}

void Mundo::creenciasBA(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int buenasP = 0;
    for( int i=0; i<files->indexReligions; i++){
        arrayBAcreencias->arrayCreencia[i]->cantidad = 0;
    }
    arrayBAcreencias->cantidadBA = 0;
    while(tmp!=NULL){

        buenasP = tmp->persona->buenasAccionesPersona;

        arrayBAcreencias->cantidadBA += buenasP;

         for (int i = 0; i < files->indexReligions; i ++){
             if(tmp->persona->creencia == arrayBAcreencias->arrayCreencia[i]->nombre)
                 arrayBAcreencias->arrayCreencia[i]->cantidad += buenasP;
         }
         tmp = tmp->siguiente;
    }
    arrayBAcreencias->bubbleSort();
    lb->setText(arrayBAcreencias->toStringCreencia2());
}

void Mundo::profesionesPecadores(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int pecadosP = 0;
    for( int i=0; i<files->indexJobs; i++){
        arrayPecadoProfesiones->arrayProfesiones[i]->cantidad = 0;
    }
    arrayPecadoProfesiones->cantidadPecados = 0;
    while(tmp!=NULL){

        pecadosP = tmp->persona->pecadosPersona;


        arrayPecadoProfesiones->cantidadPecados += pecadosP;

         for (int i = 0; i < files->indexJobs; i ++){
             if(tmp->persona->profesion == arrayPecadoProfesiones->arrayProfesiones[i]->nombre)
                 arrayPecadoProfesiones->arrayProfesiones[i]->cantidad += pecadosP;
         }
         tmp = tmp->siguiente;
    }
    arrayPecadoProfesiones->bubbleSort();
    lb->setText(arrayPecadoProfesiones->toStringProfesiones());

}

void Mundo::profesionesBA(QLabel *lb){
    NodoPersona * tmp = personas->primerNodo;
    int buenasP = 0;
    for( int i=0; i<files->indexJobs; i++){
        arrayBAprofesiones->arrayProfesiones[i]->cantidad = 0;
    }
    arrayBAprofesiones->cantidadBA = 0;
    while(tmp!=NULL){

        buenasP = tmp->persona->buenasAccionesPersona;

        arrayBAprofesiones->cantidadBA += buenasP;

         for (int i = 0; i < files->indexJobs; i ++){
             if(tmp->persona->profesion == arrayBAprofesiones->arrayProfesiones[i]->nombre)
                 arrayBAprofesiones->arrayProfesiones[i]->cantidad += buenasP;
         }
         tmp = tmp->siguiente;
    }
    arrayBAprofesiones->bubbleSort();
    lb->setText(arrayBAprofesiones->toStringProfesiones2());
}
