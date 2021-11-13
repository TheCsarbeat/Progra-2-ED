#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

#include "struct_personas.h"
#include "struct_file.h"
#include "struct_arbolfamilias.h"
#include "struct_infierno.h"

#include <QMessageBox>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>


struct Mundo;
struct ArrayContinent;
struct ContinentData{
    QString name;
    int cant;
    QLabel *lb;
    ContinentData(){
        name = "";
        cant = 0;
        lb = new QLabel();
    }
};
struct ArrayPaises;
struct PaisesData{
    QString nombre;
    int cantidad;
    PaisesData(){
        nombre = "";
        cantidad = 0;
    }
};

struct ArrayContinent{
    QString names[5] = {"america", "africa", "europa","oceania", "asia"};
    ContinentData *arrayContinents[7];
    ArrayContinent(QLabel * lb[]){
       for(int i= 0; i<5; i++){
           arrayContinents[i] = new ContinentData();
           arrayContinents[i]->name = names[i];
           arrayContinents[i]->lb = lb[i];
       }
    }
    void imprimir(){
        for(int i = 0; i<5; i++) {
            qDebug()<<"Continente: "<<arrayContinents[i]->name<<"\t\t Cantidad: "<<arrayContinents[i]->cant;
        }
    }
    void showMap(int i){
        if(i == 0){
            for(int i = 0; i<5; i++)
                arrayContinents[i]->lb->setStyleSheet("image:url(':/images/continents/"+arrayContinents[i]->name+QString::number(i+1)+".png');");
        }else{
            for(int i = 0; i<5; i++)
                arrayContinents[i]->lb->setStyleSheet("image:url(':/images/continents/"+arrayContinents[i]->name+"R"+QString::number(i+1)+".png');");
        }
    }
    void bubbleSort(){
        ContinentData *temp = new ContinentData();
        for(int i = 0; i<5; i++) {
           for(int j = i+1; j<5; j++)           {
              if(arrayContinents[j]->cant > arrayContinents[i]->cant) {
                 *temp = *arrayContinents[i];
                 *arrayContinents[i] = *arrayContinents[j];
                 *arrayContinents[j] = *temp;
              }
           }
        }
    }

};

struct ArrayPaises{
    PaisesData *arrayPaises[196];

    ArrayPaises(Files * file){
        int cantidad = file->index;
        for (int i=0; i<cantidad; i++){
            arrayPaises[i] = new PaisesData();
            arrayPaises[i]->nombre = file->paises[i]->name;
        }
    }

    QString toStringMayores(){
        QString respuesta= "";
        for(int i = 0; i<10; i++) {
            respuesta += QString::number(i+1)+" # "+arrayPaises[i]->nombre+"\t\t Cantidad: "+QString::number(arrayPaises[i]->cantidad)+"\n";
        }
        return respuesta;
    }

    QString toStringMenores(){
        QString respuesta= "";
        for(int i = 0; i<5; i++) {
            respuesta += QString::number(i+1)+" # "+arrayPaises[i]->nombre+"\t\t Cantidad: "+QString::number(arrayPaises[i]->cantidad)+"\n";
        }
        return respuesta;
    }
    void imprimir(){
        for(int i = 0; i<10; i++) {
            qDebug()<<i+1<<" # "<<arrayPaises[i]->nombre<<"\t\t\t\t\tCantidad: "<<arrayPaises[i]->cantidad;

        }
    }

    void imprimir2(){
        for(int i = 0; i<5; i++) {
            qDebug()<<i+1<<" # "<<arrayPaises[i]->nombre<<"\t\t\t\t\tCantidad: "<<arrayPaises[i]->cantidad;
        }
    }

    void bubbleSortMayorMenor(Files * file){
        PaisesData *temp = new PaisesData();
        for(int i = 0; i<file->index; i++) {
           for(int j = i+1; j<file->index; j++)           {
              if(arrayPaises[j]->cantidad > arrayPaises[i]->cantidad) {
                 *temp = *arrayPaises[i];
                 *arrayPaises[i] = *arrayPaises[j];
                 *arrayPaises[j] = *temp;
              }
           }
        }
    }

    void bubbleSortMenorMayor(Files * file){
        PaisesData *temp = new PaisesData();
        for(int i = 0; i<file->index; i++) {
           for(int j = i+1; j<file->index; j++)           {
              if(arrayPaises[j]->cantidad < arrayPaises[i]->cantidad) {
                 *temp = *arrayPaises[i];
                 *arrayPaises[i] = *arrayPaises[j];
                 *arrayPaises[j] = *temp;
              }
           }
        }
    }
};

struct Mundo{
    ListaDoblePersonas * personas;
    Files * files;
    ArbolPersonas * treePersonas;
    ArbolFamilias * treeFamilias;
    ListaSimpleArbolFamilias * listArbolFamilias;
    ArrayContinent *arrayBuenasAccionesMapa;
    ArrayContinent *arrayPecadosMapa;
    ArrayPaises *arrayBuenasAcciones;
    ArrayPaises *arrayPecados;
    Infierno * infierno;

    Mundo(QLabel * lbBuenasAccionesMapa[],QLabel * lbPecadosMapa[]){
        personas = new ListaDoblePersonas();
        treePersonas = new ArbolPersonas();
        files = new Files();
        treeFamilias = new ArbolFamilias();
        listArbolFamilias = new ListaSimpleArbolFamilias();
        arrayBuenasAccionesMapa = new ArrayContinent(lbBuenasAccionesMapa);
        arrayPecadosMapa = new ArrayContinent(lbPecadosMapa);
        arrayBuenasAcciones = new ArrayPaises(files);
        arrayPecados = new ArrayPaises(files);

        infierno = new Infierno();
    }

    void crearHumanos(int);
    void crearArbol();
    void crearArbol(NodoPersona* array[], int);
    void hacerPecar();
    void hacerHerencia(Persona *,int, int, int);

    void guarDatosWorld();
    void buscarHuman(int , QLabel* );

    void continentsMasBuenasAcciones();
    void continentsMasPecados();

    void top10Cielo(QLabel *);
    void top5Cielo(QLabel *);
    void top10Infierno(QLabel *);
    void top5Infierno(QLabel *);
};

#endif // STRUCT_MUNDO_H
