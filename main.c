#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Bibliotecas/Fecha.h"
#include "Bibliotecas/CItemMenu.h"
#include "Tests/Tests.h"

int main()
{

    //Remplazar por pedido al usuario
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    setHoy(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    CItemMenu* root = crearMenuRaiz();

    //Agregar menues desde aca
    addSubmenu(root, "1", "Alumnos", NULL);
        addSubmenu(root, "1.1", "Alumnos-Alta", NULL);
        addSubmenu(root, "1.2", "Alumnos-Baja", NULL);
        addSubmenu(root, "1.3", "Alumnos-Modificacion", NULL);



    addSubmenu(root, "9", "Tests", NULL);
        addSubmenu(root, "9.1", "Test de fechas", &EjecutarTestsFechas);
        addSubmenu(root, "9.2", "Test de cadenas", &EjecutarTestsCadenas);
    //Cierre de region de menus

    StartApp(root);
    deleteMenu(root);

    return 0;
}
