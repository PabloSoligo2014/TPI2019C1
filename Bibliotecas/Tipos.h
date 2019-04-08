#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


typedef enum abm_action{acAlta, acBaja, acModificacion}t_abmaction;

typedef struct {
    unsigned long dni;
    char nomyap[100];
    float saldo;
    char sexo;
    char estado;
}t_cliente;


typedef struct {
    unsigned long dni;
    char nomyap[100];
    float saldo;
    char sexo;
    char estado;
    t_abmaction abm_action;
}t_novedad;



typedef int (*t_appAction)(void* params);
typedef int (*t_action)(void* param);
typedef int (*t_cmp)(void* v1, void* v2);

void mostrarCliente(void* params);
void mostrarNovedad(void* params);
#endif // TIPOS_H_INCLUDED
