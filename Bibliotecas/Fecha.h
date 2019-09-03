#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
}t_fecha;




void setHoy(int dia, int mes, int an);
int getHoy(t_fecha* hoy);

int crearFecha(t_fecha* fecha, int dia, int mes, int anio);
int cmpFecha(t_fecha* fecha1, t_fecha* fecha2);
#endif // FECHA_H_INCLUDED
