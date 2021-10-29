#include "struct_personas.h"
void ListaSimplePersonas::loadNames(){
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

void ListaSimplePersonas::printNames(){
    unsigned int size =  sizeof (names)/sizeof (names[0]);
    for(unsigned int i = 0; i<size;i++){
        qDebug() << i;
        qDebug() << names[i];
    }
}
