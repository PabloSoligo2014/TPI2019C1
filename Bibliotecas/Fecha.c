#include "Fecha.h"

static t_fecha shoy;

void setHoy(int dia, int mes, int an){
    shoy.dia = dia;
    shoy.mes = mes;
    shoy.anio = an;
}

int getHoy(t_fecha* hoy){
    *hoy = shoy;
    return 1;
}


int crearFecha(t_fecha* fecha, int dia, int mes, int anio){
    fecha->dia = 0;
    fecha->mes = 0;
    fecha->anio = 0;

    //Poner validacion aca...
    //Implementar

    return 0;

}


int cmpFecha(t_fecha* fecha1, t_fecha* fecha2){
    //Implementar!

    return 0;

}



