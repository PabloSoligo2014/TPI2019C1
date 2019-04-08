#include "mstring.h"

#include <string.h>
#include <stdlib.h>

#include "Tipos.h"

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



int defaultLetra(void* params){
    t_meparam* p = params;
    TOUPPER(*(p->piv));
    swap(p->piv, p->pa);

    p->ep = esPalabra;
    p->pa++;

    return 1;
}

int defaultFin(void* params){
    t_meparam* p = params;
    swap(p->piv, p->pa);
    return 0;
}

int PalabraNoLetra(void* params){
    t_meparam* p = params;
    p->ep = esNoPalabra;
    *(p->pa) = ' ';
    p->pa++;
    return 1;
}

int PalabraLetra(void* params){
    t_meparam* p = params;
    TOLOWER(*(p->piv)) ;
    swap(p->piv, p->pa);
    p->pa++;
    return 1;
}


int PalabraFin(void* params){
    t_meparam* p = params;
    swap(p->piv, p->pa);
    return 0;
}


int NoPalabraLetra(void* params){
    t_meparam* p = params;
    p->ep = esPalabra;
    TOUPPER(*p->piv);
    swap(p->piv, p->pa);
    p->pa++;

    return 1;
}

int NoPalabraFin(void* params){
    t_meparam* p = params;
    swap(p->piv, p->pa);

    return 0;
}




char* mnormalizar_pormatriz(char* cad){

    t_meparam param;
    t_action me[3][3] = {
                            { NULL          , defaultLetra  , defaultFin},
                            { PalabraNoLetra, PalabraLetra  , PalabraFin},
                            { NULL          , NoPalabraLetra, NoPalabraFin}
                        };


    int acontinue = 1;
    param.piv = cad;
    param.pa = cad;
    param.ep = esDefault;


    while(acontinue){
        int eve = getEvent(*param.piv);

        if (me[param.ep][eve]!=NULL){
            acontinue = me[param.ep][eve](&param);
        }


        param.piv++;
    }



    return cad;
}


char* mnormalizar(char* cad){
    //Normaliza una cadena sobre la cadena misma
    //Version sin punteros a funciones
    char* piv = cad;
    char* pi  = cad;
    //0. NO es alfa, 1. Es alfa, 2 es fin de cadena
    int eve;
    enum TEstadoPalabra estado = esDefault;
    int terminated = 0;
    while(!terminated){
        eve = getEvent(*piv);
        switch(eve){
            case 0: //No es alfa
                switch(estado){
                    case esDefault:
                        break;
                    case esPalabra:
                        estado=esNoPalabra;
                        break;
                    case esNoPalabra:
                        break;
                }

                break;
            case 1: //Es Alfa
                switch(estado){
                    case esDefault:
                        TOUPPER(*piv);
                        swap(piv, pi);
                        pi++;
                        estado = esPalabra;
                        break;
                    case esPalabra:
                        TOLOWER(*piv);
                        swap(piv, pi);
                        pi++;
                        break;
                    case esNoPalabra:
                        TOUPPER(*piv);
                        *pi=' ';
                        pi++;
                        swap(piv, pi);
                        pi++;
                        estado = esPalabra;
                        break;
                }
                break;
            case 2: //Es fin cadena
                switch(estado){
                    case esDefault:
                        swap(piv, pi);
                        terminated = 1;
                        break;
                    case esPalabra:
                        swap(piv, pi);
                        terminated = 1;
                        break;
                    case esNoPalabra:
                        swap(piv, pi);
                        terminated = 1;
                        break;
                }
                break;

        }
        piv++;
    };




    return cad;
}

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

void mcharswap(char* a, char* b){
    char aux = *a;
    *a = *b;
    *b = aux;
}

char* mstrreverse(char* str){
    int l = mstrlen(str);
    char* fin = str + l - 1;
    return mstrreverse2(str, fin);
}

char* mstrreverse2(char* ini, char* fin){
    char* result = ini;
    while(ini<fin){
        mcharswap(ini, fin);
        ini++;
        fin--;
    }
    return result;
}


char* mcifrate(char* ini, int offset){
    int l = mstrlen(ini);

    return mcifrate2(ini, ini+l-1, offset);
}


char* mcifrate2(char* ini, char *fin, int offset){

    char* res = ini;
    while(ini<=fin){
        *ini = *ini+offset;
        if((*ini>'Z')&&(*ini<'a')){
            *ini+='a'-'Z'-1 ;
        }
        if(*ini>'z'){
            *ini-='z'-'A'+1;
        }

        ini++;
    }
    return res;
}


char* mstrncpy(char* sDest, const char* sSource, unsigned int cant){

    int i = 0;
    char *result = sDest;

    for(i=0;i<cant;i++){
        *sDest = *sSource;
        sDest++;
        sSource++;
    }

    return result;
}



char* mstr_insert(char* dest, const char* source, unsigned int pos){

    char* li = dest + pos - 1;
    char* ls = dest + mstrlen(dest) + mstrlen(source);
    int mv = mstrlen(source);
    *(ls+1)='\0';
    while(ls>li){
        *ls=*(ls-mv);
        ls--;
    }
    strncpy(ls, source, mv);

    return dest;
}

char* mproximaPalabra(char* frase, int* len){

    char* ini = frase;
    *len = 0;


    int alfa = ISALPHA(*frase);

    while( (*frase!='\0') && (*frase!='.') && (!alfa) ){
        frase++;
        alfa = ISALPHA(*frase);
    }

    if(ISALPHA(*frase)){
        ini = frase;
    }else{
        return NULL;
    }

    alfa = ISALPHA(*frase);
    while( (*frase!='\0') && (*frase!='.') && (alfa) ){
        (*len)++;
        frase++;
        alfa = ISALPHA(*frase);
    }
    return ini;



}
