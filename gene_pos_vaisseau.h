//Inclusion des bibliothèques utiles au programme
#include <stdio.h>
#include <stdlib.h>
//#include <sys/random.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


extern int pos_vaisseau;
extern char vaisseau;
//Définition des variables propres au fichier
//extern char ligne[105];

//Définition des fonctions utiles au programme
void init_vaisseau();
int vaisseau_bouge();
void reset_terminal_mode();
void stdin_set(int);
void set_conio_terminal_mode();
int kbhit();
int getch();
void disable_echo();
