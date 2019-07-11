#include <stdio.h>
#include <stdlib.h>
//#include <sys/random.h>
#include <unistd.h>

#define TAILLE_MAX_BOYAU 40
#define TAILLE_MIN_BOYAU 8

int longueur_tab_gauche_paroi_gauche;
int longueur_tab_droite_paroi_droite;
int longueur_boyau;
int char_boyau_droit = '|';
int char_boyau_gauche = '|';
int char_boy_cnt=0;

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
    return verif;
}
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
int creer_ligne(/*longueur_tab_gauche_paroi_gauche, char_boyau_gauche, longueur_tab_gauche_paroi_droite, char_boyau_droit*/)
{
        int index;
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
    return 0;
}
int creer_nvlle_dimension(/*char_boyau_gauche, char_boyau_droit*/)
{
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
int main(void)
{
    // 5: retirer: | + | + | + | + \0
    int total_nb_espace = sizeof(ligne) - 5;
    longueur_tab_gauche_paroi_gauche = (5 * total_nb_espace) / 12;
    longueur_tab_droite_paroi_droite = (5 * total_nb_espace) / 12;
    longueur_boyau = total_nb_espace / 6;
    do
    {
        creer_ligne();
        printf("%s\n", ligne);
        usleep(100000);
        int TMP_droit = longueur_tab_droite_paroi_droite;
        int TMP_gauche = longueur_tab_gauche_paroi_gauche;
        int is_ok = 0;
        do
        {
            creer_char_boyau();
            creer_nvlle_dimension();
            is_ok = verifier_char_boyau();
            if(is_ok == 0)
            {
                longueur_tab_droite_paroi_droite = TMP_droit;
                longueur_tab_gauche_paroi_gauche = TMP_gauche;
            }
        }
        while (is_ok == 0);
    } while (1);
    
    return 0;
}

