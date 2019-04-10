#include "TestsFechas.h"
#include "../Bibliotecas/Fecha.h"
#include <string.h>




int testCrearFechaInvalida(char msg[]){
    t_fecha fecha;
    strcpy(msg, "Validacion de fechas");
    if(crearFecha(&fecha, 80,10,1998)){
        strcpy(msg, "Error, se permitio crear una fecha invalida");
        return 1;
        //Se puede usar sprintf, es una buena arternativa tambien
    }
    return 0;
}



int testComparacionFechas01(char msg[]){

    t_fecha fecha1;
    t_fecha fecha2;

    strcpy(msg, "Comparacion de fechas");
    crearFecha(&fecha1, 10,10,1998);
    crearFecha(&fecha2, 10,11,2005);
    //Continuar aca
    strcpy(msg, "Error en al comparacion de fechas...");
    return 1;



}
