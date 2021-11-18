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
    indexName= i;
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
        arrayCBO[0]->addItem(lastNames[i]);
        i++;
    }
    indexLasName = i;

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
    indexReligions = i;
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
    indexJobs = i;
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
        paises[index] = new Pais(stream.readLine(),"america");

        index++;
    }
    file.close();
    //qDebug()<<"Cantidadde paises de america: "<<index;
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
        paises[index] = new Pais(stream.readLine(),"africa");
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
        paises[index] = new Pais(stream.readLine(),"europa");
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
        paises[index] = new Pais(stream.readLine(),"asia");
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
        paises[index] = new Pais(stream.readLine(),"oceania");
        index++;
    }
    file.close();
    //qDebug()<<"Cant de paises: "<<index;

}

void Files::printNames(){
    unsigned int size =  sizeof (paises)/sizeof (paises[0]);
    for(unsigned int i = 0; i<size;i++){
        paises[i]->toString();
    }
}

void Files::writeFile(QString fileName, QString data){
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << data << "\n";
        }

}
