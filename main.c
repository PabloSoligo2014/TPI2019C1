#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Bibliotecas/CItemMenu.h"
#include "Tests/Tests.h"

int main()
{
    CItemMenu* root = crearMenuRaiz();

    /*Agregar menues desde aca*/



    addSubmenu(root, "9", "Tests", NULL);
        addSubmenu(root, "9.1", "Test de fechas", &EjecutarTests);
    /*Cierre de region de menus*/

    StartApp(root);

    deleteMenu(root);

    return 0;
}
