#include <stdio.h>
#include <stdlib.h>
#include "chemin.h"
#include "ensemble.c"
#include "graph.c"
#include "sort.c"
#include <math.h>
#include <unistd.h>
#include <string.h>


void Astar(ens ferme,ens openlist,matrice m)
{ 
	long vert=0,rouge=0,jaune=0;
	  jaune=newcolor(1,1,0);
	  rouge=newcolor(1,0,0);
	  vert=newcolor(0,1,0);
	Couple fin={m->l-2,m->h-2};
	Couple p;
	p.x=1;p.y=1;p.g_cost=0.;p.distance=path(p.x,fin.x,p.y,fin.y);p.f_cost=p.g_cost+p.distance;
	EnsAjoute(openlist,p);
	while(!compareCouple(p,fin))
	{
		p=meilleur_case(openlist);
		ferme=EnsAjoute(ferme,p);
		DessineCouple(p,rouge);
		refresh();
		if(m->Case[p.x+1][p.y]==1 || EnsEstDans(ferme,construireCouple(p.x+1,p.y)));
		else
		if(m->Case[p.x+1][p.y]!=1 && !EnsEstDans(openlist,construireCouple(p.x+1,p.y)))
		{
			openlist=EnsAjoute(openlist,construireCouple(p.x+1,p.y));
			DessineCouple(construireCouple(p.x+1,p.y),vert);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].g_cost=p.g_cost+1.0;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].distance=path(p.x+1,fin.x,p.y,fin.x);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].f_cost=openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].g_cost + openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].distance;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].p.a=p.x;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].p.b=p.y;
		}
		else
		if(m->Case[p.x+1][p.y]!=1 && EnsEstDans(openlist,construireCouple(p.x+1,p.y)))
			{
					if(openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].g_cost<p.g_cost+1.0)
				{
				openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].g_cost=ferme->Case[EnsChercheCouple(ferme,p)].g_cost+1.0;
				openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].f_cost= (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].g_cost) + (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x+1,p.y))].distance);
				}
			}
		if(m->Case[p.x][p.y+1]==1 || EnsEstDans(ferme,construireCouple(p.x,p.y+1)));
		else
		if(m->Case[p.x][p.y+1]!=1 && !EnsEstDans(openlist,construireCouple(p.x,p.y+1)))
		{
			openlist=EnsAjoute(openlist,construireCouple(p.x,p.y+1));
			DessineCouple(construireCouple(p.x,p.y+1),vert);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].g_cost=p.g_cost+1.0;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].distance=path(p.x,fin.x,p.y+1,fin.x);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].f_cost=openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].g_cost + openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].distance;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].p.a=p.x;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].p.b=p.y;
		}
		else
		if(m->Case[p.x][p.y+1]!=1 && EnsEstDans(openlist,construireCouple(p.x,p.y+1)))
			{
					if(openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].g_cost<p.g_cost+1.0)
				{
				openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].g_cost=ferme->Case[EnsChercheCouple(ferme,p)].g_cost+1.;
				openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].f_cost= (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].g_cost) + (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y+1))].distance);
				}
			}
		if(m->Case[p.x-1][p.y]==1 || EnsEstDans(ferme,construireCouple(p.x-1,p.y)));
		else
		if(m->Case[p.x-1][p.y]!=1 && !EnsEstDans(openlist,construireCouple(p.x-1,p.y)))
		{
			openlist=EnsAjoute(openlist,construireCouple(p.x-1,p.y));
			DessineCouple(construireCouple(p.x-1,p.y),vert);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].g_cost=p.g_cost+1.0;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].distance=path(p.x-1,fin.x,p.y,fin.x);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].f_cost=openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].g_cost + openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].distance;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].p.a=p.x;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].p.b=p.y;
		}
		else
		if(m->Case[p.x-1][p.y]!=1 && EnsEstDans(openlist,construireCouple(p.x-1,p.y)))
			{
					if(openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].g_cost<p.g_cost+1.0)
				{
				openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].g_cost=ferme->Case[EnsChercheCouple(ferme,p)].g_cost+1.0;
				openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].f_cost= (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].g_cost) + (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x-1,p.y))].distance);
				}
			}
		if(m->Case[p.x][p.y-1]==1 || EnsEstDans(ferme,construireCouple(p.x,p.y-1)));
		else
		if(m->Case[p.x][p.y-1]!=1 && !EnsEstDans(openlist,construireCouple(p.x,p.y-1)))
		{
			openlist=EnsAjoute(openlist,construireCouple(p.x,p.y-1));
			DessineCouple(construireCouple(p.x,p.y-1),vert);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].g_cost=p.g_cost+1.0;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].distance=path(p.x-1,fin.x,p.y,fin.x);
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].f_cost=openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].g_cost + openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].distance;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].p.a=p.x;
			openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].p.b=p.y;
		}
		else
			if(m->Case[p.x][p.y-1]!=1 && EnsEstDans(openlist,construireCouple(p.x,p.y-1)))
				{
						if(openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].g_cost<p.g_cost+1.0)
					{
					openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].g_cost=ferme->Case[EnsChercheCouple(ferme,p)].g_cost+1.0;
					openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].f_cost= (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].g_cost) + (openlist->Case[EnsChercheCouple(openlist,construireCouple(p.x,p.y-1))].distance);
					}
				}
				
		EnsSuppr2(openlist,p);
		

		refresh();
		
	}
	waitgraph();
	Couple chemin=ferme->Case[EnsChercheCouple(ferme,fin)];
	DessineCouple(chemin,jaune);
	refresh();
	while(!compareCouple(chemin,construireCouple(1,1)))
	{
		DessineCouple(construireCouple(chemin.p.a,chemin.p.b),jaune);
		refresh();
		chemin=ferme->Case[EnsChercheCouple(ferme,construireCouple(chemin.p.a,chemin.p.b))];
	}
	waitgraph();
	closegraph();
}
				
