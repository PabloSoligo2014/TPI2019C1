#include <stdio.h>
#include "Tests.h"

#include "TestsTipos.h"
#include "TestsFechas.h"
#include "TestsCadenas.h"

int EjecutarTestsFechas(){
    char msg[500];
    t_tstfun atest[] = {    &testCrearFechaInvalida,
                            &testComparacionFechas01


                        };
    puts("----------------------------------------------------------");
    //De esta manera no importa si tengo compilador de 16, 32 o 64 bits
    int i;
    for(i=0; i<sizeof(atest)/sizeof(atest[0]);i++){

        if (atest[i](msg)){
            printf("TEST %02d FALLO: %s\n", i,msg);
        }else{
            printf("TEST %02d OK   : %s\n", i,msg);
        }
    }
    puts("----------------------------------------------------------");
    return 1;

}

int EjecutarTestsCadenas(){
    char msg[500];
    t_tstfun atest[] = {
                            &testNormalizarCadenaNyAp01,
                            &testNormalizarCadenaNyAp02,
                            &testNormalizarCadenaNyAp03,
                            &testNormalizarCadenaNyAp04,
                            &testNormalizarCadenaNyAp05,
                            &testNormalizarCadenaNyAp06,
                            &testNormalizarCadenaNyAp07
                        };
    puts("----------------------------------------------------------");
    //De esta manera no importa si tengo compilador de 16, 32 o 64 bits
    int i;
    for(i=0; i<sizeof(atest)/sizeof(atest[0]);i++){

        if (atest[i](msg)){
            printf("TEST %02d FALLO: %s\n", i,msg);
        }else{
            printf("TEST %02d OK   : %s\n", i,msg);
        }
    }


    puts("----------------------------------------------------------");
    return 1;

}



