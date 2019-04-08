#include "TestsFechas.h"
#include "../Bibliotecas/Fecha.h"


int testCrearFechas(char msg[]){
    t_fecha fecha;

    if(!crearFecha(&fecha, 30,10,1976)){
        strcpy(msg, "No se pudo crear la fecha 30/10/1976");
        return 0;
        //Se puede usar sprintf, es una buena arternativa tambien
    }
    return 1;
}
