#include "Alumno.h"
#include <stdio.h>
#include <string.h>
int ingresarAlumno()
{
    t_alumno al;
    t_fecha hoy;
    int errores[6] = {0};
    getHoy(&hoy);
    printf("\nIngrese DNI del alumno: \n");
    scanf("%ld",&al.dni);
    printf("Ingrese apellido y nombre del alumno: \n");
    fflush(stdin);
    fgets(al.NyA,40,stdin);
    printf("Ingrese fecha de nacimiento del alumno: \n");
    fflush(stdin);
    ingresarFecha(&(al.fNacimiento));
    printf("\nIngrese sexo del alumno: \n");
    fflush(stdin);
    scanf("%c",&al.sexo);
    printf("Ingrese fecha de ingreso del alumno: \n");;
    ingresarFecha(&(al.fIngreso));
    printf("Ingrese carrera del alumno: \n");
    fflush(stdin);
    fgets(al.carrera,4,stdin);
    printf("Ingrese cantidad de materias aprobadas del alumno: \n");
    scanf("%d",&al.cant_mat_aprobadas);
    al.estado = 'R';
    validarAlumno(&al,&hoy,errores);
    return 1;
}
int* validarAlumno(t_alumno* a, t_fecha* hoy, int* errores)
{
    char carreras[9][4] = {{"INF"}, {"ELE"}, {"IND"}, {"ECO"}, {"DER"}, {"ADM"}, {"MED"}, {"EDF"}, {"FIL"}};
    int i = 0;
    if(!(a->dni >= 10000 && a->dni <= 100000000))
        *errores=1;
    errores++;
    normalizarNyAp(a->NyA);
    if(!es_fecha_valida(&a->fNacimiento) || a->fNacimiento.anio > (a->fIngreso.anio-10)) //la biblioteca de fechas.h no cuenta dias? para calcular dif de 10 años
        *errores=1;
    errores++;
    if(a->sexo != 'F' && a->sexo != 'M')
        *errores=1;
    errores++;
    if(!es_fecha_valida(&a->fIngreso) || cmpfecha(&a->fIngreso,hoy) > 0 || cmpfecha(&a->fIngreso,&a->fNacimiento) < 0)
        *errores=1;
    errores++;
    for(i=0;i<9 && i!=-1;i++) //medio horrible, arreglar.
    {
        if(strstr(a->carrera,carreras[i]))
            i=-2;
    }
    if(i!=-1)
        *errores=1;
    errores++;
    if(a->cant_mat_aprobadas < 0)
        *errores=1;
    errores-=5;
    return errores;
}
