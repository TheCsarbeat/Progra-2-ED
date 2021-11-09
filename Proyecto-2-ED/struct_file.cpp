#include "struct_file.h"


void Pais::toString(){
    qDebug() << name;
    qDebug() << continente;
    qDebug() << "\n";
}

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
