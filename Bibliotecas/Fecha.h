#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
}t_fecha;


int crearFecha(t_fecha* fecha, int dia, int mes, int anio);
#endif // FECHA_H_INCLUDED
