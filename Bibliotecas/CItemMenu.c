#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Se quita conio para hacer multiplataforma la aplicacion
//#include <conio.h>
#include "xplatform/XPlatform.h"
#include "CItemMenu.h"
#include "mstring.h"
#define ESC 27

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void clearScreen()
{
  //Esto no es multiplataforma!
  //system("@cls||clear");

  xplt_clrscr();
}

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
    int i;
    for(i=0; i<MAX_SUBMENU;i++){
        if(root->submenu[i]!=NULL){
            printf("%d.%s\n",i+1, root->submenu[i]->desc);
        }
    }
    return 1;
}

char selectOption(CItemMenu* root){
    int ops = 0;
    char op;
    //puts("------------------------------------------------");
    printf("Seleccione un opcion:\n");
    puts("-------------------------");

    //char op;
    int i;
    for(i=0; i<MAX_SUBMENU;i++){
        if(root->submenu[i]!=NULL){
            printf("%d.%s\n",i+1, root->submenu[i]->desc);
            ops++;
        }
    }

    if(ops==0){
        puts("Funcion no implementada/No existen opciones de menu...");
    }
    puts("-------------------------");
    printf("%s %s","ESCAPE (Esc)", ", para volver...\n-->");
    //clean_stdin();
    op = xplt_getch();
    //scanf("%d", &iop);


    //La version monoplataforma puede usar conio+getch y no es necesario el "enter" despues de seleccionar
    //menu, como contra solo va a 0/1 a 9
    //op = _getch();
    //scanf("%s",sel);
    return op;


}

void StartApp(CItemMenu* root){
    //char op;
    char op;

    t_appAction act;
    clearScreen();
    op = selectOption(root);
    while(op!=ESC){
        //iop = CHARTOINT(op)-1;
        if (root->submenu[(op-48)-1]->action!=NULL){
            //Recomendacion, en aplicaciones reales (No academicas) no asumir ASCII.
            act = root->submenu[(op-48)-1]->action;
            clearScreen();
            act(NULL);

            puts("\nPresione cualquier tecla para continuar...");
            //clean_stdin();
            getch();

        }else{
            //Verificar que el submenu no sea null
            StartApp(root->submenu[(op-48)-1]);
        }
        clearScreen();
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
