#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/CItemMenu.h"
#include "Tests/Tests.h"

int main()
{
    CItemMenu* root = crearMenuRaiz();

    /*Agregar menues desde aca*/
    addSubmenu(root, "9", "Tests", NULL);
        addSubmenu(root, "9.1", "Test de fechas", &EjecutarTestsFechas);
        addSubmenu(root, "9.2", "Test de cadenas", &EjecutarTestsCadenas);
    /*Cierre de region de menus*/

    StartApp(root);
    deleteMenu(root);

    return 0;
}
