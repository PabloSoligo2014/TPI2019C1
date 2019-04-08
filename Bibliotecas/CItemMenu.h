#ifndef CITEMMENU_H_INCLUDED
#define CITEMMENU_H_INCLUDED

#include "Tipos.h"
#define MAX_SUBMENU 9
#define MAX_DEEP_SUBMENU 5
#define CHARTOINT(X) (X-48)

typedef struct sItemMenu{
    char code[10];
    char desc[24];
    t_appAction action;
    struct sItemMenu* submenu[MAX_SUBMENU];
}CItemMenu;


CItemMenu* crearMenuRaiz();
int addSubmenu(CItemMenu* root, char* code, char* desc, t_appAction act);
void deleteMenu(CItemMenu* root);
int showMenu(CItemMenu* root);


//int selectOption(CItemMenu* root, char* sel);
char selectOption(CItemMenu* root);
void StartApp(CItemMenu* root);


#endif // CITEMMENU_H_INCLUDED
