#include "Tipos.h"

/*    unsigned long dni;
    char nomyap[100];
    float saldo;
    char sexo;
    char estado;*/

void mostrarCliente(void* params){
    printf("DNI: %ld, Nombre: %s, saldo: %f, s: %c, estado: %c\n",
           ((t_cliente*)params)->dni,
            ((t_cliente*)params)->nomyap,
           ((t_cliente*)params)->saldo,
           ((t_cliente*)params)->sexo,
           ((t_cliente*)params)->estado);
}


void mostrarNovedad(void* params){
    printf("DNI: %ld, Nombre: %s, saldo: %f, s: %c, estado: %c, act: %d\n",
           ((t_novedad*)params)->dni,
            ((t_novedad*)params)->nomyap,
           ((t_novedad*)params)->saldo,
           ((t_novedad*)params)->sexo,
           ((t_novedad*)params)->estado,
           ((t_novedad*)params)->abm_action);
}
