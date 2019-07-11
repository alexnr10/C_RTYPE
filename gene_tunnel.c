#include "gene_tunnel.h"
#include "gene_pos_vaisseau.h"
#include "regle.h"

int char_boyau_droit = '|';
int char_boyau_gauche = '|';
int char_boy_cnt=0;
int indice_ast;
//int pos_ast = longueur_tab_gauche_paroi_gauche + longueur_boyau / 2;
char vaisseau;
char asteroide;

int creer_char_boyau()
{
	/* // Générer des formes de boyau pour tester
    if (char_boy_cnt < 5)
    {
        char_boyau_droit = '/';
        char_boyau_gauche = '\\';
    }
    else if (char_boy_cnt < 10)
    {
        char_boyau_droit = '|';
        char_boyau_gauche = '|';
    }
    else if (char_boy_cnt < 15)
    {
        char_boyau_droit = '\\';
        char_boyau_gauche = '/';
    }
    char_boy_cnt++;
    if (char_boy_cnt == 15) 
    {
        char_boy_cnt = 0;
    }
	 */

	// Générer un boyau aléatoire
	char boyau_char[]={'/','|','\\'};
	unsigned char rnd[2];
	//getrandom(rnd, sizeof(rnd), 0);
	rnd[0] = rand();
	rnd[1] = rand();
	rnd[0] %= 3;
	rnd[1] %= 3;
	char_boyau_droit = boyau_char[rnd[0]];
	char_boyau_gauche = boyau_char[rnd[1]];

	return 0;
}

int creer_nvlle_dimension(/*char_boyau_gauche, char_boyau_droit*/)
{
	longueur_tab_droite_paroi_droite_precedent = longueur_tab_droite_paroi_droite;
	longueur_tab_gauche_paroi_gauche_precedent = longueur_tab_gauche_paroi_gauche;
	if (char_boyau_droit == '\\')
	{
		longueur_tab_droite_paroi_droite--;
		longueur_boyau++;
	}
	else if (char_boyau_droit == '/')
	{
		longueur_tab_droite_paroi_droite++;
		longueur_boyau--;
	}
	if (char_boyau_gauche == '\\')
	{
		longueur_tab_gauche_paroi_gauche++;
		longueur_boyau--;
	}
	else if (char_boyau_gauche == '/')
	{
		longueur_tab_gauche_paroi_gauche--;
		longueur_boyau++;
	}
	return 0;
}

int init_tableau(){
	int index;
	int k;
	struct ligne_s ligne;
	modele.tab_decor[0].data[0] = '|';
	for(k = 0; k < sizeof(modele.tab_decor) / sizeof(modele.tab_decor[0].data); k++){
		creer_char_boyau();
		creer_nvlle_dimension();
		for (index = 1; index <= longueur_tab_gauche_paroi_gauche; index++)
		{
			modele.tab_decor[k].data[index] = '#';
		}
		modele.tab_decor[k].data[longueur_tab_gauche_paroi_gauche + 1] = char_boyau_gauche;
		for (index = longueur_tab_gauche_paroi_gauche + 2; index <= longueur_tab_gauche_paroi_gauche + longueur_boyau + 1; index++)
		{
			modele.tab_decor[k].data[index] = ' ';
		}
		modele.tab_decor[k].data[longueur_tab_gauche_paroi_gauche + longueur_boyau + 2] = char_boyau_droit;
		for (index = longueur_tab_gauche_paroi_gauche + longueur_boyau + 3; index <= sizeof(ligne.data) - 3; index ++)
		{
			modele.tab_decor[k].data[index] = '#';
		}
		modele.tab_decor[k].data[sizeof(modele.tab_decor[k].data) - 2] = '|';
		modele.tab_decor[k].data[sizeof(modele.tab_decor[k].data) - 1] = '\0';
	}
	modele.init = 1;
	return 0;
}

int creer_ligne(/*longueur_tab_gauche_paroi_gauche, char_boyau_gauche, longueur_tab_gauche_paroi_droite, char_boyau_droit*/)
{
#if 0
	int index;
	//while(1)
	{
		creer_char_boyau();
		creer_nvlle_dimension();
		ligne[0] = '|';
		for (index = 1; index <= longueur_tab_gauche_paroi_gauche; index++)
		{
			ligne[index] = '#';
		}
		ligne[longueur_tab_gauche_paroi_gauche + 1] = char_boyau_gauche;
		for (index = longueur_tab_gauche_paroi_gauche + 2; index <= longueur_tab_gauche_paroi_gauche + longueur_boyau + 1; index++)
		{
			ligne[index] = ' ';
		}
		ligne[longueur_tab_gauche_paroi_gauche + longueur_boyau + 2] = char_boyau_droit;
		for (index = longueur_tab_gauche_paroi_gauche + longueur_boyau + 3; index <= sizeof(ligne) - 3; index ++)
		{
			ligne[index] = '#';
		}
		ligne[sizeof(ligne) - 2] = '|';
		ligne[sizeof(ligne) - 1] = '\0';
	}
#endif
	return 0;
}

