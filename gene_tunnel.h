//Inclusion des bibliothèques utiles au programme
#include <stdio.h>
#include <stdlib.h>
//#include <sys/random.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

//Définition des étiquettes 
#define TAILLE_MAX_BOYAU 40
#define TAILLE_MIN_BOYAU 8
#define PI 3.14159265

typedef struct ligne_s{
	char data[105];
}ligne_t;
//Définition des variables propres au fichier
typedef struct modele_rtype_s{
	int idx_debut_tab_decor;
	int indice_pos_vaisseau;
	struct ligne_s tab_decor[34];
	int decor_a_change;
	int vaisseau_pos_evenement;
	//int asteroide_evenement;
	int init;
}modele_rtype_t;

#define NB_LIGNE_DECOR (sizeof(modele.tab_decor) / sizeof(modele.tab_decor[0].data))
extern modele_rtype_t modele;
extern ligne_t ligne;
extern int longueur_tab_gauche_paroi_gauche;
extern int longueur_tab_droite_paroi_droite;
extern int longueur_tab_gauche_paroi_gauche_precedent;
extern int longueur_tab_droite_paroi_droite_precedent;
extern int longueur_boyau;
extern int indice_ast;
//extern int pos_ast;
extern char asteroide;

//Définition des fonctions utiles au programme 

int creer_char_boyau();
int creer_ligne();
int modif_decor(/*longueur_tab_gauche_paroi_gauche, char_boyau_gauche, longueur_tab_gauche_paroi_droite, char_boyau_droit*/);
int creer_nvlle_dimension(/*char_boyau_gauche, char_boyau_droit*/);
int init_tableau();
int aleatoire(int);
int gene_asteroides();
int mouvement_asteroides();
