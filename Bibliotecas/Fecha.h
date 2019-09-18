#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
}t_fecha;




void setHoy(int dia, int mes, int an);
int getHoy(t_fecha* hoy);

void mostrarFechaDMA(const t_fecha *fec);
int ingresarFecha(t_fecha* fecha);
int cant_dias(int mes, int anio);
int es_fecha_valida(t_fecha* fecha);
int cmpfecha(const t_fecha *fec1, const t_fecha *fec2);


#endif // FECHA_H_INCLUDED
