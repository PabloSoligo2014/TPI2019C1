#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "CItemMenu.h"
#include "mstring.h"

CItemMenu* crearMenuRaiz(){
    int i = 0;

    CItemMenu* root = malloc(sizeof(CItemMenu));
    strcpy(root->code, "0");
    strcpy(root->desc, "root");
    root->action = NULL;

    for(i=0;i<MAX_SUBMENU;i++){
        root->submenu[i] = NULL;
    }

    return root;
}

int addSubmenu(CItemMenu* root, char* code, char* desc, t_appAction act){
    //mstrpartir
    int v[MAX_DEEP_SUBMENU];
    int cant = mstrpartir(code, v);
    int i = 0;
    //int step = 0;
    CItemMenu* menuact = root;


    for(i=0;i<cant-1;i++){
        menuact = (menuact->submenu[v[i]-1]);
    }


    CItemMenu* nue = malloc(sizeof(CItemMenu));
    //Pongo todos los submenus en NULL
    int j;
    for(j=0;j<MAX_SUBMENU;j++){
        nue->submenu[j] = NULL;
    }

    strcpy(nue->code, code);
    strcpy(nue->desc, desc);
    nue->action = act;
    (menuact->submenu[v[i]-1]) = nue;
    return 1;

}

int showMenu(CItemMenu* root){
    //Siempre se muestran los submenues del pasado como parametro
    for(int i=0; i<MAX_SUBMENU;i++){
        if(root->submenu[i]!=NULL){
            printf("%d.%s\n",i+1, root->submenu[i]->desc);
        }
    }
    return 1;
}

char selectOption(CItemMenu* root){
    int ops = 0;
    printf("Seleccione un opcion, q para salir: \n");
    char op;
    for(int i=0; i<MAX_SUBMENU;i++){
        if(root->submenu[i]!=NULL){
            printf("%d.%s\n",i+1, root->submenu[i]->desc);
            ops++;
        }
    }

    if(ops==0){
        puts("Funcion no implementada/No existen opciones de menu...");
    }
    printf("%s.%s\n","ESC", "Para volver...");
    fflush(stdin);
    op = _getch();
    //scanf("%s",sel);
    return op;


}

void StartApp(CItemMenu* root){
    char op;
    int iop;
    t_appAction act;

    op = selectOption(root);
    while(op!=27){
        iop = CHARTOINT(op)-1;
        if (root->submenu[iop]->action!=NULL){
            act = root->submenu[iop]->action;
            act(NULL);
            puts("\nPresione cualquier tecla para continuar...");
            _getch();

        }else{
            //Verificar que el submenu no sea null
            StartApp(root->submenu[iop]);
        }
        op = selectOption(root);
    }
    return;


}

void deleteMenu(CItemMenu* root){
    int i = 0;
    for(i=0;i<MAX_SUBMENU;i++){
        if(root->submenu[i]!=NULL){
            deleteMenu(root->submenu[i]);
        }

    }
    free(root);
}