/***********************************************************************
 * recherche avec une heuristique choix du voisin avec la plus faible
 * distance à vol d oiseau avec l arrivée
 * *********************************************************************/

Couple heuristique(ens e1,ens e2,matrice m)
{
	Couple tmp1={0,0,0},min={0,0,0};
    Couple p=e1->Case[e1->taille_elem-1];
    Couple fin={m->l-2,m->h-2};
    p.distance=path(p.x,fin.x,p.y,fin.y);
	min=construireCouple((p.x - e1->Case[e1->taille_elem-2].x),(p.y - e1->Case[e1->taille_elem-2].y));
	min.distance=path(p.x,fin.x,p.y,fin.y);
	if(!EnsEstDans(e2,construireCouple(p.x+1,p.y)) && m->Case[p.x+1][p.y] != vrai && path(p.x+1,fin.x,p.y,fin.y)<min.distance) // a droite
	tmp1=construireCouple(1,0);
	else
	if(!EnsEstDans(e2,construireCouple(p.x,p.y+1)) && m->Case[p.x][p.y+1] != vrai && path(p.x,fin.x,p.y+1,fin.y)<min.distance) // en bas
	tmp1=construireCouple(0,1);
	else
	if(!EnsEstDans(e2,construireCouple(p.x,p.y-1)) && m->Case[p.x][p.y-1] != vrai ) //en haut
	tmp1=construireCouple(0,-1);
	else
	if(!EnsEstDans(e2,construireCouple(p.x-1,p.y)) && m->Case[p.x-1][p.y] != vrai )//a gauche
	tmp1=construireCouple(-1,0);
	else
	tmp1=construireCouple(0-min.x,0-min.y);
return tmp1;
   }


/***********************************************************************
 * recherche du plus court chemin Dijkstra
 * *********************************************************************/  
