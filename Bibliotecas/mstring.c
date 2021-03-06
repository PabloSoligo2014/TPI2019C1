#include "mstring.h"

#include <string.h>
#include <stdlib.h>

#include "Tipos.h"


char* shiftRight(char* sentence, int spaces)
{
    char* original = sentence;
    while (*sentence != '\0') {
        sentence++;
    }
    while (sentence > original) {
        *(sentence + spaces) = *sentence;
        sentence--;
    }
    return original;
}

char* normalizarNyAp(char* frase)
{
    char isSpaceAfterLetter = 0,
         isPastFirstLetter = 0,
         isSurnameDone = 0;
    char *writer, *reader;

    writer = frase;
    reader = frase;

    while (*reader != '\0') {
        // The only valid characters are letters, spaces, and commas. All others get ignored.
        if (ISALPHA(*reader) || (*reader == ' ' && isSpaceAfterLetter) || (*reader == ',' && !isSurnameDone)) {
            if (ISALPHA(*reader)) {
                // The first letter after letter gets capitalized. The rest get the opposite treatment.
                if (!isPastFirstLetter) {
                    isPastFirstLetter = 1;
                    *writer = TOUPPER(*reader);
                } else {
                    *writer = TOLOWER(*reader);
                }
            } else {
                if (isPastFirstLetter) {
                    // If we got to a space or a comma, that means its the end of a word.
                    if (!isSurnameDone) {
                        // At the end of the first word (the surname), goes a comma.
                        *writer = ',';
                        writer++;
                        isSurnameDone = 1;
                        // If there is not a non-letter character directly after the first space after the surname, we must shift the rest of the string on space forwards, or the program will get stuck on an infinite loop.
                        if (!ISALPHA(*(reader + 1))) {
                            shiftRight(reader, 1);
                            reader++;
                        }
                    }
                    isPastFirstLetter = 0;
                }
                // We put a space after the comma, just in case there isn't one.
                *writer = ' ';
            }
            // After writing each character, we move to the next free space.
            writer++;
        }

        // We only need to change these flags under two circumstances: At the first space after a word, and at the first letter after a space.
        if ((isSpaceAfterLetter) && (!ISALPHA(*reader)))
            isSpaceAfterLetter = 0;
        if ((!isSpaceAfterLetter) && (ISALPHA(*reader)))
            isSpaceAfterLetter = 1;

        // After operating, we move to the next character.
        reader++;
    }

    // If the null character is right after the last letter, then the normal algorithm would leave an orphan space at the end of the string. This solved by checking for this orphan space and placing the null character accordingly.
    if (*(writer - 1) == ' ')
        *(writer - 1) = '\0';
    else
        *writer = '\0';
    return frase;
}


int getEvent(char c)
{
    if (ISALPHA(c))
    {
        return 1;
    }
    else
    {
        if(c=='\0')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
}

void swap(char* v1, char* v2)
{
    char aux = *v1;
    *v1 = *v2;
    *v2 = aux;

}

typedef struct
{
    char* piv;
    char* pa;
    enum TEstadoPalabra ep;
} t_meparam;


int mstrpartir(char* code, int* v)
{
    char aux[24];
    int i = 0;
    char* pos = strchr(code, '.');
    while(pos)
    {
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

int mstrlen(const char* pl)
{
    int result = 0;
    while(*pl)
    {
        pl++;
        result++;
    }
    return result;
}
