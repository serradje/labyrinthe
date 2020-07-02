#include <stdio.h>
#include <stdlib.h>

#include "labyrinthe.h"
#include "sort.c"

matrice GenLab (matrice m)
{   
   
    ens e1=NULL,e2=NULL,e3=NULL;
    Couple p;
    e3=EnsAlloc();
    long blue=0,rouge=0;

       if(affichage == 1)
         {
               initgraph(PIXEL*m->l,PIXEL*m->h);
		blue=newcolor(0,0,1);
		rouge=newcolor(1,0,0);
                cleargraph();
          }
    
	     e3=Creer_Bord(m,e3);
	     e1=Pose_Graine(m);
         e2=Construire_Mur(e1,m);

    if(affichage == 1)
    {
		DessineEns(e3,blue);
		DessineEns(e1,blue);
		if(affiche_case==1) DessineEns(e2,rouge);
		refresh();
	}

    while(e2->taille_elem > 0)
    {
       
        p=EnsTirage(e2);
        m->Case[p.x][p.y]=1;

		e2=Suppr_Mur(p,e2,m);
		e2=Ajout_Mur(p,e2,m,rouge);


        if(affichage == 1)
          {
            DessineCouple(p,blue);
            refresh();
           }

    }

   
        EnsFree(e1);
        EnsFree(e2);
	EnsFree(e3);
	if(affichage == 1)
	{
		waitgraph();
		closegraph();
	}
	return m;
}

Couple Check_Graine(matrice m,Couple p)
{
    Couple tmp={0,0};
 
 /* Verifie d'abord que nous sommes bien dans la matrice ensuite pour Case gauche , droite , haut , bas
  * cherche la graine responsable de la construction de la case constructible et ensuite une fois trouvé je retourne les coordonnées de cette graine */ 
   
    if((m->h-p.y>0)&&(m->l-p.x>0)) 
    {
            if((m->Case[p.x-1][p.y])==vrai) 
               {
                tmp.x=p.x-1;  // en haut 
                tmp.y=p.y;
               }
               
             if((m->Case[p.x+1][p.y])==vrai)
               {
                tmp.x=p.x+1; // en bas 
                tmp.y=p.y;
               }
               
            if((m->Case[p.x][p.y+1])==vrai)
               {
                tmp.x=p.x;   //  a droite 
                tmp.y=p.y+1; 
                }
                
            if((m->Case[p.x][p.y-1])==vrai)
              {
                tmp.x=p.x;   // a gauche
                tmp.y=p.y-1;
               }
	}
	return tmp;
}

/*******************FONCTION QUI MET DES BORDS SUR LES CONTOURS DE LA MATRICE*************************/
ens Creer_Bord(matrice m,ens e)
{
    int i;
    for(i=0;i<m->l;i++)
      {
        m->Case[i][0]=vrai; // sur toutes les lignes de la premeiere colonne on y met des murs 
        e=EnsAjoute(e,construireCouple(i,0)); // stocke dans e
        m->Case[i][m->h-1]=vrai; //sur toutes les lignes de la gerniere colonne on y met des murs  
        e=EnsAjoute(e,construireCouple(i,m->h-1)); // stocke dans e 
      }
    for(i=0;i<m->h;i++)
       {
        m->Case[0][i]=vrai; //sur toutes les colonnes de la premiere ligne on y met des murs 
        e=EnsAjoute(e,construireCouple(0,i)); //stocke dans e
        m->Case[m->l-1][i]=vrai; // sur toutes les colonnes de la derniere ligne  on y met des murs 
        e=EnsAjoute(e,construireCouple(m->l-1,i)); // stocke dans e 
       }
    
    return e;
}

