#include <stdio.h>
#include "Tests.h"

#include "TestsTipos.h"
#include "TestsFechas.h"


int EjecutarTests(){
    char msg[100];
    t_tstfun atest[] = {    &testCrearFechaInvalida,
                            &testComparacionFechas01

                        };
    puts("----------------------------------------------------------");
    for(int i=0; i<sizeof(atest)/4;i++){

        if (atest[i](msg)){
            printf("TEST %02d FALLO  : %s\n", i,msg);
        }else{
            printf("TEST %02d OK     : %s\n", i,msg);
        }
    }
    puts("----------------------------------------------------------");
    return 1;

}
