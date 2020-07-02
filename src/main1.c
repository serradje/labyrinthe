#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "ensemble.h"
#include "matrice.h"
#include "labyrinthe.h"
#include "graph.h"

#define DEF_L 300
#define DEF_H 200

int affichage = 0;
int affiche_case= 0;
int PIXEL = 3;

char *usage_string = "Usage genlab : ./genlab [-v] [-d] [-l <largeur>] [-h <hauteur>] [-p <taille pixel>] <fichier>\n" ;


void usage (char *argv)
{
    fprintf (stderr, usage_string, argv[0]) ;
    exit (1) ;
}

int main(int argc, char ** argv)
{
	int l=DEF_L,h=DEF_H;
    int active_pixel=0;

		int opt;
	srand(time(NULL));
   
	   while ((opt = getopt (argc, argv, "vdl:h:p:")) != -1)
		{
			switch (opt)
				{

					case 'v' :
						 affichage=1;
					break ;					
					case 'd' :
					{
					  affiche_case=1;
					  affichage=1;
					
					break;
					}
					case'l':
					{
					   l=atoi(optarg);
					   	if(l>1000) 
						l=1000;
				
					break ;
					}				
					case 'h' : 
					{
					   h=atoi(optarg);
					   	if(h>800)
						h=800;
		
					}
					break ;
						
					case 'p' : 
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
			
			if(active_pixel==0)
				 PIXEL=tailleFenetre(h,l);
				 matrice m=NULL;
				 m=MatAlloc(h,l);
				 
				 if (m == NULL)
			{
				return 1;
			}
			m = GenLab(m);
				if ((MatSauve(m,argv[argc-1])) == 0)
					return 1;
					
					return 0;

}