int EstConstructible(matrice m,Couple p)
{
    int k=0;
    Couple tmp={0,0};
 if(((m->l>p.x)&&(p.x>=0))&&((m->h>p.y)&&(p.y>=0)))
    {
        if(m->Case[p.x][p.y] != vrai)
        {
            if((m->Case[p.x-1][p.y])==vrai)
            {
                k++;
                tmp.x=p.x-1;
                tmp.y=p.y;
            }
            if((m->Case[p.x][p.y-1])==1)
            {
                k++;
                tmp.x=p.x;
                tmp.y=p.y-1;
            }
            if((m->Case[p.x+1][p.y])==1)
            {
                k++;
                tmp.x=p.x+1;
                tmp.y=p.y;
            }
            if((m->Case[p.x][p.y+1])==vrai)
            {
                k++;
                tmp.x=p.x;
                tmp.y=p.y+1;
            }
            
            if(k == 1)
            {
                Couple tmp1={p.x-tmp.x,p.y-tmp.y};
                Couple tmp2={tmp1.y,tmp1.x};
                if(m->Case[p.x+tmp1.x+tmp2.x][p.y+tmp1.y+tmp2.y]==1) 
                k++;
                if(m->Case[p.x+tmp1.x-tmp2.x][p.y+tmp1.y-tmp2.y]==1) 
                k++;
            }
        }
}
    return ( k== 1);

}



/****** INITIALISATION DE L'ENSEMBLE DES GRAINES A CONTRUIRE PROPORTIONNELLEMENT SUIVANT LA TAILLE DE LA MATRICE****************/
/****** PLACE LES GRAINES SUIVANT LES MURS EXTERNES EN HAUT EN BAS A GAUCHE A GROITE DU LABYRINTHE*****************/

ens Pose_Graine(matrice m)
{
	
	
	    /*Calcul pour avoir un nombre de graine proportionnel à la taille de la matrice
         c'est a dire on fait une supposition d'une variable norme qui vaudra une graine 
         ensuite on fera la regle de trois pour savoir ce que vaudra les varibales suivant ligne et suivant colonne
         */
	int suivant_h=(m->h -2)/GLOBAL+1;
	int suivant_l=(m->l -2)/GLOBAL+1;
	int i,abs,ord;
	Couple p;
	int emplacement=0;
	ens e=NULL;
	e=EnsAlloc();
	
	
	/* semer des graines sur les murs externes de droit et gauche
        On va tirer aleatoirement des points sur les murs externes de droite,gauche,haut,bas et enfin au centre 
        ensuite on verifie si les points tires representent 1 (murs) enfin on y seme une graine ainsi de suite  */
	  for(i=0;i <suivant_l ;i++)
	    {
		emplacement=(rand() % (m->l-2)) + 1;
		
		if(EstConstructible(m,construireCouple(emplacement,1)) == 1) 
		  {
			EnsAjoute(e,construireCouple(emplacement,1));
			m->Case[emplacement][1]=1;
		   }
        else 
        { i--;}  
        
		emplacement=(rand() % (m->l-2)) + 1;
		
		if(EstConstructible(m,construireCouple(emplacement,m->h-2))== 1) 
		  {
			EnsAjoute(e,construireCouple(emplacement,m->h-2));
			m->Case[emplacement][m->h-2]=vrai;
		  }
		else 
		{ i--; }
	  }
   
	for(i=0;i <suivant_h ;i++)
	  {
		emplacement=(rand() % (m->h-2)) + 1;
		if((EstConstructible(m,construireCouple(1,emplacement))) == 0) 
		   i--;
		else
		{
			EnsAjoute(e,construireCouple(1,emplacement));
			m->Case[1][emplacement]=1;
		}

		emplacement=(rand() % (m->l-2)) + 1;
		if((EstConstructible(m,construireCouple(m->l-2,emplacement))) == 0) 
		   i--;
		else
		{
			EnsAjoute(e,construireCouple(m->l-2,emplacement));
			m->Case[m->l-2][emplacement]=1;
		}
	}
        // au centre 
		i = 0;
	while(i<((2*(suivant_h + suivant_l))/4) )
	{
	    
	    abs=(rand() % (m->l-6)) + 3;
	    ord=(rand() % (m->h-6)) + 3;
        p=construireCouple(abs,ord);
	    if(m->Case[p.x][p.y] == 1) 
	    i--;
	    else
	    {
	        EnsAjoute(e,p);
	        m->Case[abs][ord]=1;
	    }
    i++;
	}

	return e;
}


/*************FONCTION QUI INITIALISE UN ENSEMBLE DE MUR CONSTRUCTIBLE A PARTIR D'UN ENSEMBLE DE GRAINE**********************************/

