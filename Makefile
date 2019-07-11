all : prog


main.o : main.c regle.h gene_tunnel.h gene_pos_vaisseau.h vue.h
	gcc -c main.c -Wall -Werror -g  -o main.o

regle.o : regle.c regle.h
	gcc -c regle.c -Wall -Werror -g  -o regle.o

gene_tunnel.o : gene_tunnel.c gene_tunnel.h
	gcc -c gene_tunnel.c -Wall -Werror -g  -o gene_tunnel.o
	
gene_pos_vaisseau.o : gene_pos_vaisseau.c gene_pos_vaisseau.h
	gcc -c gene_pos_vaisseau.c -Wall -Werror -g -o gene_pos_vaisseau.o
	
vue.o : vue.c vue.h
	gcc -c vue.c -Wall -Werror -g -o vue.o

prog : main.o regle.o gene_tunnel.o gene_pos_vaisseau.o vue.o
	gcc main.o regle.o gene_tunnel.o gene_pos_vaisseau.o vue.o -o rtype

clean : 
		rm -f *.o
		rm -f prog
