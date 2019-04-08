#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Bibliotecas/CItemMenu.h"


int main()
{
    CItemMenu* root = crearMenuRaiz();

    /*Agregar menues desde aca*/

    /*Cierre de region de menus*/

    StartApp(root);

    deleteMenu(root);

    return 0;
}
