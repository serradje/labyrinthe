#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "matrice.h"
#include "chemin.h"

int affiche = 0; 
int PIXEL = 3;
char *move;
void usage (const char *prog)
{
    fprintf (stderr, "usage: %s [-v][-d][-c CHEMIN] [fichier]\n"
    			"\t-v   : affichage de labyrinthe\n"
    			"\t-d   : affichage des cases constructibles\n"
    			"\t-c   : Choix de Chemin: h =heuristique, a = aleatoire d = dijkstra * = Astar\n"
    		, prog) ;
}

int main(int argc, char ** argv)
{
	
		int opt;
	srand(time(NULL));

    int active_pixel=0;
    matrice m;
	   while ((opt = getopt (argc, argv, "v:c:p:")) != -1)
		{
			switch (opt)
				{

					case 'v' :
						affiche=1;
					
					break ;
					case 'c' :
					move = optarg;
					break;
					case'p':
					{
					PIXEL=atoi(optarg);
					active_pixel=1;
					
					break ;
					}
					default :
					usage (argv[0]) ;
					exit (1) ;
					break ;
				}
				
		}
		
		
					   
			 /*
			 * Analyse des arguments
			 */
			 
			if (argc - optind == 0)
			{
				usage (argv[0]) ;
				exit (1) ;
			}
			
			m=MatLit(argv[argc-1]);
			if(active_pixel==0)
			 PIXEL=tailleFenetre(m->h,m->l);
			 
			if(move[0]=='a' || move[0]=='h')
			mat_Alea_Heuri(m);
			else
			if(move[0]=='d')
			mat_Dij(m);
			else
			mat_Astar(m);

		MatFree(m);
	
	return 0;
}