void dijkstra(ens e1,matrice m)
{	  
	  long rouge=0;
	  rouge=newcolor(1,0,0);
	
	  while(!EnsEstVide(e1))
	  {
		    Couple p=e1->Case[0];
			 DessineCouple(construireCouple(p.x,p.y),rouge);
			 e1=EnsSupprPremier(e1);

		  
			if(m->Case[p.x+1][p.y]== 2)
			{
			  m->Case[p.x+1][p.y]=m->Case[p.x][p.y]+1;
			  EnsAjoute(e1,construireCouple(p.x+1,p.y));
			 }
		    if(m->Case[p.x][p.y+1]== 2)
			{
			  m->Case[p.x][p.y+1]=m->Case[p.x][p.y]+1;
			  EnsAjoute(e1,construireCouple(p.x,p.y+1));
			}
			if(m->Case[p.x-1][p.y]== 2)
			{
			  m->Case[p.x-1][p.y]=m->Case[p.x][p.y]+1;
			  EnsAjoute(e1,construireCouple(p.x-1,p.y));
			}	
			if(m->Case[p.x][p.y-1]== 2 )
			{
			  m->Case[p.x][p.y-1]=m->Case[p.x][p.y]+1;
			  EnsAjoute(e1,construireCouple(p.x,p.y-1));
			}
		
			refresh();

		  
	  }
 }
	  
  
/***********************************************************************
 *Boucle principale du programme de recherche de chemin
 * fonction:
 * mat_Alea_Heuri
 * mat_Dij
 * mat_Astar
 * *********************************************************************/	

matrice mat_Alea_Heuri(matrice m)
{
   
     //Création des variables de couleurs, les couples, et les pointeurs
    ens e2=NULL,e1=NULL;
    Couple p,PosA={1,1},PosB={m->l-2,m->h-2};
    Couple deplacement,p1,p2;
    long blue=0,jaune=0,gris=0;
    e2=EnsAlloc(); //Allocation de l'ensemble des cases déjà visitées
    
    e1=EnsAlloc();	 //Allocation de l'ensemble qui représente le parcours de l'aglorithme,
					// (donc la liste des coordonnées des cases par lequels l'algo est passé depuis le début
    
    EnsAjoute(e2,PosA); //on ajoute la position initial dans l'ensemble des cases déjà vu,
    EnsAjoute(e1,PosA); // ainsi que dans le parcours

    if(affiche==1)
    {
		//Création des couleurs, initialisation de l'affichage graphique,
		// et dessine le labyrinthe en entier en Blue
		// ainsi que la position actuel en rouge
		
        initgraph(m->l*PIXEL,m->h*PIXEL);
        blue=newcolor(0,0,1); //
        jaune=newcolor(1,1,0);//chemin
        gris=newcolor(0.5,0.5,0.5);
        cleargraph();
        DessineLab(m,blue);
        DessineCouple(PosA,jaune);
        refresh();
    }

    //tant qu'on a pas atteind la fin du labyrinthe
    while(!(compareCouple(e1->Case[e1->taille_elem-1],PosB)))
    {
		//la position actuelle est celle de la derniere case du parcours
        p1=e1->Case[e1->taille_elem-1];
        //si la position actelle est celle du début, on va d'abord à
        // droite, puis en bas si c'est possible(donc on ajoute la case
        //où l'on va dans le parcours, et dans l'ensemble dejavu
        if(compareCouple(p1,PosA))
        {
            if(!(EnsEstDans(e2,construireCouple(1,2))))
            {
                p=construireCouple(1,2);
                EnsAjoute(e2,p);
                EnsAjoute(e1,p);

                if(affiche==1) 
				DessineCouple(p,jaune);
            }
            else
            {
                p=construireCouple(2,1);
                EnsAjoute(e2,p);
                EnsAjoute(e1,p);
                
                if(affiche==1) 
                DessineCouple(p,jaune);
            }
        }
        else
        {
			/*choix de deplacement
			  la positon future sera la position actuelle + la direction,
			  le "deplacement", dans laquelle on va aller */
				//~ if(strcmp(move,"a")==0)
				if(move[0]=='a')
                deplacement=chemin_alea(e1,e2,m);
                else
				//~ if(strcmp(move,"h")==0)
				if(move[0]=='h')
				deplacement=heuristique(e1,e2,m);
				
                p2=SommeCouple(deplacement,p1);
                 /*on ajoute la position actuelle à l'ensemble des cases
				 deja vu (car si on est dessus, on l'a déja vu)*/
				EnsAjoute(e2,p1);
				/*Si la position future correspond à l'avant dernière case du parcours
				 (donc la case "dernière nous"), alors on enlève le dernier élément
				  de parcours(l'algorithme " on recule") et on dessine
				  en gris la d'où on vient*/
				if(compareCouple(p2,e1->Case[e1->taille_elem-2])==1)
				{
                  EnsSupprDernier(e1);                 
				  if(affiche==1)
                   DessineCouple(p1,gris);
                  // usleep(500);
				}
              
               /*sinon on avance(ajoute au parcours la position future)
                 vers la position future, qu'on dessine en jaune
                 si l'affichage est activé*/
              
            else
				{
				EnsAjoute(e1,p2);
				if(affiche==1) 
				DessineCouple(p2,jaune);
				//usleep(500);
				}
        }
			if(affiche==1) 
			refresh();
    }

			if(affiche==1)
			{
			waitgraph();
			closegraph();
			}
			
      //désallocation des ensembles
    EnsFree(e1);
    EnsFree(e2);

    return m;
}

