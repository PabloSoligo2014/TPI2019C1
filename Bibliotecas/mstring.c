#include "mstring.h"

#include <string.h>
#include <stdlib.h>

#include "Tipos.h"


char* normalizarNyAp(char* frase){
    //Implementar aqui la funcion
    return frase;
}


int getEvent(char c){
    if (ISALPHA(c)){
        return 1;
    }else{
        if(c=='\0'){
            return 2;
        }else{
            return 0;
        }
    }
}

void swap(char* v1, char* v2){
    char aux = *v1;
    *v1 = *v2;
    *v2 = aux;

}

typedef struct{
    char* piv;
    char* pa;
    enum TEstadoPalabra ep;
}t_meparam;


int mstrpartir(char* code, int* v){
    char aux[24];
    int i = 0;
    char* pos = strchr(code, '.');
    while(pos){
        strncpy(aux, code, pos-code);

        *(aux + (pos-code)) = '\0';

        *(v+(i++)) = atoi(aux);
        pos++;
        code = pos;
        pos = strchr(pos, '.');
    }

    /*Queda el ultimo numero*/
    strcpy(aux, code);
    *(v+(i++)) = atoi(aux);
    return i;
}

int mstrlen(const char* pl){
    int result = 0;
    while(*pl){
        pl++;
        result++;
    }
    return result;
}

