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

    static char strtest[] = "belTRAN daniel GERONIMO%%%%%";
    static char result[] = "Beltran, Daniel Geronimo";
    strcpy(msg, "Test normalizacion cadena NyAp03");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }
    return 0;
}

int testNormalizarCadenaNyAp04(char msg[]){

    static char strtest[] = "GonzALEz, to#%&Bias FrAnCo";
    static char result[] = "Gonzalez, Tobias Franco";
    strcpy(msg, "Test normalizacion cadena NyAp04");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }
    return 0;
}

int testNormalizarCadenaNyAp05(char msg[]){

    static char strtest[] = "       &$/7aNTOni&//772o       mArco       7";
    static char result[] = "Antonio, Marco";
    strcpy(msg, "Test normalizacion cadena NyAp05");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }
    return 0;
}

int testNormalizarCadenaNyAp06(char msg[]){

    static char strtest[] = ")( \t     AndER///Son,,, John     ";
    static char result[] = "Anderson, John";
    strcpy(msg, "Test normalizacion cadena NyAp06");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }
    return 0;
}

int testNormalizarCadenaNyAp07(char msg[]){

    static char strtest[] = "      \n\nLaLONDE,,,Rose GRImd,a99rk";
    static char result[] = "Lalonde, Rose Grimdark";
    strcpy(msg, "Test normalizacion cadena NyAp07");
    if (strcmp(normalizarNyAp(strtest), result)!=0) {
        sprintf(msg, "\nError, normalizacion incorrecta.\nRetorno %s cuando debio retornar %s", strtest, result);
        return 1;
    }
    return 0;
}
