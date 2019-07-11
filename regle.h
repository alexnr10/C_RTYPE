//Inclusion des bibliothèques utiles au programme
#include <stdio.h>
#include <stdlib.h>
//#include <sys/random.h>
#include <unistd.h>
#include "gene_pos_vaisseau.h"

//Définition des étiquettes
#define TAILLE_MAX_BOYAU 40
#define TAILLE_MIN_BOYAU 8

//Définition des variables propres au fichier
extern int longueur_tab_gauche_paroi_gauche;
extern int longueur_tab_droite_paroi_droite;
extern int longueur_boyau;
extern int pos_vaisseau; 

//Définition des fonctions utiles au programme
int verifier_char_boyau();
//int perdu();
