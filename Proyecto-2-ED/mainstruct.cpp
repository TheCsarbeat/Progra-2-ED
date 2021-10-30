#include "mainstruct.h"
void MainStruct::loadNames(){
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

void MainStruct::printNames(){
    unsigned int size =  sizeof (names)/sizeof (names[0]); // aparantely such a simple thing like getting the size of an array in c++ is a fucking imposible nightmare
    for(unsigned int i = 0; i<size;i++){
        qDebug() << i;
        qDebug() << names[i];
    }
}
