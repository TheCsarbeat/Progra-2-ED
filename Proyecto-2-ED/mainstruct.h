#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H

#include "struct_mundo.h"


struct MainStruct;

struct MainStruct{
    Mundo * mundo;
    MainStruct(QLabel * lbBuenasAccionesMapa[],QLabel * lbPecadosMapa[], QComboBox * cbo[]){
        mundo = new Mundo(lbBuenasAccionesMapa, lbPecadosMapa);
    }

};

#endif // MAINSTRUCT_H