ens Construire_Mur(ens e,matrice m)
{
	ens e1=NULL;
	Couple p,tmp;
	e1=EnsAlloc();
	if(e1!=NULL)
	{
	int i=0;
	while (i< e->taille_elem)
		{
			p=e->Case[i];
			tmp=construireCouple(p.x-1,p.y);
			
			if(EstConstructible(m,tmp) == 1) 
			EnsAjoute(e1,tmp);
			
			tmp=construireCouple(p.x,p.y+1);
			if(EstConstructible(m,tmp) == 1)
			  EnsAjoute(e1,tmp);
			  
			tmp=construireCouple(p.x,p.y-1);
			if(EstConstructible(m,tmp) == 1) 
			   EnsAjoute(e1,tmp); 
			   
			 tmp=construireCouple(p.x+1,p.y);
			 if(EstConstructible(m,tmp) == 1)
			   EnsAjoute(e1,tmp);
			i++;
		}
	}
	return e1;
}



ens Suppr_Mur(Couple p,ens e,matrice m)
{
	Couple p1,p2;
	p2=Check_Graine(m,p);
	p1=construireCouple(p.x-p2.x,p.y-p2.y);
    
	EnsSuppr(e,construireCouple(p.x+p1.x+p1.y,p.y+p1.y+p1.x));
	EnsSuppr(e,construireCouple(p.x+p1.x-p1.y,p.y+p1.y-p1.x));
	EnsSuppr(e,construireCouple(p.x+p1.x,p.y+p1.y));
	EnsSuppr(e,construireCouple(p.x+p1.y,p.y+p1.x));
	EnsSuppr(e,construireCouple(p.x-p1.y,p.y-p1.x));
	if(affiche_case==1)
	{
	   
		SupprCouple(construireCouple(p.x+p1.x+p1.y,p.y+p1.y+p1.x));
		SupprCouple(construireCouple(p.x+p1.x-p1.y,p.y+p1.y-p1.x));
		SupprCouple(construireCouple(p.x+p1.x,p.y+p1.y));
		SupprCouple(construireCouple(p.x+p1.y,p.y+p1.x));
		SupprCouple(construireCouple(p.x-p1.y,p.y-p1.x));
	}
	return e;
}


ens Ajout_Mur(Couple p,ens e,matrice m,long couleur)
{
	Couple p1;
    
	p1=construireCouple(p.x,p.y+1);
	if(EstConstructible(m,p1) == 1)
	{
		e=EnsAjoute(e,p1);
		if(affiche_case ==1) DessineCouple(p1,couleur);
	}

	p1=construireCouple(p.x,p.y-1);
	if(EstConstructible(m,p1) == 1)
	{
		e=EnsAjoute(e,p1);
		if(affiche_case==1) DessineCouple(p1,couleur);
	}

	p1=construireCouple(p.x+1,p.y);
	if(EstConstructible(m,p1) == 1)
	{
		e=EnsAjoute(e,p1);
		if(affiche_case ==1) DessineCouple(p1,couleur);
	}
	p1=construireCouple(p.x-1,p.y);
	if(EstConstructible(m,p1) == 1)
	{
		e=EnsAjoute(e,p1);
		if(affiche_case ==1) DessineCouple(p1,couleur);
	}

	return e;
}

/********************************* FONCTION QUI SONT LA POUR LE BON AFFICHAGE DU LABYRINTHE ******************************/

void DessineCouple(Couple p,long couleur)
{
	setcolor(couleur);
	int k;
	for(k=0;k<(PIXEL);++k) 
          {
           line(p.x*PIXEL,p.y*PIXEL+k,p.x*PIXEL + PIXEL -1,p.y*PIXEL+k);  }
}
void DessineEns(ens e,long couleur)
{
	int i=0;
	for(i=0;i<e->taille_elem;i++) 
         DessineCouple(e->Case[i],couleur);
}



void SupprCouple(Couple p)
{
	DessineCouple(p,newcolor(1,1,1));
}

void SupprEns(ens e)
{
	DessineEns(e,newcolor(1,1,1));
}