/***********************************************************************
 * fontion mat_Dij, conserne le parcourt le plus court Dijkstra

 * *********************************************************************/
 
matrice mat_Dij(matrice m)
{
	
	
	ens e1=NULL;
    Couple PosA={1,1},PosB={m->l-2,m->h-2};
    long blue=0,rouge=0,vert=0;
 
    e1=EnsAlloc();

    EnsAjoute(e1,PosA);

    if(affiche==1)
    {
        initgraph(m->l*PIXEL,m->h*PIXEL);
        blue=newcolor(0,0,1); //
        rouge=newcolor(1,0,0);//chemin
       
        vert=newcolor(0,1,0);
        cleargraph();
        DessineLab(m,blue);
        DessineCouple(PosA,rouge);
        refresh();
    }
    int i,j;
	for (i =0; i<m->l;i++)
	{
		for(j=0;j<m->h;j++)
		{
			if(m->Case[i][j] != vrai)
			{
				m->Case[i][j] = 2;
			}
		}
	}
                m->Case[1][1]=3;
                dijkstra(e1,m);
        
        if(affiche==1) 
          refresh();
		
		
		
		if(affiche==1)
		waitgraph();
			
		while(m->Case[PosB.x][PosB.y] != m->Case[1][1])
		{
			if (affiche==1)
			{
				refresh();
				DessineCouple(PosB,vert);
			}
		
			if(m->Case[PosB.x+1][PosB.y] == m->Case[PosB.x][PosB.y]-1)
			{
			PosB.x=PosB.x+1;
			DessineCouple(PosB,vert);
			}
			else
			if(m->Case[PosB.x-1][PosB.y] == m->Case[PosB.x][PosB.y]-1)
			{
			PosB.x=PosB.x-1;
			DessineCouple(PosB,vert);
			}
			else
			if(m->Case[PosB.x][PosB.y-1] == m->Case[PosB.x][PosB.y]-1)
			{
			PosB.y=PosB.y-1;
			DessineCouple(PosB,vert);
			}
			else
			if(m->Case[PosB.x][PosB.y+1] == m->Case[PosB.x][PosB.y]-1)
			{
			PosB.y=PosB.y+1;
			DessineCouple(PosB,vert);
			}
			
		}
		
			
		if(affiche==1)
      {
		refresh();
        waitgraph();
        closegraph();
      }
      EnsFree(e1);
      
      
	
	return m;
}

/***********************************************************************
 * fontion mat_Astar, conserne le parcourt le plus court A*
 * *********************************************************************/

matrice mat_Astar(matrice m)
{
	ens openlist=NULL,closelist=NULL;
	long blue=0;
	openlist=EnsAlloc();
	closelist=EnsAlloc();
			 if(affiche==1)
    {
        initgraph(m->l*PIXEL,m->h*PIXEL);
        blue=newcolor(0,0,1); 
        cleargraph();
        DessineLab(m,blue);
        refresh();
    }
	Astar(closelist,openlist,m);

	EnsFree(closelist);
	EnsFree(openlist);
    
	return m;
}
		
			


