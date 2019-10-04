#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "Fecha.h"
#include "mstring.h"
typedef struct {
    long int dni;
    char NyA[40];
    t_fecha fNacimiento;
    char sexo;
    t_fecha fIngreso;
    char carrera[4];
    int cant_mat_aprobadas;
    char estado;
}t_alumno;

int ingresarAlumno();
int* validarAlumno(t_alumno* al, t_fecha* f, int* errores);

#endif // ALUMNO_H_INCLUDED
