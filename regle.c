#include "regle.h"

char ligne[105];
int longueur_tab_gauche_paroi_gauche;
int longueur_tab_droite_paroi_droite;
int longueur_tab_gauche_paroi_gauche_precedent;
int longueur_tab_droite_paroi_droite_precedent;
int longueur_boyau;

int verifier_char_boyau()
{
    int verif = 1;
    if (longueur_tab_droite_paroi_droite < 1)
    {
        //printf("non1");
        verif = 0;
    }
    else if (longueur_tab_gauche_paroi_gauche < 1)
    {
        //printf("non2");
        verif = 0;
    }
    else if (longueur_boyau < TAILLE_MIN_BOYAU || longueur_boyau > TAILLE_MAX_BOYAU)
    {
        //printf("non3");
        verif = 0;
    }
    else if (longueur_boyau + longueur_tab_gauche_paroi_gauche > sizeof(ligne) - 7)
    {
	//printf("non4");
        verif = 0;
    }

    if(!verif){
    	longueur_tab_gauche_paroi_gauche = longueur_tab_gauche_paroi_gauche_precedent;
    	longueur_tab_droite_paroi_droite = longueur_tab_droite_paroi_droite_precedent;
    }
    return verif;
}

//int perdu(){
//	int verif = 1;
//	modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
//	if((modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau + 1] == '#') || (modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau - 1] == '#')){
//		verif = 0;
//	}
//	if((modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau] == asteroide) && (m)
//	return verif;
//}
