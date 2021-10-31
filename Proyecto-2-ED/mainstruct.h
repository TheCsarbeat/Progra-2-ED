#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H

#include "struct_mundo.h"

struct MainStruct;

struct MainStruct{
    Mundo * mundo;
    MainStruct(){
        mundo = new Mundo();
    }

};

#endif // MAINSTRUCT_H
