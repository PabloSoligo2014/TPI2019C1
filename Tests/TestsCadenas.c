#include "TestsCadenas.h"
#include "../Bibliotecas/mstring.h"
#include <string.h>
#include <stdio.h>

int testNormalizarCadenaNyAp01(char msg[]){

    static char strtest[] = "   vAlderraMA &&9 cArlos alberto         ";
    static char result[] = "Valderrama, Carlos Alberto";
    strcpy(msg, "Test normalizacion cadena NyAp01");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }

    return 0;
}

int testNormalizarCadenaNyAp02(char msg[]){

    static char strtest[] = "Dosantos, Manuel Francisco";
    static char result[] = "Dosantos, Manuel Francisco";
    strcpy(msg, "Test normalizacion cadena NyAp02");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }

    return 0;
}

int testNormalizarCadenaNyAp03(char msg[]){

    static char strtest[] = "belTRAN dAniel GERONIMO%%%%%";
    static char result[] = "Beltran, Daniel Geronimo";
    strcpy(msg, "Test normalizacion cadena NyAp03");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }
    return 0;
}
