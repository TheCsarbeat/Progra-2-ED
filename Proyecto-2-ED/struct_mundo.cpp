#include "struct_mundo.h"
//======================PAIS===============================
void Pais::toString(){
    qDebug() << name;
    qDebug() << continente;
}

//======================PERSONA===============================
void Persona::imprimir(){
    qDebug() << id;
    qDebug() << name;
    qDebug() << apellido;
    pais->toString();
    qDebug() << creencia;
    qDebug() << profesion;
    qDebug() << email;
    qDebug() << nacimiento;
    qDebug() << "\n";
}

//======================LISTA DOBLE=========================
void ListaDoblePersonas::insertarAntes(NodoPersona * nodo, Persona * p){
    NodoPersona * nuevo = new NodoPersona(p);
    nuevo->siguiente = nodo;
    nuevo->anterior = nodo->anterior;
    nodo->anterior->siguiente = nuevo;
    nodo->anterior = nuevo;
}

void ListaDoblePersonas::insertarDespues(NodoPersona *nodo, Persona *p){
    NodoPersona * nuevo = new NodoPersona(p);
    nuevo->anterior = nodo;
    nuevo->siguiente = nodo->siguiente;
    nodo->siguiente->anterior = nuevo;
    nodo->siguiente = nuevo;
}

//======================FILES===============================
void Files::loadNames(){
    QFile file(":/data/names.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    int i = 0;
    while(!stream.atEnd()){
        names[i] = stream.readLine();
        i++;
    }
    file.close();
}

void Files::loadLastNames(){
    QFile file(":/data/last_names.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    int i = 0;
    while(!stream.atEnd()){
        lastNames[i] = stream.readLine();
        i++;
    }
    file.close();
}

void Files::loadReligions(){
    QFile file(":/data/religions.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    int i = 0;
    while(!stream.atEnd()){
        religions[i] = stream.readLine();
        i++;
    }
    file.close();
}

void Files::loadJobs(){
    QFile file(":/data/jobs.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    int i = 0;
    while(!stream.atEnd()){
        jobs[i] = stream.readLine();
        i++;
    }
    file.close();
}

void Files::loadAmerica(){
    QFile file(":/data/america.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        paises[index] = new Pais(stream.readLine(),"America");
        index++;
    }
    file.close();
}

void Files::loadAfrica(){
    QFile file(":/data/africa.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        paises[index] = new Pais(stream.readLine(),"Africa");
        index++;
    }
    file.close();
}

void Files::loadEuropa(){
    QFile file(":/data/europa.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        paises[index] = new Pais(stream.readLine(),"Europa");
        index++;
    }
    file.close();
}

void Files::loadAsia(){
    QFile file(":/data/asia.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        paises[index] = new Pais(stream.readLine(),"Asia");
        index++;
    }
    file.close();
}

void Files::loadOceania(){
    QFile file(":/data/oceania.txt");

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        paises[index] = new Pais(stream.readLine(),"Oceania");
        index++;
    }
    file.close();
}


void Files::printNames(){
    unsigned int size =  sizeof (paises)/sizeof (paises[0]);
    for(unsigned int i = 0; i<size;i++){
        paises[i]->toString();
    }
}

//======================MUNDO===============================

Persona * Mundo::generar(){
    Persona * persona = new Persona();
    persona->id = QRandomGenerator::global()->bounded(0,99999);
    persona->name = files->names[QRandomGenerator::global()->bounded(0,999)];
    persona->apellido = files->lastNames[QRandomGenerator::global()->bounded(0,500)];
    persona->pais = files->paises[QRandomGenerator::global()->bounded(0,195)];
    persona->creencia = files->religions[QRandomGenerator::global()->bounded(0,18)];
    persona->profesion = files->jobs[QRandomGenerator::global()->bounded(0,79)];

    return persona;
}


