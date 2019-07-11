/*
 * vue.c
 *
 *  Created on: 2 juil. 2019
 *      Author: ensea
 */
#include "vue.h"
#include "gene_tunnel.h"
#include "gene_pos_vaisseau.h"

int pos_vaisseau;
char vaisseau;
int indice_ast;

void vue_init(void){
	modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
	printf("%c\n", vaisseau);
}

void vue_update(void)
{
	//printf("%d", modele.decor_a_change);
	if(modele.decor_a_change == 1){
		int i;
		int j;
		system("clear");
		//printf("COUCOU\n");
		printf("%c\n", modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau]);
		printf("%c\n", modele.tab_decor[indice_ast].data[longueur_tab_gauche_paroi_gauche + longueur_boyau / 2]);
		for(i = modele.idx_debut_tab_decor; i < NB_LIGNE_DECOR; i++){
			printf("%s\n", modele.tab_decor[i].data);
		}
		for(j = 0; j < modele.idx_debut_tab_decor; j++){
			printf("%s\n", modele.tab_decor[j].data);
		}
		modele.decor_a_change = 0;
	}
	else if(modele.vaisseau_pos_evenement == 1){
		printf("%c\n", modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau]);
		modele.vaisseau_pos_evenement = 0;
		modele.decor_a_change = 1;
		vue_update();
	}
}

