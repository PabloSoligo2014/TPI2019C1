#include <stdio.h>
#include "Fecha.h"
#define ESBISIESTO(X) (   ((X)%4==0 && (X)%100!=0 ) || (X)%400==0  )?1:0


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


int ingresarFecha(t_fecha* fecha)
{
    fecha->dia = 0;
    fecha->mes = 0;
    fecha->anio = 0;
    fflush(stdin);
    scanf("%d%d%d",&fecha->dia, &fecha->mes, &fecha->anio);
    if(!es_fecha_valida(fecha))
    {
      return 0;
    }
    return 1;
}

int es_fecha_valida(t_fecha* fecha)
{

    if (fecha->anio>1600 && fecha->mes>=1&&fecha->mes<=12 &&
           (fecha->dia>=1) && (fecha->dia<=cant_dias(fecha->mes, fecha->anio)))

                return 1;
            else
                return 0;
    return 0;
}

int cant_dias(int mes, int anio)
{
    static int vd[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(mes==2 && ESBISIESTO(anio)==1)
    {
        return 29;
    }
return vd[mes-1];
}


void mostrarFechaDMA(const t_fecha *fec)
{
    printf("\n%02d/%02d/%04d\n",fec->dia,fec->mes,fec->anio);
}

int cmpfecha (const t_fecha *fec1, const t_fecha *fec2)
{
    int cmp,cmp2,cmp3;

    cmp= fec2->anio - fec1->anio;
    cmp2= fec2->mes -fec1->mes;
    cmp3= fec2->dia - fec1->dia;

     if(cmp3>0 && cmp>=0 &&cmp2>=0)
    {
        return 1;
    }
    else if(cmp3==0 && cmp==0 && cmp2==0)
    {
        return 0;

    }
    return -1;
}




