#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

#include "struct_personas.h"
#include "struct_file.h"
#include "struct_arbolfamilias.h"
#include "struct_infierno.h"
#include "struct_cielo.h"

#include <QMessageBox>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include <QtMath>
#include <QStringList>




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
struct ArrayApellidos;
struct ApellidosData{
    QString apellido;
    int cantidad;
    ApellidosData(){
        apellido = "";
        cantidad = 0;
    }

};
struct ArrayCreencias;
struct CreenciaData{
    QString nombre;
    int cantidad;
    CreenciaData(){
        nombre = "";
        cantidad = 0;
    }

};
struct ArrayProfesiones;
struct ProfesionData{
    QString nombre;
    int cantidad;
    ProfesionData(){
        nombre = "";
        cantidad = 0;
    }

};

struct ArrayContinentes;
struct ContinentesData{
    QString nombre;
    int cantidad;
    ContinentesData(){
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
    int cantidadPecados;
    int cantidadBA;

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
            respuesta += QString::number(i+1)+" # "+arrayPaises[i]->nombre+"\n";
        }
        return respuesta;
    }

    QString toStringMayoresCantidad(){
        QString respuesta= "";
        for(int i = 0; i<10; i++) {
            respuesta += "Cantidad: "+QString::number(arrayPaises[i]->cantidad)+"\n";
        }
            return respuesta;
    }

    QString toStringMenores(){
        QString respuesta= "";
        for(int i = 0; i<5; i++) {
            respuesta += QString::number(i+1)+" # "+arrayPaises[i]->nombre+"\n";
        }
        return respuesta;
    }

    QString toStringMenoresCantidad(){
        QString respuesta= "";
        for(int i = 0; i<5; i++) {
            respuesta += "Cantidad: "+QString::number(arrayPaises[i]->cantidad)+"\n";
        }
            return respuesta;
     }

    QString toStringPaises(Files * file){
        QString respuesta= "";
        for(int i = 0; i<file->index; i++) {
            respuesta += QString::number(i+1)+" # "+arrayPaises[i]->nombre+"\tCantidad: " + QString::number(arrayPaises[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayPaises[i]->cantidad*100)/cantidadPecados)+ " %" +"\n";
        }
        return respuesta;
    }

    QString toStringPaises2(Files * file){
        QString respuesta= "";
        for(int i = 0; i<file->index; i++) {
            respuesta += QString::number(i+1)+" # "+arrayPaises[i]->nombre+"\tCantidad: " + QString::number(arrayPaises[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayPaises[i]->cantidad*100)/cantidadBA)+ " %" +"\n";
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

    void bubbleSort(Files * file){
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
};

struct ArrayApellidos{
    ApellidosData *arrayApellidos[566];
    int cantidadPecados;
    int cantidadBA;
    ArrayApellidos(Files * file){
        int cantidad = file->indexLasName;
        cantidadPecados = 0;
        for (int i=0; i<cantidad; i++){
            arrayApellidos[i] = new ApellidosData();
            arrayApellidos[i]->apellido = file->lastNames[i];

        }
    }

    QString toStringApellidos(){
        QString respuesta= "";
        for(int i = 0; i<50; i++) {
            respuesta += QString::number(i+1)+" # "+arrayApellidos[i]->apellido+"\tCantidad: " + QString::number(arrayApellidos[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayApellidos[i]->cantidad*100)/cantidadPecados)+ " %" +"\n";
        }
        return respuesta;
    }

    QString toStringApellidos2(){
        QString respuesta= "";
        for(int i = 0; i<50; i++) {
            respuesta += QString::number(i+1)+" # "+arrayApellidos[i]->apellido+"\tCantidad: " + QString::number(arrayApellidos[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayApellidos[i]->cantidad*100)/cantidadBA)+ " %" +"\n";
        }
        return respuesta;
    }

    void bubbleSort(Files * file){
        ApellidosData *temp = new ApellidosData();
        for(int i = 0; i<file->indexLasName; i++) {
           for(int j = i+1; j<file->indexLasName; j++)           {
              if(arrayApellidos[j]->cantidad > arrayApellidos[i]->cantidad) {
                 *temp = *arrayApellidos[i];
                 *arrayApellidos[i] = *arrayApellidos[j];
                 *arrayApellidos[j] = *temp;
              }
           }
        }
    }
};

struct ArrayProfesiones{
    ProfesionData *arrayProfesiones[80];
    int cantidadPecados;
    int cantidadBA;
    ArrayProfesiones(Files * file){
        int cantidad = file->indexJobs;
        for (int i=0; i<cantidad; i++){
            arrayProfesiones[i] = new ProfesionData();
            arrayProfesiones[i]->nombre = file->jobs[i];
        }
    }

    QString toStringProfesiones(){
        QString respuesta= "";
        for(int i = 0; i<80; i++) {
            respuesta += QString::number(i+1)+" # "+arrayProfesiones[i]->nombre+"\tCantidad: " + QString::number(arrayProfesiones[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayProfesiones[i]->cantidad*100)/cantidadPecados)+ " %" +"\n";
        }
        return respuesta;
    }

    QString toStringProfesiones2(){
        QString respuesta= "";
        for(int i = 0; i<80; i++) {
            respuesta += QString::number(i+1)+" # "+arrayProfesiones[i]->nombre+"\tCantidad: " + QString::number(arrayProfesiones[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayProfesiones[i]->cantidad*100)/cantidadBA)+ " %" +"\n";
        }
        return respuesta;
    }

    void bubbleSort(){
        ProfesionData *temp = new ProfesionData();
        for(int i = 0; i<80; i++) {
            for(int j = i+1; j<80; j++){
                if(arrayProfesiones[j]->cantidad > arrayProfesiones[i]->cantidad) {
                    *temp = *arrayProfesiones[i];
                    *arrayProfesiones[i] = *arrayProfesiones[j];
                    *arrayProfesiones[j] = *temp;
                 }
             }
        }
    }
};

struct ArrayCreencias{
    CreenciaData *arrayCreencia[19];
    int cantidadPecados;
    int cantidadBA;

    ArrayCreencias(Files * file){
        int cantidad = file->indexReligions;
        for (int i=0; i<cantidad; i++){
            arrayCreencia[i] = new CreenciaData();
            arrayCreencia[i]->nombre = file->religions[i];
        }
    }

    QString toStringCreencia(){
        QString respuesta= "";
        for(int i = 0; i<19; i++) {
            respuesta += QString::number(i+1)+" # "+arrayCreencia[i]->nombre+"\tCantidad: " + QString::number(arrayCreencia[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayCreencia[i]->cantidad*100)/cantidadPecados)+ " %" +"\n";
        }
        return respuesta;
    }

    QString toStringCreencia2(){
        QString respuesta= "";
        for(int i = 0; i<19; i++) {
            respuesta += QString::number(i+1)+" # "+arrayCreencia[i]->nombre+"\tCantidad: " + QString::number(arrayCreencia[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayCreencia[i]->cantidad*100)/cantidadBA)+ " %" +"\n";
        }
        return respuesta;
    }

    void bubbleSort(){
        CreenciaData *temp = new CreenciaData();
        for(int i = 0; i<19; i++) {
            for(int j = i+1; j<19; j++){
                if(arrayCreencia[j]->cantidad > arrayCreencia[i]->cantidad) {
                    *temp = *arrayCreencia[i];
                    *arrayCreencia[i] = *arrayCreencia[j];
                    *arrayCreencia[j] = *temp;
                 }
             }
        }
    }
};

struct ArrayContinentes{

    QString names[5] = {"america", "africa", "europa","oceania", "asia"};
    ContinentesData *arrayContinentes[7];
    int cantidadPecados;
    int cantidadBA;

    ArrayContinentes(){

        for (int i=0; i<5; i++){
            arrayContinentes[i] = new ContinentesData();
            arrayContinentes[i]->nombre = names[i];
        }
    }

    QString toStringContinentes(){
        QString respuesta= "";
        for(int i = 0; i<5; i++) {
            respuesta += QString::number(i+1)+" # "+arrayContinentes[i]->nombre+"\tCantidad: " + QString::number(arrayContinentes[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayContinentes[i]->cantidad*100)/cantidadPecados)+ " %" +"\n";
        }
        return respuesta;
    }

    QString toStringContinentes2(){
        QString respuesta= "";
        for(int i = 0; i<5; i++) {
            respuesta += QString::number(i+1)+" # "+arrayContinentes[i]->nombre+"\tCantidad: " + QString::number(arrayContinentes[i]->cantidad)+
                    "\t\tPorcentaje: "+QString::number((double)(arrayContinentes[i]->cantidad*100)/cantidadBA)+ " %" +"\n";
        }
        return respuesta;
    }

    void bubbleSort(){
        ContinentesData *temp = new ContinentesData();
        for(int i = 0; i<5; i++) {
            for(int j = i+1; j<5; j++){
                if(arrayContinentes[j]->cantidad > arrayContinentes[i]->cantidad) {
                    *temp = *arrayContinentes[i];
                    *arrayContinentes[i] = *arrayContinentes[j];
                    *arrayContinentes[j] = *temp;
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
    CieloHash *cielo;
    ArbolAngelesCielo *arbolAngeles;
    ArrayApellidos * arrayBAapellidos;
    ArrayApellidos * arrayPecadoApellidos;
    ArrayCreencias * arrayBAcreencias;
    ArrayCreencias * arrayPecadoCreencias;
    ArrayProfesiones * arrayBAprofesiones;
    ArrayProfesiones * arrayPecadoProfesiones;
    ArrayPaises * arrayBAPaises;
    ArrayPaises * arrayPecadoPaises;
    ArrayContinentes * arrayBAContinentes;
    ArrayContinentes * arrayPecadosContinentes;

    QStringList filesNameToSend;
    QString currentFileName;

    Mundo(QLabel * lbBuenasAccionesMapa[],QLabel * lbPecadosMapa[], QComboBox * cbo[]){
        personas = new ListaDoblePersonas();
        treePersonas = new ArbolPersonas();
        files = new Files(cbo);
        treeFamilias = new ArbolFamilias();
        listArbolFamilias = new ListaSimpleArbolFamilias();
        arrayBuenasAccionesMapa = new ArrayContinent(lbBuenasAccionesMapa);
        arrayPecadosMapa = new ArrayContinent(lbPecadosMapa);
        arrayBuenasAcciones = new ArrayPaises(files);
        arrayPecados = new ArrayPaises(files);
        infierno = new Infierno();
        cielo = new CieloHash();
        arbolAngeles = new ArbolAngelesCielo();
        arrayPecadoApellidos = new ArrayApellidos(files);
        arrayBAapellidos = new ArrayApellidos(files);
        arrayBAcreencias = new ArrayCreencias(files);
        arrayBAprofesiones = new ArrayProfesiones(files);
        arrayPecadoProfesiones = new ArrayProfesiones(files);
        arrayBAPaises = new ArrayPaises(files);
        arrayPecadoPaises = new ArrayPaises(files);
        arrayBAContinentes = new ArrayContinentes();
        arrayPecadosContinentes = new ArrayContinentes();
        arrayPecadoCreencias = new ArrayCreencias(files);


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

    void top10Cielo(QLabel *,QLabel *);
    void top5Cielo(QLabel *, QLabel *);
    void top10Infierno(QLabel *, QLabel *);
    void top5Infierno(QLabel *, QLabel *);

    void salvacion();
    void buscarBAFamilias(int,QLabel *);
    void buscarPecadosFamilias(int,QLabel *);

    void consutlaHumanStateFamily(QString , QString ,QLabel *);


    void apellidosPecadores(QLabel *);
    void apellidosBA(QLabel *);
    void continentesPecadores(QLabel *);
    void continentesBA(QLabel *);
    void paisesPecadores(QLabel *);
    void paisesBA(QLabel *);
    void creenciasPecadores(QLabel *);
    void creenciasBA(QLabel *);
    void profesionesPecadores(QLabel *);
    void profesionesBA(QLabel *);
};

#endif // STRUCT_MUNDO_H