/***********************************************************************
 fonction Couple chemin(ens e1,ens e2,matrice m) 
*choisir quel chemin prendre : regarde la case où l'on se trouve,
* et applique une préférence quant à la direction à prendre
*(si l'on ne vient pas de cette direction,et qu'il n'y a pas de mur):
* droite,puis bas,puis haut,puis gauche
************************************************************************/

Couple chemin_alea(ens e1,ens e2,matrice m)
{
    Couple tmp1={0,0},tmp2={0,0};
    Couple p=e1->Case[e1->taille_elem-1];
	ens alea=NULL;
	alea=EnsAlloc();
	
	/* tmp2 contient le vecteur directeur de l'avancé de l'algorithme,
	  si l'on vient de gauche tmp2= {1,0} */
	tmp2=construireCouple((p.x - e1->Case[e1->taille_elem-2].x),(p.y - e1->Case[e1->taille_elem-2].y));
	/* ici on teste les préférences : si on ne vient pas de la
	  droite, qu'on est jamais aler à droite, et que la droite n'est pas
	  un mur, alors la direction sera la droite, et sinon on fait la même
	  chose pour le bas,puis le haut, puis à gauche */ 
	
	if((m->Case[p.x+1][p.y] != vrai)&& !(EnsEstDans(e2,construireCouple(p.x+1,p.y))))
		EnsAjoute(alea,construireCouple(1,0));
	if((m->Case[p.x-1][p.y] != vrai)&& !(EnsEstDans(e2,construireCouple(p.x-1,p.y))))
		EnsAjoute(alea,construireCouple(-1,0));
	if((m->Case[p.x][p.y-1] != vrai) && !(EnsEstDans(e2,construireCouple(p.x,p.y-1))))
		EnsAjoute(alea,construireCouple(0,-1)); 
	if((m->Case[p.x][p.y+1] != vrai) && !(EnsEstDans(e2,construireCouple(p.x,p.y+1)))) 
		EnsAjoute(alea,construireCouple(0,1));
	if(EnsEstVide(alea))
	tmp1=construireCouple(0-tmp2.x,0-tmp2.y);
	else
	// on initialise les direction aleatoirement
	tmp1=(alea->Case[rand() % alea->taille_elem]);
	EnsFree(alea);
	 //on renvoie le nouveau vecteur directeur de l'algorithme
    return tmp1;
}

/***********************************************************************
 * Dessine tout les couples contenu dans l'ensemble donné en parametre,
 * avec une couleur passé en parametre
 * *********************************************************************/

void DessineEns(ens e,long couleur)
{
	int i=0;
	for(i=0;i<e->taille_elem;i++) DessineCouple(e->Case[i],couleur);
}


/***********************************************************************
 *  Dessine un couple avec la couleur passé en parametre
 * *********************************************************************/
void DessineCouple(Couple p,long couleur)
{       int i;
	setcolor(couleur);
	for(i=0;i<(PIXEL);i++) 
           line(p.x*PIXEL,p.y*PIXEL+i,p.x*PIXEL + PIXEL -1,p.y*PIXEL+i);
}

/***********************************************************************
 *Parcours et dessine les murs d'un labyrinthe 
 * avec la couleur passé en parametrre
 * *********************************************************************/
void DessineLab(matrice m,long couleur)
{
    int i,j;
    for(j=0;j<m->h;j++)
    {
        for(i=0;i<m->l;i++)
          if(m->Case[i][j] == vrai) 
            DessineCouple(construireCouple(i,j),couleur);
    }
}

/***********************************************************************
 * Efface tout les couples de l'ensemble de l'affichage graphique
 * c-à-d les redessiner en blanc
 * *********************************************************************/
void SupprCouple(Couple p)
{
	DessineCouple(p,newcolor(1,1,1));
}

/***********************************************************************
 * Efface un couple de l'affichage graphique
 * c-à-d le redessine en blanc
 * 
 * *********************************************************************/
void SupprEns(ens e)
{
	DessineEns(e,newcolor(1,1,1));
}
