#include "TestsFechas.h"
#include "../Bibliotecas/Fecha.h"
#include <string.h>
#include <stdio.h>


int testComparacionFechas01(char msg[]){
    int cmp;
    t_fecha fecha1 = {10,10,1998};
    t_fecha fecha2 = {10,11,2005};

    strcpy(msg, "Comparacion de fechas");
    cmp = cmpfecha(&fecha1, &fecha2);
    if(cmp>0){
        sprintf(msg, "Error, comparando fechas 01\n");
        return 1;
    }

    return 0;
}

int testComparacionFechas02(char msg[]){
    int cmp;
    t_fecha fecha1 = {1,11,1998};
    t_fecha fecha2 = {31,10,1998};

    strcpy(msg, "Comparacion de fechas");
    cmp = cmpfecha(&fecha1, &fecha2);
    if(cmp<0){
        sprintf(msg, "Error, comparando fechas 02\n");
        return 1;
    }

    return 0;

}
int testFechaValida01(char msg[]){
    t_fecha fecha1 = {29,2,1976};


    strcpy(msg, "Fecha valida");
    if(!es_fecha_valida(&fecha1)){
        sprintf(msg, "\nError, validando fecha 29/02/1976");
        return 1;
    }

    return 0;


}
int testFechaValida02(char msg[]){
    t_fecha fecha1 = {30,2,1976};


    strcpy(msg, "Fecha valida");
    if(es_fecha_valida(&fecha1)){
        sprintf(msg, "\nError, validando fecha 29/02/1976");
        return 1;
    }

    return 0;


}
