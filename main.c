#include "gene_tunnel.h"
#include "regle.h"
#include "gene_pos_vaisseau.h"
#include "vue.h"

modele_rtype_t modele;
ligne_t ligne;
int main(void)
{
    // 5: retirer: | + | + | + | + \0
	stdin_set(1);
	disable_echo();
    int total_nb_espace = sizeof(ligne.data) - 5;
	vaisseau = '*';
	asteroide = 'o';
    pos_vaisseau = sizeof(ligne.data) / 2;
    longueur_tab_gauche_paroi_gauche = (5 * total_nb_espace) / 12;
    longueur_tab_droite_paroi_droite = (5 * total_nb_espace) / 12;
    longueur_boyau = total_nb_espace / 6;
    modele.idx_debut_tab_decor = 0;
    modele.indice_pos_vaisseau = 1;
    modele.vaisseau_pos_evenement = 1;
    int compteur_temps=0;
    int compteur_temps_ast = 0;
//    init_tableau();
    vue_init();
    do
    {
    	if((compteur_temps % 100) == 0)
    	{
    		//printf("COUCOU3");
    		//sleep(1);
    		creer_ligne();
    		modif_decor();
    		vaisseau_bouge();
    		//printf("COUCOU4");
    	}
    	else if((compteur_temps_ast % 10) == 0){
    		gene_asteroides();
    		//mouvement_asteroides();
    		vue_update();
    	}
    	//printf("update");
    	vue_update();
//        init_ligne();
//        init_vaisseau();
//        printf("%s\n", ligne);
    	compteur_temps ++;
    	compteur_temps_ast ++;
        usleep(1000);
//        int TMP_droit = longueur_tab_droite_paroi_droite;
//        int TMP_gauche = longueur_tab_gauche_paroi_gauche;
//        int joueur = pos_vaisseau;
//        int is_ok = 0;
//        int is_ok1 = 1;
//        do
//        {
            
//            vaisseau_bouge();
//            creer_ligne();
//            is_ok = verifier_char_boyau();
//            is_ok1 = perdu();
//            if(is_ok == 0 && is_ok1 == 0)
//            {
//                longueur_tab_droite_paroi_droite = TMP_droit;
//                longueur_tab_gauche_paroi_gauche = TMP_gauche;
//                pos_vaisseau = joueur;
//            }
//        }
//        while (is_ok == 0 && is_ok1 == 0);
    } while (1);
    printf("¡¡¡PERDIDO!!! PUEDES HACERLO DE NUEVO ;)");
    return 0;
}