int modif_decor(/*longueur_tab_gauche_paroi_gauche, char_boyau_gauche, longueur_tab_gauche_paroi_droite, char_boyau_droit*/)
{
	int index;
	struct ligne_s ligne;
	//	struct modele_rtype_s modele;
	do
	{
		creer_char_boyau();
		creer_nvlle_dimension();
	} while(!verifier_char_boyau());

	ligne.data[0] = '|';
	for (index = 1; index <= longueur_tab_gauche_paroi_gauche; index++)
	{
		ligne.data[index] = '#';
	}
	ligne.data[longueur_tab_gauche_paroi_gauche + 1] = char_boyau_gauche;
	for (index = longueur_tab_gauche_paroi_gauche + 2;
		index <= longueur_tab_gauche_paroi_gauche + longueur_boyau + 1;
		index++)
	{
		ligne.data[index] = ' ';
	}
	ligne.data[longueur_tab_gauche_paroi_gauche + longueur_boyau + 2] = char_boyau_droit;
	for (index = longueur_tab_gauche_paroi_gauche + longueur_boyau + 3; index <= sizeof(ligne.data) - 3; index ++)
	{
		ligne.data[index] = '#';
	}
	ligne.data[sizeof(ligne.data) - 2] = '|';
	ligne.data[sizeof(ligne.data) - 1] = '\0';
	modele.indice_pos_vaisseau++;
	if(modele.indice_pos_vaisseau >= NB_LIGNE_DECOR){
		modele.indice_pos_vaisseau = 0;
	}
	modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
	if(modele.indice_pos_vaisseau != 0){
		modele.tab_decor[modele.indice_pos_vaisseau - 1].data[pos_vaisseau] = ' ';
	}else{
		modele.tab_decor[NB_LIGNE_DECOR-1].data[pos_vaisseau] = ' ';
	}
	memcpy(&modele.tab_decor[modele.idx_debut_tab_decor],
			ligne.data, sizeof(struct ligne_s));
	modele.idx_debut_tab_decor++;
	modele.idx_debut_tab_decor %= sizeof(modele.tab_decor) / sizeof(ligne_t) ;
	modele.decor_a_change = 1;
	return 0;
}

int aleatoire(int x){
	int r;
	time_t t;

	/* Intializes random number generator */
	srand((unsigned) time(&t));
	r = rand() % x;
	return r;
}

int gene_asteroides(){
	//	int r;
	//	int ast;
	//	int i;
	//	int j;
	//	if(pos_vaisseau % 2 == 0){
	//		return 0;
	//	}
	//	else{
	//		r = aleatoire(2);
	//		if(r == 0){
	//			return 0;
	//		}
	//		else{
	//			ast = longueur_tab_gauche_paroi_gauche + aleatoire(longueur_boyau + 1);
	//			for(i = 1; i < NB_LIGNE_DECOR / 2; i++){
	//				//ast += i;
	//				modele.tab_decor[NB_LIGNE_DECOR - i-1].data[ast+i] = asteroide;
	//				modele.tab_decor[NB_LIGNE_DECOR - i].data[ast+i-1] = ' ';
	//			}
	//			for(j = NB_LIGNE_DECOR / 2; j < NB_LIGNE_DECOR; j++){
	//				modele.tab_decor[NB_LIGNE_DECOR - j - 1].data[ast-j] = asteroide;
	//				modele.tab_decor[NB_LIGNE_DECOR - j].data[ast-j+1] = ' ';
	//			}
	//			return 0;
	//		}
	//	}
	int pos_ast;
	time_t t;
	srand((unsigned) time(&t));
	if((modele.indice_pos_vaisseau == 0) || (modele.indice_pos_vaisseau == 5) || (modele.indice_pos_vaisseau == 10) || (modele.indice_pos_vaisseau == 15) || (modele.indice_pos_vaisseau == 20) || (modele.indice_pos_vaisseau == 25) || (modele.indice_pos_vaisseau == 30)){
		indice_ast = rand() % NB_LIGNE_DECOR;
		pos_ast = rand() % longueur_boyau;
		if(modele.tab_decor[indice_ast].data[longueur_tab_gauche_paroi_gauche + pos_ast] != ' '){
		}
		else{
			modele.tab_decor[indice_ast].data[longueur_tab_gauche_paroi_gauche + pos_ast] = asteroide;
			modele.decor_a_change = 1;
		}
	}
	return 0;
}

//int mouvement_asteroides(){
//	if(asteroide == modele.tab_decor[indice_ast].data[pos_ast]){
//		(asteroide = modele.tab_decor[indice_ast - 1].data[pos_ast +1]) || (asteroide = modele.tab_decor[indice_ast - 1].data[pos_ast -1]);
//		modele.tab_decor[indice_ast].data[pos_ast] = ' ';
//		modele.decor_a_change = 1;
//		return 0;
//	}
//	else{
//		return 0;
//	}
//}

/*void print_ligne(){
	int i;
	for(i = decor_data.idx_debut_tab_decor; i < sizeof(decor_data.tab_decor); i++){
		printf("%c\n", decor_data.tab_decor[i]);
	}
	for(i = 0; i < decor_data.idx_debut_tab_decor; i++){
		printf("%c\n", decor_data.tab_decor[i]);
	}
}

void add_ligne(){
	decor_data.idx_debut_tab_decor++;
	decor.data.idx_debut_tab_decor %= sizeof(decor_data.tab_decor);
	memcpy(&decor_data.tab_decor[decor_data.idx_debut_tab_decor], 
    		ligne.data, sizeof(struct ligne_s));
}*/
