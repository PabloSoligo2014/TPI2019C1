#include <stdio.h>
#include "Tests.h"

#include "TestsTipos.h"
#include "TestsFechas.h"


int EjecutarTests(){
    char msg[100];
    t_tstfun atest[] = {&testCrearFechas};

    for(int i=0; i<sizeof(t_tstfun)/4;i++){

        if (!atest[i](msg)){
            printf("Fallo test %s", msg);
            return 0;
        }
    }
    return 1;

}
