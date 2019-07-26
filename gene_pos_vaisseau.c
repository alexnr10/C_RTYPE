#include "gene_pos_vaisseau.h"
#include "gene_tunnel.h"
int pos_vaisseau;
char vaisseau;
int verif;

void init_vaisseau(){
	modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] =  vaisseau;
}

struct termios orig_termios;

void reset_terminal_mode()
{
	tcsetattr(0, TCSANOW, &orig_termios);
}

void stdin_set(int cmd)
{
	struct termios t;
	tcgetattr(1,&t);
	switch (cmd) {
	case 1:
		t.c_lflag &= ~ICANON;
		break;
	default:
		t.c_lflag |= ICANON;
		break;
	}
	tcsetattr(1,0,&t);
}

void disable_echo(){
	struct termios t;
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
}

void set_conio_terminal_mode()
{
	struct termios new_termios;

	/* take two copies - one for now, one for later */
	tcgetattr(0, &orig_termios);
	memcpy(&new_termios, &orig_termios, sizeof(new_termios));

	/* register cleanup handler, and set the new terminal mode */
	atexit(reset_terminal_mode);
	cfmakeraw(&new_termios);
	tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}

int getch(char *c)
{
	int r;
	if ((r = read(0, (unsigned char*)c, sizeof(char))) < 0) {
		return r;
	} else {
		return r;
	}
}

int vaisseau_bouge(){
	int input[2];
	char frappe = '\0';
	if(kbhit())
	{
		if(getch(&frappe) > 0)
		{
			input[0] = getchar();
			input[1] = getchar();
			if(input[1] == 68){
				if((modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau -1] == '/') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau -1] == '|') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau -1] == '\\') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau -1] == 'o')){
					verif = 0;
				}
				pos_vaisseau--;
				if(pos_vaisseau <= 0){
					pos_vaisseau = 1;
				}
				if(modele.indice_pos_vaisseau >= NB_LIGNE_DECOR){
					modele.indice_pos_vaisseau = 0;
				}
				modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
				if((pos_vaisseau != sizeof(modele.tab_decor[0].data)) && (modele.indice_pos_vaisseau != 0)){
					modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau+1] = ' ';
				}
				modele.vaisseau_pos_evenement = 1;
			}
		else if(input[1] == 67){
			if((modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau + 1] == '/') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau + 1] == '|') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau + 1] == '\\') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau + 1] == 'o')){
				verif = 0;
			}
			pos_vaisseau++;
			if(pos_vaisseau >= sizeof(modele.tab_decor[0].data) ){
				pos_vaisseau = sizeof(modele.tab_decor[0].data) - 1;
			}
			if(modele.indice_pos_vaisseau >= NB_LIGNE_DECOR){
				modele.indice_pos_vaisseau = 0;
			}
			modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
			if((0 != pos_vaisseau) && (modele.indice_pos_vaisseau != 0)){
				modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau-1] = ' ';
			}
			modele.vaisseau_pos_evenement = 1;
		}
		else if(input[1] == 66){
			if((modele.tab_decor[modele.indice_pos_vaisseau + 2].data[pos_vaisseau] == '/') || (modele.tab_decor[modele.indice_pos_vaisseau + 2].data[pos_vaisseau] == '|') || (modele.tab_decor[modele.indice_pos_vaisseau + 2].data[pos_vaisseau] == '\\') || (modele.tab_decor[modele.indice_pos_vaisseau + 2].data[pos_vaisseau] == 'o')){
				verif = 0;
			}
			modele.indice_pos_vaisseau++;
			if(modele.indice_pos_vaisseau >= NB_LIGNE_DECOR){
				modele.indice_pos_vaisseau = 0;
			}
			modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
			if((0 != pos_vaisseau) && (modele.indice_pos_vaisseau != 0)){
				modele.tab_decor[modele.indice_pos_vaisseau-1].data[pos_vaisseau] = ' ';
			}
			modele.vaisseau_pos_evenement = 1;
		}
		else if(input[1] == 65){
			if((modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] == '/') || (modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] == '|') || (modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] == '\\') || (modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] == 'o')){
				verif = 0;
			}
			modele.indice_pos_vaisseau--;
			if(modele.indice_pos_vaisseau <= 0){
				modele.indice_pos_vaisseau = 1;
			}
			modele.tab_decor[modele.indice_pos_vaisseau].data[pos_vaisseau] = vaisseau;
			if((0 != pos_vaisseau) && (modele.indice_pos_vaisseau != 0)){
				modele.tab_decor[modele.indice_pos_vaisseau+1].data[pos_vaisseau] = ' ';
			}
			modele.vaisseau_pos_evenement = 1;
		}
	}
}
else{
	if((modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau] == '/') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau] == '|') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau] == '\\') || (modele.tab_decor[modele.indice_pos_vaisseau + 1].data[pos_vaisseau] == 'o')){
		verif = 0;
	}
}
return 0;
}


