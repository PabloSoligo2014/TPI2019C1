#ifndef MSTRING_H_INCLUDED
#define MSTRING_H_INCLUDED

#define ISALPHA(X) ((X>='A') && (X<='Z')) || ((X>='a') && (X<='z'))

#define TOLOWER(X) ((X>='A') && (X<='Z'))?X=X+32:X
#define TOUPPER(X) ((X>='a') && (X<='z'))?X=X-32:X


enum TEstadoPalabra{esDefault, esPalabra, esNoPalabra};



char* mnormalizar(char* cad);
char* mnormalizar_pormatriz(char* cad);

int mstrpartir(char* code, int* v);
int mstrlen(const char* pl);
void mcharswap(char* a, char* b);
char* mstrreverse(char* str);
char* mstrreverse2(char* ini, char* fin);
char* mcifrate(char* ini, int offset);
char* mcifrate2(char* ini, char *fin, int offset);



char* mstrncpy(char* sDest, const char* sSource, unsigned int cant);
char* mstr_insert(char* dest, const char* source, unsigned int pos);

char* mproximaPalabra(char* frase, int* len);
#endif // MSTRING_H_INCLUDED
