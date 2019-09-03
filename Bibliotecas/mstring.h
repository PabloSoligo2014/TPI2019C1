#ifndef MSTRING_H_INCLUDED
#define MSTRING_H_INCLUDED

#define ISALPHA(X) ((X>='A') && (X<='Z')) || ((X>='a') && (X<='z'))

#define TOLOWER(X) ((X>='A') && (X<='Z'))?X=X+32:X
#define TOUPPER(X) ((X>='a') && (X<='z'))?X=X-32:X


enum TEstadoPalabra{esDefault, esPalabra, esNoPalabra};




int mstrpartir(char* code, int* v);

/*---------------------Alumnos------------------------*/

/*! \brief Normaliza nombre y apellido.
 *
 *
 *  Normaliza nombre y apellido, dejando la primera palabra como apellido, luego una coma para despues
 *  dejar los nombres, todas las palabras comienzan con mayusculas para quedar el resto como minisculas
 *  Ej: vAlderraMA &&9 cArlos alberto => Valderrama, Carlos Alberto
 */
char* normalizarNyAp(char* frase);



/*----------------------------------------------------*/
#endif // MSTRING_H_INCLUDED
